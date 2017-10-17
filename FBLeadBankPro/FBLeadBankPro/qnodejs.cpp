#include "qnodejs.h"
#include <QDir>
#include <QDebug>
#include <QCoreApplication>
#include <QApplication>
#include <QDebug>

QNodeJs::QNodeJs() : QThread()
{
    this->m_isRunning = false;
#ifdef Q_OS_WIN
    this->m_exeName = QLatin1String("njs.exe");
#else
    this->m_exeName = QLatin1String("njs");
#endif

    this->m_exePath = QDir::toNativeSeparators(QCoreApplication::applicationDirPath()+QLatin1String("/")+this->m_exeName);
    //qDebug() << this->m_exePath;

}

QNodeJs::~QNodeJs()
{
    //qDebug() << "Destorying";
}

void QNodeJs::run()
{
    //qDebug() << "Thread started";
    this->m_nodeJsProcess = new QProcess();
    this->connect(this->m_nodeJsProcess,SIGNAL(started()),this,SIGNAL(nodeJsStarted()));
    this->m_nodeJsProcess->start(this->m_exePath, this->m_args);
    bool b;
    {
        QMutexLocker aLocker(&this->aMutex);
        b = this->m_isRunning;
    }

    while(b)
    {
        {
            QMutexLocker aLocker(&this->aMutex);
            b = this->m_nodeJsProcess->state() == QProcess::NotRunning;
            this->m_isRunning = b;
        }
        QApplication::processEvents();
        this->msleep(500);
    }

    {
        QMutexLocker aLocker(&this->aMutex);
        this->m_finalString = QString(this->m_nodeJsProcess->readAllStandardOutput());
    }

    this->m_nodeJsProcess->waitForFinished();
    delete this->m_nodeJsProcess;

    emit nodeJsFinished();
    emit status("finished");
}

void QNodeJs::processFinished()
{
    //    Q_UNUSED(exitCode);
    //    Q_UNUSED(exitStatus);

    {
        QMutexLocker aLocker(&this->aMutex);
        this->m_isRunning = false;
    }
}

void QNodeJs::start(const QString &path, const QStringList &args)
{
    {
        QMutexLocker aLocker(&this->aMutex);
        this->m_args.clear();
        this->m_args<<path<<args;
        this->m_isRunning = true;
    }
    emit status("started");
    QThread::start();
}

void QNodeJs::stop()
{

    QMutexLocker aLocker(&this->aMutex);
    this->m_isRunning = false;
}

bool QNodeJs::isRunning()
{
    QMutexLocker aLocker(&this->aMutex);
    return this->m_isRunning;
}

QString QNodeJs::finalString()
{
    QMutexLocker aLocker(&this->aMutex);
    return this->m_finalString;
}
