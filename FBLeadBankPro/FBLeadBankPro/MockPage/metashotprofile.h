#ifndef METASHOTPROFILE_H
#define METASHOTPROFILE_H

#include <QString>
#include <QVariant>
#include <QSettings>

class MetaShotProfile
{
private:
    QSettings *m_settings;
    QString m_profileName;

public:
    explicit MetaShotProfile();
    explicit MetaShotProfile(const QString &name,bool path=false);
    ~MetaShotProfile();

    void set(const QString &key, const QVariant &value);
    QVariant get(const QString &key);


    QString userAgent();
    QString browserWidth();
    QString browserHeight();
    QString imageType();

    QString imageHeight();
    QString imageWidth();

    QString imageQuality();
    QString imageOverlay();

    QString profileName();

    bool isProfileExists();

    bool imageOverlayCheckbox();

    int imageOverlaySizeScale();

    int maxMetaRefresh();
    int maxRequestTime();
    int refreshTime();
};

#endif // METASHOTPROFILE_H
