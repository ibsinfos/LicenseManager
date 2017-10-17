#ifndef QNODEJS_H
#define QNODEJS_H

#include <QMutex>
#include <QObject>
#include <QProcess>
#include <QThread>
#include <QMutexLocker>

class QNodeJs : public QThread
{
    Q_OBJECT
private:
    QString m_exeName;
    QString m_exePath;
    QProcess *m_nodeJsProcess;
    QString m_finalString;
    QStringList m_args;

    bool m_isRunning;

    QMutex aMutex;

public:
    explicit QNodeJs();
    ~QNodeJs();

protected:
    void run() Q_DECL_OVERRIDE;

signals:
    void nodeJsStarted();
    void nodeJsFinished();
    void status(const QString &message);

private slots:
    void processFinished();

public slots:
    void start(const QString &path, const QStringList &args);
    void stop();
    bool isRunning();

    QString finalString();
};

#endif // QNODEJS_H
