#include "pjsthreadmanager.h"

#include <QDebug>
#include <QDir>
#include <QApplication>

PJSThreadManager::PJSThreadManager():QThread()
{
    this->m_stop = false;
    this->m_pause = false;
    this->m_maxThread = 10;
}

PJSThreadManager::~PJSThreadManager()
{

    QMutexLocker locker(&this->m_pjsMutex);
    while (!this->m_pjsObjectList.isEmpty()) {
        PJSObject *obj = this->m_pjsObjectList.takeFirst();
        obj->pause();
        obj->deleteLater();
    }
}

void PJSThreadManager::setMaxThread(int num)
{
    QMutexLocker locker(&this->m_aMutex);
    this->m_maxThread = num;
}

void PJSThreadManager::setProfile(const QString &profile)
{
    QMutexLocker locker(&this->m_aMutex);
    this->m_profile = profile;
}

void PJSThreadManager::setImageDir(const QString &path)
{
    QMutexLocker locker(&this->m_aMutex);
    this->m_imageDir = path;
}

void PJSThreadManager::sendMessageEnabled(bool b)
{
    QMutexLocker locker(&this->m_aMutex);
    this->m_sendMessage = b;
}

void PJSThreadManager::sendEmailEnabled(bool b)
{
    QMutexLocker locker(&this->m_aMutex);
    this->m_sendEmail = b;
}

void PJSThreadManager::generateMockPageEnabled(bool b)
{
    QMutexLocker locker(&this->m_aMutex);
    this->m_generateMockPage = b;
}

void PJSThreadManager::addFacebookId(int row, QString fbid, QString url)
{
    QMutexLocker locker(&this->m_aMutex);
    if(!this->m_indexList.contains(row)){
        this->m_indexList.append(row);
        this->m_facebookIdList.append(fbid);
        this->m_facebookUrlList.append(url);
    }
}

void PJSThreadManager::removeFacebookId(QString fbid)
{
    QMutexLocker locker(&this->m_aMutex);
    if(this->m_facebookIdList.contains(fbid)){
        int index = this->m_facebookIdList.indexOf(fbid);
        this->m_facebookIdList.removeAt(index);
        this->m_indexList.removeAt(index);
        this->m_facebookUrlList.removeAt(index);
    }
}

void PJSThreadManager::removeRow(int row)
{
    QMutexLocker locker(&this->m_aMutex);
    if(this->m_indexList.contains(row)){
        int index = this->m_indexList.indexOf(row);
        this->m_facebookIdList.removeAt(index);
        this->m_indexList.removeAt(index);
        this->m_facebookUrlList.removeAt(index);
    }
}

void PJSThreadManager::clearAll()
{
    QMutexLocker locker(&this->m_aMutex);
    this->m_indexList.clear();
    this->m_facebookIdList.clear();
    this->m_facebookUrlList.clear();
    this->m_pIndexList.clear();
    this->m_pFacebookList.clear();
    this->m_pFacebookUrlList.clear();
}

int PJSThreadManager::takeOne()
{
    QMutexLocker locker(&this->m_aMutex);
    if(this->m_indexList.size()==0) return -1;

    this->m_facebookIdList.takeFirst();
    this->m_facebookUrlList.takeFirst();
    return this->m_indexList.takeFirst();
}

void PJSThreadManager::clearRow(int row)
{
     QMutexLocker locker(&this->m_aMutex);
     if(this->m_indexList.contains(row)){
         int index = this->m_indexList.indexOf(row);
         this->m_facebookIdList.removeAt(index);
         this->m_indexList.removeAt(index);
         this->m_facebookUrlList.removeAt(index);
     }

     if(this->m_pIndexList.contains(row)){
         int index = this->m_pIndexList.indexOf(row);
         this->m_pFacebookList.removeAt(index);
         this->m_pIndexList.removeAt(index);
         this->m_pFacebookUrlList.removeAt(index);
     }
}

void PJSThreadManager::addP(int row, QString fbid,QString url)
{
    QMutexLocker locker(&this->m_aMutex);
    if(!this->m_pIndexList.contains(row)){
        this->m_pIndexList.append(row);
        this->m_pFacebookList.append(fbid);
        this->m_pFacebookUrlList.append(url);
    }
}

void PJSThreadManager::removeP(int row)
{
    QMutexLocker locker(&this->m_aMutex);
    if(this->m_pIndexList.contains(row)){
        int index = this->m_pIndexList.indexOf(row);
        this->m_pFacebookList.removeAt(index);
        this->m_pIndexList.removeAt(index);
        this->m_pFacebookUrlList.removeAt(index);
    }
}

void PJSThreadManager::removeP(QString fbid)
{
    QMutexLocker locker(&this->m_aMutex);
    if(this->m_pFacebookList.contains(fbid)){
        int index = this->m_pFacebookList.indexOf(fbid);
        this->m_pFacebookList.removeAt(index);
        this->m_pIndexList.removeAt(index);
        this->m_pFacebookUrlList.removeAt(index);
    }
}

