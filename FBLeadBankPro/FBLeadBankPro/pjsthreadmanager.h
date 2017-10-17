#ifndef PJSTHREADMANAGER_H
#define PJSTHREADMANAGER_H

#include <QMutex>
#include <QObject>
#include <QThread>
#include <QMutexLocker>
#include <QList>
#include <QTimer>

#include "MockPage/pjsobject.h"

class PJSThreadManager:public QThread
{
    Q_OBJECT
private:
    int m_maxThread;
    QString m_profile;
    QString m_imageDir;

    QList <int> m_indexList;
    QList <QString> m_facebookIdList;
    QList <QString> m_facebookUrlList;

    QList <int> m_pIndexList;
    QList <QString> m_pFacebookList;
    QList <QString> m_pFacebookUrlList;


    QList <PJSObject*> m_pjsObjectList;
    QMutex m_pjsMutex;

    QMutex m_aMutex;

    bool m_stop;
    bool m_pause;

    bool m_sendMessage;
    bool m_sendEmail;
    bool m_generateMockPage;

public:
    explicit PJSThreadManager();
    ~PJSThreadManager();

    void setMaxThread(int num);
    void setProfile(const QString &profile);
    void setImageDir(const QString &path);

    void sendMessageEnabled(bool b);
    void sendEmailEnabled(bool b);
    void generateMockPageEnabled(bool b);


    void addFacebookId(int row, QString fbid,QString url);
    void removeFacebookId(QString fbid);
    void removeRow(int row);

    void clearAll();

    int takeOne();


    void clearRow(int row);

private:
    void addP(int row, QString fbid, QString url);
    void removeP(int row);
    void removeP(QString fbid);

    void addUnprocessedData();

protected:
    void run() Q_DECL_OVERRIDE;


signals:
    void updateMessage(int row, const QString &message);
    void error(const QString &message);

    void threadStopped();
    void threadFinished();
    void threadPaused();

    void sendEmail(int row);
    void sendFacebookMessage(int row);

public slots:
    void stop();
    void start();
    void pause();

private slots:
    void pjsMessage(int row, const QString &message);
};

#endif // PJSTHREADMANAGER_H
