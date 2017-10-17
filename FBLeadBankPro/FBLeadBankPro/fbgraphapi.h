#ifndef FBGRAPHAPI_H
#define FBGRAPHAPI_H

#include <QUrl>
#include <QList>
#include <QQueue>
#include <QDebug>
#include <QObject>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariantMap>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

///////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief The FBGraphApi class
///////////////////////////////////////////////////////////////////////////////////////////////////
class FBGraphApi : public QObject
{
    Q_OBJECT
private:
    QString m_accessToken;
    bool m_isCollectingDetails;
    QNetworkAccessManager m_nam;

    QString m_rootURL;
    QString m_apiVersion;

    QString m_grapApiURL;

    QNetworkReply *m_reply;

    QQueue<QString> m_detailsQueue;

    QStringList m_detailsList;
    bool m_stop;
    bool m_pause;

    QList<QNetworkReply*> m_messageSendingReply;

public:
    explicit FBGraphApi(QObject *parent = 0);
    void setAccessToken(const QString &accessToken);

    void searchLead(const QString &q,int limit=50);
    void findPage(const QString &page);
    void pageEnque(const QStringList &pages);

    QVariantMap searchResult();

private:
    void getDetails();

signals:
    void fbSearchStarted();
    void fbSearchFinished();
    void fbSearchStopped();

    void fbSearchPaused();
    void fbSearchResumed();

    void transmitResult(const QVariantMap &data);

    void fbUpdateToken();

    void fbTotalResultFound(int number);

public slots:
    void loadFinished();
    void loadError(QNetworkReply::NetworkError code);

    void detailsLoadFinished();
    void detailsLoadError(QNetworkReply::NetworkError code);

    void stopSearch();
    void pauseSearch();
    void resumeSearch();

    void sendMessage(const QString &to, const QString &message);

private slots:
    void messageSendingFinished();
    void messageSendingError(QNetworkReply::NetworkError code);
};

#endif // FBGRAPHAPI_H
