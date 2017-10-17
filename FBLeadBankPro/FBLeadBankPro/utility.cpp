#include "utility.h"

Utility::Utility(QObject *parent) : QObject(parent)
{

}

void Utility::testChannel()
{
    qDebug() << "Channel Working";
}