void PJSThreadManager::addUnprocessedData()
{
    QMutexLocker locker(&this->m_aMutex);
    while(!this->m_pFacebookList.empty()){
        int row = this->m_pIndexList.takeFirst();
        QString fbid = this->m_pFacebookList.takeFirst();
        QString url = this->m_pFacebookUrlList.takeFirst();

        this->m_indexList.prepend(row);
        this->m_facebookIdList.prepend(fbid);
        this->m_facebookUrlList.prepend(fbid);
    }
}

void PJSThreadManager::stop()
{
    QMutexLocker locker(&this->m_aMutex);
    this->m_stop = true;
    this->m_pause = false;
    qDebug() << "Stop";
    emit threadStopped();
}

void PJSThreadManager::start()
{
    {
        QMutexLocker locker(&this->m_aMutex);
        this->m_stop = false;
        this->m_pause = false;
    }
    qDebug() << "Start";

    QThread::start();
}

void PJSThreadManager::pause()
{
    {
        QMutexLocker locker(&this->m_aMutex);
        this->m_stop = true;
        this->m_pause = true;
    }

    emit threadPaused();
}

void PJSThreadManager::pjsMessage(int row, const QString &message)
{
    if(message.toLower() == QString("Finished").toLower())
    {
        {
            QMutexLocker locker(&this->m_pjsMutex);
            PJSObject *obj = dynamic_cast<PJSObject*>(this->sender());
            int i = this->m_pjsObjectList.indexOf(obj);
            if(i!=-1){
                this->m_pjsObjectList.removeAt(i);
            }
            obj->deleteLater();
        }

        {
            QMutexLocker locker(&this->m_aMutex);
            if(this->m_generateMockPage){
                if(this->m_sendEmail) emit sendEmail(row);
                if(this->m_sendMessage) emit sendFacebookMessage(row);
            }
        }
        this->removeP(row);
    }

    emit updateMessage(row,message);
}

void PJSThreadManager::run()
{
    bool b = false;
    QString profile;
    QString imageDir;
    {
        QMutexLocker locker(&this->m_aMutex);
        b = this->m_stop;
        profile = this->m_profile;
        imageDir = this->m_imageDir;
    }

    if(profile.isEmpty()) {
        qDebug() << "Profile can not be empty";
        emit threadStopped();
        emit error("Profile can not be empty");
        return;
    }
    if(imageDir.isEmpty()) {
        qDebug() << "Image dir can not be empty";
        emit threadStopped();
        error("target dir can not be empty");
        return;
    }

    this->addUnprocessedData();

    while(!b){
        //qDebug() << "running";
        int maxThread;
        int currentThreadCount;
        bool isMockPageEnabled;
        bool isEmailEnabled;
        bool isFacebookEnabled;
        bool hasAnyIndex;
        bool isPaused;
        {
            QMutexLocker locker(&this->m_aMutex);
            b = this->m_stop;
            currentThreadCount = this->m_pjsObjectList.size();
            maxThread = this->m_maxThread;
            isMockPageEnabled = this->m_generateMockPage;
            isEmailEnabled = this->m_sendEmail;
            isFacebookEnabled = this->m_sendMessage;
            hasAnyIndex = this->m_indexList.size()!=0;
            isPaused = this->m_pause;
        }
        //If the thread is stopped remove all processes
        if(b){
            QMutexLocker locker(&this->m_pjsMutex);
            while (!this->m_pjsObjectList.isEmpty()) {
                PJSObject *obj = this->m_pjsObjectList.takeFirst();
                if(isPaused){
                    obj->pause();
                }
                else{
                    obj->stop();
                }
                obj->deleteLater();
            }
            break;
        }
        if(!hasAnyIndex && currentThreadCount==0) break;

        //check max threads and create new one if necessary
        if(!b){
            if(isMockPageEnabled){
                if(currentThreadCount<this->m_maxThread && hasAnyIndex){
                    //create new threads and start
                    //qDebug() << "creating new thread and starting";
                    int row;
                    QString facebookId;
                    QString url;
                    {
                        QMutexLocker locker(&this->m_aMutex);
                        row = this->m_indexList.takeFirst();
                        facebookId = this->m_facebookIdList.takeFirst();
                        url = this->m_facebookUrlList.takeFirst();
                    }
                    this->addP(row,facebookId,url);
                    QString imagePath = QDir::toNativeSeparators(imageDir+"/"+facebookId);

                    PJSObject *obj = new PJSObject();
                    {
                        QMutexLocker locker(&this->m_pjsMutex);
                        this->m_pjsObjectList.append(obj);
                    }
                    this->connect(obj,SIGNAL(pjsMessage(int,QString)),this,SLOT(pjsMessage(int,QString)));
                    obj->setup(row,row,url,imagePath,profile);
                    //obj->start();
                }
            }
            else{
                int row = this->takeOne();
                if(row!=-1){
                    if(isEmailEnabled) emit sendEmail(row);
                    if(isFacebookEnabled) emit sendFacebookMessage(row);
                }
            }
        }
        QApplication::processEvents();
        this->msleep(500);
        //qDebug() << "Running";
    }

    bool isPaused;
    {
        QMutexLocker locekr(&this->m_aMutex);
        isPaused = this->m_pause;
    }

    if(isPaused){
        emit threadPaused();
    }
    else{
        emit threadFinished();
    }
}
