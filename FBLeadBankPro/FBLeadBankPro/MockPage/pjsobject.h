#ifndef PJSOBJECT_H
#define PJSOBJECT_H

#include <QObject>
#include <QProcess>
#include <QTimer>
#include <QPixmap>
#include "metashotprofile.h"

class PJSObject : public QObject
{
    Q_OBJECT
private:
    QProcess *m_pjsProcess;
    QTimer m_timer;
    QTimer m_requestTimer;

    QString m_pjsExe;
    int m_index;
    QString m_url;
    QString m_target;
    MetaShotProfile *m_profile;
    QString m_jsPath;
    int m_serialNumber;
    QString m_imagePath;

    bool m_stop;
    bool m_delayOverlayImage;

    QString m_status;

public:
    explicit PJSObject(QObject *parent = 0);

    void setup(int index,int number, const QString &url,const QString &target,const QString &profile,bool isPath=false);
    int serialNumber();
    int index();

    void delayOverlayImage();

    bool isFinished();
    bool isProcessRunning();

    QPixmap paintOverlayImage(int value);

    QString imagePath();

    QString overlayImagePath();

    ~PJSObject();

    public slots:
       void stop();
       void pause();
private:
    void refreshJS();

signals:
    void pjsMessage(int index, const QString &message);

private slots:
    void started();
    void finished(int exitCode, QProcess::ExitStatus exitStatus);

    void timeOut();

    void requestTimeOut();

public slots:
};

#endif // PJSOBJECT_H
