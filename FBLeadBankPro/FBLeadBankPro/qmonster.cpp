#include "qmonster.h"
#include <QDebug>

QMonster::QMonster()
{
#ifdef Q_OS_WIN
    this->m_exePath = QDir::toNativeSeparators(QCoreApplication::applicationDirPath()+"/"+"pjs.exe");
#else
    this->m_exePath = QDir::toNativeSeparators(QCoreApplication::applicationDirPath()+"/"+"pjs");
#endif
    this->m_threadState = 0;//0-stop 1-run 2-pause 3-finished
}

void QMonster::setExe(const QString &path, const QStringList &args)
{
    QMutexLocker locker(&this->m_attribLock);
    this->m_exePath = path;
    this->m_exeArgs = args;
}

void QMonster::setExePath(const QString &path)
{
    QMutexLocker locker(&this->m_attribLock);
    this->m_exePath = path;
}

void QMonster::setExeArgs(const QStringList &args)
{
    QMutexLocker locker(&this->m_attribLock);
    this->m_exeArgs = args;
}

void QMonster::setPath(const QString &path)
{
    this->setExePath(path);
}

void QMonster::setArgs(const QStringList &args)
{
    this->setExeArgs(args);
}

QString QMonster::processResult()
{
    QMutexLocker locker(&this->m_attribLock);
    return this->m_result;
}

QString QMonster::processError()
{
    QMutexLocker locker(&this->m_attribLock);
    return this->m_error;
}

bool QMonster::isRunning()
{
    QMutexLocker locker(&this->m_attribLock);
    return this->m_threadState == 1;
}

int QMonster::threadState()
{
    QMutexLocker locker(&this->m_attribLock);
    return this->m_threadState;
}

void QMonster::run()
{
    int state;
    //qDebug() << "startingThread";
    {
        QMutexLocker locker(&this->m_attribLock);
        if(!QFile::exists(this->m_exePath)){
            emit processNotFoundError();
            return;
        }
        state = this->m_threadState;
    }

    QProcess *process = new QProcess();
    QObject::connect(process,static_cast<void (QProcess::*)(int,QProcess::ExitStatus)>
                     (&QProcess::finished),[this](int exitCode, QProcess::ExitStatus exitStatus){
        //qDebug() << exitCode;
        //qDebug() << exitStatus;
        Q_UNUSED(exitCode);
        QMutexLocker locker(&this->m_attribLock);
        if(QProcess::NormalExit == exitStatus){
            this->m_threadState = 3;
        }
    });

    {
        QMutexLocker locker(&this->m_attribLock);
        process->setProgram(this->m_exePath);
        process->setArguments(this->m_exeArgs);
    }
    process->start();

    while(state == 1)
    {
        QCoreApplication::processEvents();
        {
            QMutexLocker locker(&this->m_attribLock);
            state = this->m_threadState;
        }
    }
    process->kill();
    process->waitForFinished();
    {
        QMutexLocker locker(&this->m_attribLock);
        this->m_result = QString(process->readAllStandardOutput().constData());
        this->m_error = QString(process->readAllStandardError().constData());
    }
    delete process;

    if(state==0){
        emit threadStopped();
    }
    else if(state==2){
        emit threadPaused();
    }
    else{
        emit threadFinished();
        {
            QMutexLocker locker(&this->m_attribLock);
            this->m_threadState = 0;
        }
    }
}

void QMonster::start()
{
    int state;
    {
        QMutexLocker locker(&this->m_attribLock);
        state = this->m_threadState;
    }

    if(state==1){
        return;
    }
    else{
        {
            QMutexLocker locker(&this->m_attribLock);
            this->m_threadState = 1;//run the thread
        }
        QThread::start();
        emit threadStarted();
    }
}

void QMonster::stop()
{
    int state;
    {
        QMutexLocker locker(&this->m_attribLock);
        state = this->m_threadState;
    }
    if(state==1 || state==2){
        QMutexLocker locker(&this->m_attribLock);
        this->m_threadState = 0;//stop the thread
    }
}

void QMonster::pause()
{
    int state;
    {
        QMutexLocker locker(&this->m_attribLock);
        state = this->m_threadState;
    }
    if(state==1){
        QMutexLocker locker(&this->m_attribLock);
        this->m_threadState = 2;//pause the thread
    }
}

void QMonster::resume()
{
    int state;
    {
        QMutexLocker locker(&this->m_attribLock);
        state = this->m_threadState;
    }

    if(state==1){
        return;
    }
    else{
        {
            QMutexLocker locker(&this->m_attribLock);
            this->m_threadState = 1;//run the thread
        }
        QThread::start();
        emit threadResumed();
    }
}
