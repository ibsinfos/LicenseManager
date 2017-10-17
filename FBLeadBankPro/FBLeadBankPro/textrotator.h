#ifndef TEXTROTATOR_H
#define TEXTROTATOR_H

#include <QObject>
#include <QString>
#include <QRegExp>
#include <QDebug>

class TextRotator : public QObject
{
    Q_OBJECT
public:
    explicit TextRotator(QObject *parent = 0);
    QString message(const QString &msg);

    int getRandomNumber(int max);

signals:

public slots:
};

#endif // TEXTROTATOR_H
