#ifndef PJSTHREAD_H
#define PJSTHREAD_H

#include <QObject>
#include <QThread>

class PJSThread : public QThread
{
public:
    PJSThread();
    void setup(int index, const QString &url,const QString &target,const QString &profile);
};

#endif // PJSTHREAD_H
