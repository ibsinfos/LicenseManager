#include "textrotator.h"
#include <QDateTime>
#include <QDebug>

TextRotator::TextRotator(QObject *parent) : QObject(parent)
{
        qsrand(static_cast<uint>(QDateTime::currentMSecsSinceEpoch()));
}

QString TextRotator::message(const QString &msg)
{
    QRegExp rx("\\{(.*)\\}",Qt::CaseInsensitive,QRegExp::RegExp2);
    rx.setMinimal(true);
    int pos = 0;
    int startPoint = 0;
    QString newMsg;
    while ((pos = rx.indexIn(msg, pos)) != -1) {
        //qDebug() <<msg.mid(startPoint,pos-startPoint);
        newMsg.append(msg.mid(startPoint,pos-startPoint));
        QString matchedStr = rx.cap(1);
        pos += rx.matchedLength();
        if(matchedStr.length()>0){
           QStringList tokens =  matchedStr.split("|");
           QString choosenOne = tokens.at(this->getRandomNumber(tokens.length()-1));
           newMsg.append(choosenOne);
        }
        startPoint = pos;
    }
    //qDebug() << pos;
    //qDebug() << startPoint;
    newMsg.append(msg.mid(startPoint,msg.length()-startPoint));
    return newMsg;
}

int TextRotator::getRandomNumber(int max)
{

    return qrand() % ((max + 1) - 0) + 0;
}
