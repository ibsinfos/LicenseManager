#ifndef UTILITY_H
#define UTILITY_H

#include <QObject>
#include <QDebug>

class Utility : public QObject
{
    Q_OBJECT
public:
    explicit Utility(QObject *parent = 0);

signals:

public slots:
    void testChannel();

};

#endif // UTILITY_H
