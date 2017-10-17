#include "fbgraphapi.h"

FBGraphApi::FBGraphApi(QObject *parent) : QObject(parent)
{
    this->m_rootURL = "https://graph.facebook.com/";
    this->m_apiVersion = "v2.8";

    this->m_grapApiURL = this->m_rootURL+this->m_apiVersion;

    this->m_reply = Q_NULLPTR;



    this->m_detailsList << "id"<<"name"<<"location"<<"phone"<<"emails"<<"link"<<"website"<<"is_unclaimed"<<"is_verified";
}

void FBGraphApi::setAccessToken(const QString &accessToken)
{
    if(this->m_accessToken!=accessToken){
        this->m_accessToken = accessToken;
    }
}

void FBGraphApi::searchLead(const QString &q, int limit)
{
    emit fbSearchStarted();
    //qDebug() << limit;
    this->m_stop = false;
    this->m_pause = false;
    this->m_isCollectingDetails = false;
    this->m_detailsQueue.clear();

    QUrl url(this->m_grapApiURL+"/search");
    QUrlQuery query;
    query.addQueryItem("q",q);
    query.addQueryItem("limit",QString::number(limit));
    query.addQueryItem("pretty","0");
    query.addQueryItem("type","page");
    query.addQueryItem("access_token",this->m_accessToken);
    url.setQuery(query);

    QNetworkRequest request;
    request.setUrl(url);

    QNetworkReply *reply =  this->m_nam.get(request);

    this->connect(reply,SIGNAL(finished()),this,SLOT(loadFinished()));
    this->connect(reply,SIGNAL(error(QNetworkReply::NetworkError)),this,SLOT(loadError(QNetworkReply::NetworkError)));

    this->m_reply = reply;
}

void FBGraphApi::findPage(const QString &page)
{
    this->m_detailsQueue.enqueue(page);
        this->m_isCollectingDetails = true;
    this->getDetails();
}

void FBGraphApi::pageEnque(const QStringList &pages)
{
    this->m_detailsQueue.clear();

    foreach(QString page, pages){
        //qDebug() << page;
        this->m_detailsQueue.enqueue(page);
    }
        this->m_isCollectingDetails = true;
    this->getDetails();
}

void FBGraphApi::getDetails()
{
    if(this->m_stop||this->m_pause) return;
    if(!this->m_detailsQueue.isEmpty())
    {
        QUrl url(this->m_grapApiURL+"/"+this->m_detailsQueue.dequeue());
        QUrlQuery query;
        QString fields = this->m_detailsList.join(",");
        query.addQueryItem("fields",fields);
        query.addQueryItem("access_token",this->m_accessToken);
        url.setQuery(query);

        QNetworkRequest request;
        request.setUrl(url);

        QNetworkReply *reply =  this->m_nam.get(request);

        this->connect(reply,SIGNAL(finished()),this,SLOT(detailsLoadFinished()));
        this->connect(reply,SIGNAL(error(QNetworkReply::NetworkError)),this,SLOT(detailsLoadError(QNetworkReply::NetworkError)));

        this->m_reply = reply;
    }
    else{
        this->m_isCollectingDetails = false;
        emit fbSearchFinished();
    }
}

void FBGraphApi::loadFinished()
{
    if(this->m_reply!=Q_NULLPTR)
    {
        QJsonObject json = QJsonDocument::fromJson(this->m_reply->readAll()).object();

        if(json.contains("data")){
            QJsonArray jArray = json.value("data").toArray();
            emit fbTotalResultFound(jArray.count());
            for(int i=0;i<jArray.count();++i){
                QJsonObject obj = jArray.at(i).toObject();
                this->m_detailsQueue.enqueue(obj.value("id").toString());
            }
        }
        this->m_reply->deleteLater();
    }
    this->m_isCollectingDetails = true;
    this->getDetails();
}

void FBGraphApi::loadError(QNetworkReply::NetworkError code)
{
    if(code == QNetworkReply::ProtocolInvalidOperationError){
        emit fbUpdateToken();
    }
    //qDebug() << code;
}

