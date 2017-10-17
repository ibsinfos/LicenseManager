#include "metashotprofile.h"
#include "metashot.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QSize>
#include <QDebug>
#include <QTime>

MetaShotProfile::MetaShotProfile(const QString &name, bool path)
{
    qsrand((uint)QTime::currentTime().msec());
    if(path){
        this->m_settings = new QSettings(name,QSettings::IniFormat);
    }
    else{
        this->m_settings = new QSettings(MetaShot::ins()->profilePath(name),QSettings::IniFormat);
    }

}

MetaShotProfile::~MetaShotProfile()
{
    delete this->m_settings;
}

void MetaShotProfile::set(const QString &key, const QVariant &value)
{
    this->m_settings->setValue(key,value);
    this->m_settings->sync();
}

QVariant MetaShotProfile::get(const QString &key)
{
    return this->m_settings->value(key);
}

QString MetaShotProfile::userAgent()
{
    QString ua = this->m_settings->value("userAgent").toString();
    if (ua.isEmpty()){
        ua = "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:49.0) Gecko/20100101 Firefox/49.0";
    }
    return ua;
}

QString MetaShotProfile::browserWidth()
{
    QString width = this->m_settings->value("browserWidth").toString();
    //qDebug() << width;
    if (width.isEmpty()){
        width = qApp->desktop()->screenGeometry().width();
    }
    return width;
}

QString MetaShotProfile::browserHeight()
{
    QString height = this->m_settings->value("browserHeight").toString();
    if (height.isEmpty()){
        height = qApp->desktop()->screenGeometry().width();
    }
    return height;
}

QString MetaShotProfile::imageType()
{
    int i = this->m_settings->value("imageType").toInt();
    //qDebug()<<i;
    if(i==0) return "png";
    else return "jpg";
}

QString MetaShotProfile::imageHeight()
{
    QString height = this->m_settings->value("imageHeight").toString();
    return height;
}

QString MetaShotProfile::imageWidth()
{
    QString width = this->m_settings->value("imageWidth").toString();
    return width;
}

QString MetaShotProfile::imageQuality()
{
    QString iq = this->m_settings->value("imageQuality").toString();
    return iq;
}

QString MetaShotProfile::imageOverlay()
{
    QString io = this->m_settings->value("imageOverlay").toString();
    return io;
}

bool MetaShotProfile::imageOverlayCheckbox()
{
    return this->m_settings->value("imageOverlayCheckBox").toBool();
}

int MetaShotProfile::imageOverlaySizeScale()
{
    QString io = this->m_settings->value("imageOverlaySize").toString();
    return io.toInt();
}

int MetaShotProfile::maxMetaRefresh()
{
    return this->m_settings->value("metaRefresh").toInt();
}

int MetaShotProfile::maxRequestTime()
{
    return this->m_settings->value("timeOut").toInt();
}

int MetaShotProfile::refreshTime()
{
    int high = this->maxMetaRefresh();
    int low = 5;
    high = low>high?high+low:high;
    return qrand() % ((high + 1)  - low) + low;
}
