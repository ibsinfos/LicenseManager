#ifndef DBOBJECT_H
#define DBOBJECT_H

#include <QtSql>
#include <QObject>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QStandardPaths>

///////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief The DbObject class
///
/// variant = 0 - facebook; 1 - email
///////////////////////////////////////////////////////////////////////////////////////////////////
class DbObject : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase m_db;

public:
    explicit DbObject(QObject *parent = 0);
    ~DbObject();
    bool add(QString key, int variant);
    bool addEmailLog(QString key);
    bool addFacebookLog(QString key);

    qint64 totalEmailSent();
    qint64 totalFacebookMessageSent();
    qint64 totalMessageSent(int variant=-1);

    qint64 totalEmailSentToday();
    qint64 totalFacebookMessageSentToday();

    qint64 totalTextSent24();

    //bool isExists(int key, int variant);
    //QSqlRecord get(int key, int variant);
    //bool increase(int key,int variant);
    //bool update(int key,int variant,int count);
signals:

public slots:
};

#endif // DBOBJECT_H
