#include "dbobject.h"
#include <QDebug>
#include <QDateTime>
#include <QDir>

DbObject::DbObject(QObject *parent) : QObject(parent)
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/LeadBankPro";
    QDir d;
    d.mkpath(path);
    path = path+QLatin1String("/main.db");
    path = QDir::toNativeSeparators(path);


    this->m_db = QSqlDatabase::addDatabase("QSQLITE","LeadBankProDb");
    this->m_db.setDatabaseName(path);
    if(this->m_db.open()){
        QSqlQuery query(this->m_db);
        if(!query.exec("CREATE TABLE IF NOT EXISTS LeadBankPro(id INTEGER PRIMARY KEY NOT NULL,key TEXT NOT NULL,created INTEGER NOT NULL,variant INTEGER default 0)")){
            qDebug() << "Failed to create databse table.";
        }
    }
}

DbObject::~DbObject()
{
    if(this->m_db.isOpen()){
        this->m_db.close();
        //QSqlDatabase::removeDatabase("LeadBankProDb");
    }
}

bool DbObject::add(QString key, int variant)
{
    QSqlQuery query(this->m_db);
    query.prepare("INSERT INTO LeadBankPro(key,created,variant) VALUES(:key,:created,:variant)");
    query.bindValue(":key",key);
    query.bindValue(":created",QDateTime::currentDateTimeUtc().toTime_t());
    query.bindValue(":variant",variant);
    if(query.exec()) return true;
    return false;
}

bool DbObject::addEmailLog(QString key)
{
    return this->add(key,1);
}

bool DbObject::addFacebookLog(QString key)
{
    return this->add(key,0);
}

qint64 DbObject::totalEmailSent()
{
    return this->totalMessageSent(1);
}

qint64 DbObject::totalFacebookMessageSent()
{
    return this->totalMessageSent(0);
}

qint64 DbObject::totalMessageSent(int variant)
{
    QSqlQuery q(this->m_db);
    if(variant==-1){
        q.prepare("SELECT count(id) FROM LeadBankPro");
    }
    else{
        q.prepare("SELECT count(id) FROM LeadBankPro WHERE variant = :variant");
        q.bindValue(":variant",variant);
    }
    if(q.exec()){
        q.next();
        return q.value(0).toLongLong();
    }
    return 0;
}

qint64 DbObject::totalEmailSentToday()
{
    QSqlQuery q(this->m_db);
    q.prepare("SELECT count(id) FROM LeadBankPro WHERE variant = :variant AND created >= :created");
    q.bindValue(":variant",1);
    q.bindValue(":created",QDateTime::currentDateTimeUtc().toTime_t() - 24*60*60);

    if(q.exec()){
        q.next();
        return q.value(0).toLongLong();
    }
    return 0;
}

qint64 DbObject::totalFacebookMessageSentToday()
{
    QSqlQuery q(this->m_db);
    q.prepare("SELECT count(id) FROM LeadBankPro WHERE variant = :variant AND created >= :created");
    q.bindValue(":variant",0);
    q.bindValue(":created",QDateTime::currentDateTimeUtc().toTime_t() - 24*60*60);

    if(q.exec()){
        q.next();
        return q.value(0).toLongLong();
    }
    return 0;
}

qint64 DbObject::totalTextSent24()
{
    QSqlQuery q(this->m_db);
    q.prepare("SELECT count(id) FROM LeadBankPro WHERE created >= :created");
    q.bindValue(":created",QDateTime::currentDateTimeUtc().toTime_t() - 24*60*60);
    if(q.exec()){
        q.next();
        return q.value(0).toLongLong();
    }
    return 0;
}

//bool DbObject::isExists(int key, int variant)
//{
//    QSqlQuery query(this->m_db);
//    query.prepare("SELECT * FROM LeadBankPro WHERE key=:key AND variant=:variant");
//    query.bindValue(":key",key);
//    query.bindValue(":variant",variant);
//    if(query.exec()){
//        while(query.next()){
//            return true;
//        }
//    }
//    return false;
//}

//QSqlRecord DbObject::get(int key, int variant)
//{
//    QSqlQuery query(this->m_db);
//    query.prepare("SELECT * FROM LeadBankPro WHERE key=:key AND variant=:variant");
//    query.bindValue(":key",key);
//    query.bindValue(":variant",variant);
//    if(query.exec()){
//        while(query.next()){
//            return query.record();
//        }
//    }
//    return QSqlRecord();
//}

//bool DbObject::increase(int key, int variant)
//{
//    if(this->isExists(key,variant)){
//        QSqlRecord r = this->get(key,variant);
//        return this->update(key,variant,r.value("count").toInt()+1);
//    }
//    else{
//        QSqlQuery query(this->m_db);
//        query.prepare("INSERT INTO LeadBankPro(key,created,updated,variant,");
//        query.bindValue(":key",key);
//        query.bindValue(":created",QDateTime::currentDateTimeUtc().toTime_t());
//        query.bindValue(":updated",QDateTime::currentDateTimeUtc().toTime_t());
//        query.bindValue(":variant",variant);
//        if(query.exec()) return true;
//    }
//    return false;
//}

//bool DbObject::update(int key, int variant, int count)
//{
//    QSqlQuery query(this->m_db);
//    query.prepare("UPDATE LeadBankPro SET count=:count,updated=:updated WHERE key=:key AND variant=:variant");
//    query.bindValue(":count",count);
//    query.bindValue(":updated",QDateTime::currentDateTimeUtc().toTime_t());
//    query.bindValue(":key",key);
//    query.bindValue(":variant",variant);

//    if(query.exec()){
//        return true;
//    }
//    return false;
//}
