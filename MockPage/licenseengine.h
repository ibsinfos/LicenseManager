#ifndef LICENSEENGINE_H
#define LICENSEENGINE_H

#include <QUrl>
#include <QObject>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QUuid>
#include <QSettings>
#include "QHostInfo"

///////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief The LicenseEngine class
///
/// API to check license engine
///////////////////////////////////////////////////////////////////////////////////////////////////
class LicenseEngine : public QObject
{
    Q_OBJECT
    QString m_rootUrl;
    QNetworkAccessManager m_nam;
    QNetworkReply *m_reply;
    QString m_UUID;
    QHostInfo info;
    QList<QHostAddress> ip;
    bool m_isValid;
    bool m_isActivated;
public:
    explicit LicenseEngine(QObject *parent = 0);

signals:
    void invalidLicense();
    void validLicense();

    void licenseActivated();
    void error();

private slots:
        void licenseValidationReport();
        void licenseValidationErrorReport(QNetworkReply::NetworkError code);

public slots:
    void validateLicense(const QString &license,const QString &product_id);
};

#endif // LICENSEENGINE_H
