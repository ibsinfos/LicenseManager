/**************************************************************************************************
 * Object Name  : QMonster
 * Vesrion      : 1.0
 * Purpose      : Run any command line executables in a thread and receive results
 * Date         : 01/02/2017
 * Time         : 7:30 P.M
 * Developer    : kawser
 * Url          : www.kawser.org
 * Git          : github.com/QMonster
**************************************************************************************************/

#ifndef QMONSTER_H
#define QMONSTER_H

#include <QDir>
#include <QMutex>
#include <QObject>
#include <QThread>
#include <QProcess>
#include <QMutexLocker>
#include <QCoreApplication>

///////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief The QMonster class
///
/// QMonster is a allows to talk with other processes
///////////////////////////////////////////////////////////////////////////////////////////////////
class QMonster : public QThread
{
    Q_OBJECT
private:
    QString m_exePath;
    QStringList m_exeArgs;
    QMutex m_attribLock;
    QString m_result;
    QString m_error;

    int m_threadState;

public:
    explicit QMonster();
    void setExe(const QString &path, const QStringList &args);
    void setExePath(const QString &path);
    void setExeArgs(const QStringList &args);

    void setPath(const QString &path);
    void setArgs(const QStringList &args);

    QString processResult();
    QString processError();

    bool isRunning();

    int threadState();

protected:
    void run() Q_DECL_OVERRIDE;

signals:
    void threadStarted();
    void threadStopped();
    void threadPaused();
    void threadResumed();
    void threadFinished();
    void processNotFoundError();

public slots:
    void start();
    void stop();
    void pause();
    void resume();

private slots:

};

#endif // QMONSTER_H
