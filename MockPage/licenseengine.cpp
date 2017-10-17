#include "licenseengine.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include "metashot.h"

LicenseEngine::LicenseEngine(QObject *parent) : QObject(parent)
{

    this->m_rootUrl = QString("http://app.leadbankpro.com/api/");
    QSettings settings(MetaShot::ins()->appDataRoot()+"/lbp.s",QSettings::IniFormat);
    this->m_UUID = settings.value("UID").toString();

    if(this->m_UUID.isEmpty()){
        this->m_UUID = QUuid::createUuid().toString();
        settings.setValue("UID",this->m_UUID);
        settings.sync();
    }
}

void LicenseEngine::licenseValidationReport()
{
    QByteArray data = this->m_reply->readAll();
    this->m_reply->deleteLater();

    qDebug() << data;
    QJsonObject obj = QJsonDocument::fromJson(data).object();

    qDebug()<<obj;

//    if(obj.contains("license")){
//        if(obj.value("license").toString() == QLatin1String("valid")){
//            emit validLicense();
//        }
//        else{
//            emit invalidLicense();
//        }
//    }
//    else{
//        emit invalidLicense();
//    }
    if(obj.contains("status")){
        if(obj.value("status") == 200){
            emit validLicense();
        }
        else{
            emit invalidLicense();
        }
    }
    else{
        emit invalidLicense();
    }


}

void LicenseEngine::licenseValidationErrorReport(QNetworkReply::NetworkError code)
{
    Q_UNUSED(code);
    this->m_reply->deleteLater();
    emit error();
}

void LicenseEngine::validateLicense(const QString &license, const QString &product_id)
{
    info = QHostInfo::fromName( QHostInfo::localHostName() );
    ip = info.addresses();
    qDebug()<<"IP:" << ip[0].toString();
   for(int a =0;a<ip.length();a++)
    {
     qDebug()<<"IP:"<<a<< ip[a].toString();
    }
 qDebug()<<"licensekey:" << license<<"product_id"<<product_id;
    QUrlQuery query;

    query.addQueryItem("licensekey",license);

    query.addQueryItem("product_id",product_id);
    query.addQueryItem("ip_address",ip[1].toString());

    QUrl url(this->m_rootUrl);
    url.setQuery(query);


    qDebug()<<"LC:" << url.toString();
    QNetworkRequest r;
    r.setUrl(url);
    r.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    //qDebug() << url.toString();

    this->m_reply = this->m_nam.get(r);
    this->connect(this->m_reply,SIGNAL(finished()),this, SLOT(licenseValidationReport()));
    this->connect(this->m_reply,SIGNAL(error(QNetworkReply::NetworkError)),this,SLOT(licenseValidationErrorReport(QNetworkReply::NetworkError)));
}

