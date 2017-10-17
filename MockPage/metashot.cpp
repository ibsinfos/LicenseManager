#include "metashot.h"
#include <QApplication>
#include <QDir>
#include <QSettings>
#include <QTime>

MetaShot *MetaShot::m_ins = nullptr;

MetaShot::MetaShot(QObject *parent) : QObject(parent)
{
    qsrand(uint(QTime::currentTime().msec()));
    this->m_metaId = QString::number(rand());
}

QString MetaShot::appDataRoot()
{
    QString p = QDir::homePath()+QLatin1String("/")+QApplication::applicationName();
    p = QDir::toNativeSeparators(p);
    QDir d(p);
    if (!d.exists()) d.mkpath(p);
    return p;
}

QString MetaShot::profileListPath()
{
    QString p = this->appDataRoot()+"/"+"profiles";
    p = QDir::toNativeSeparators(p);
    QDir d(p);
    if(!d.exists()) d.mkpath(p);
    return p;
}

QString MetaShot::profilePath(const QString &name)
{
    return QDir::toNativeSeparators(this->profileListPath()+"/"+name+".p");
}

bool MetaShot::deleteProfile(const QString &name)
{
    QString p = this->profilePath(name);
    if(QFile::exists(p)){
        QFile::remove(p);
    }
    return true;
}

QStringList MetaShot::profileList()
{
    QDir d(this->profileListPath());
    QStringList l =  d.entryList(QStringList()<<"*.p");
    QStringList nl;
    foreach(const QString &s,l){
        QString t = s;
        t.remove(t.length()-2,2);
        nl.append(t);
    }
    return nl;
}

QString MetaShot::tempPath()
{
    QString p = this->appDataRoot()+"/temp";
    p = QDir::toNativeSeparators(p);
    QDir d(p);
    if (!d.exists()) d.mkpath(p);
    return p;
}

QString MetaShot::tempProfile()
{
    QString p = this->tempPath()+"/temp.p";
    p = QDir::toNativeSeparators(p);
    return p;
}

QString MetaShot::urlForPreview()
{
    QString p = this->value("urlForPreview").toString();
    if(p.isEmpty()) return QString("http://google.com");
    else return p;
}

void MetaShot::setPreviewUrl(const QString &url)
{
    this->setValue("urlForPreview",url);
}

QString MetaShot::jsPath()
{
    QString p = this->appDataRoot()+"/js";
    p = QDir::toNativeSeparators(p);
    QDir d(p);
    if (!d.exists()) d.mkpath(p);
    return p;
}

void MetaShot::cleanTemp()
{
    QDir dir(this->tempPath());
    dir.setNameFilters(QStringList() << "*.*");
    dir.setFilter(QDir::Files);
    foreach(QString dirFile, dir.entryList())
    {
        dir.remove(dirFile);
    }
}

void MetaShot::cleanJS()
{
    QDir dir(this->jsPath());
    dir.setNameFilters(QStringList() << "*.*");
    dir.setFilter(QDir::Files);
    foreach(QString dirFile, dir.entryList())
    {
        dir.remove(dirFile);
    }
}

void MetaShot::setValue(const QString &key, const QVariant &value)
{
    QSettings s(this->appDataRoot()+"/data.ini",QSettings::IniFormat,this);
    s.setValue(key,value);
    s.sync();
}

QVariant MetaShot::value(const QString &key)
{
    QSettings s(this->appDataRoot()+"/data.ini",QSettings::IniFormat,this);
    return s.value(key);
}

MetaShot *MetaShot::ins()
{
    if(MetaShot::m_ins==nullptr) MetaShot::m_ins = new MetaShot();
    return MetaShot::m_ins;
}

QString MetaShot::metaId()
{
    return this->m_metaId;
}