void FBGraphApi::detailsLoadFinished()
{
    if(this->m_reply!=Q_NULLPTR)
    {
        QByteArray data = this->m_reply->readAll();
        this->m_reply->deleteLater();
        //qDebug() << data;
        data = data.replace("true","\"true\"");
        data = data.replace("false","\"false\"");
        QJsonObject jObj = QJsonDocument::fromJson(data).object();
        QVariantMap map;

        //qDebug() << jObj.value("emails").toArray();

        foreach(const QString &key, this->m_detailsList){
            if(key=="location"){
                if(jObj.contains(key)){
                    map.insert(key,jObj.value("location").toObject().toVariantMap());
                }
                else{
                    map.insert(key,QVariantMap());
                }
                continue;
            }
            else if(key=="emails"){
                if(jObj.contains(key)){
                    QJsonArray jArray = jObj.value(key).toArray();
                    QString email;
                    if(jArray.count()>0){
                        email = jArray.at(0).toString();
                    }
                    if(email != "<<not-applicable>>"){
                        map.insert(key,email);
                    }
                    else{
                        map.insert(key,QString());
                    }
                }
                else{
                    map.insert(key,QString());
                }
            }
            else if(jObj.contains(key))
            {
                //qDebug() <<"KEY: "<<key<<" " <<jObj.contains(key);
                if(key == "is_unclaimed" || key == "is_verified"){
                    //qDebug() <<key<<":"<< jObj.value("key").isUndefined();
                    QString value = jObj.value(key).toString();
                    if(key == "is_unclaimed"){
                        QString nval;
                        if(value == "true"){
                            nval = "Unclaimed";
                        }
                        map.insert(key,nval);
                    }
                    else {
                        QString nval;
                        if(value == "true"){
                            nval = "Verified";
                        }
                        map.insert(key,nval);
                    }

                }
                else{
                    QString val = jObj.value(key).toString();
                    //qDebug() << val;
                    if(val == "<<not-applicable>>"){
                        map.insert(key,"");
                    }
                    else{
                        map.insert(key,val);
                    }
                }
            }
            else{
                map.insert(key,QString());
            }
        }

        map.insert("SERIALIZE",this->m_detailsList);
        emit transmitResult(map);
        //qDebug() << map;

    }
    this->getDetails();
}

void FBGraphApi::detailsLoadError(QNetworkReply::NetworkError code)
{
    qDebug() << code;
    if(this->m_isCollectingDetails) this->pauseSearch();
    emit fbUpdateToken();
}

void FBGraphApi::stopSearch()
{
    this->m_stop = true;
    emit fbSearchStopped();
}

void FBGraphApi::pauseSearch()
{
    this->m_pause = true;
    emit fbSearchPaused();
}

void FBGraphApi::resumeSearch()
{
    this->m_pause = false;
    emit fbSearchResumed();
    this->getDetails();
}

void FBGraphApi::sendMessage(const QString &to, const QString &message)
{
    qDebug()<<"TO:"<<to<<" MSG:"<<message;
    QUrl url(this->m_grapApiURL+"/me/messages");
    QUrlQuery query;
    query.addQueryItem("access_token",this->m_accessToken);
    url.setQuery(query);

    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader,QString("application/json"));
    QString data = QString("{\"recipient\":{\"id\":\"%1\"},\"message\":{\"text\":\"%2\"}}").arg(to).arg(message);

    qDebug() << data;
    QNetworkReply *reply = this->m_nam.post(req,data.toLocal8Bit());
    this->m_messageSendingReply.append(reply);

    this->connect(reply,SIGNAL(finished()),this,SLOT(messageSendingFinished()));
    this->connect(reply,SIGNAL(error(QNetworkReply::NetworkError)),this,SLOT(messageSendingError(QNetworkReply::NetworkError)));
}

void FBGraphApi::messageSendingFinished()
{
    qDebug() << this->sender()->objectName();
}

void FBGraphApi::messageSendingError(QNetworkReply::NetworkError code)
{
    qDebug() << "messageSendingError:"<<code;
    qDebug() << this->sender()->objectName();

    if(this->m_isCollectingDetails) {
        this->pauseSearch();
    }
    emit fbUpdateToken();
}
