#ifndef METASHOT_H
#define METASHOT_H

#include <QObject>
#include <QString>
#include <QVariant>

class MetaShot : public QObject
{
    Q_OBJECT
private:
    static MetaShot *m_ins;
    QString m_metaId;

private:
    explicit MetaShot(QObject *parent = 0);
public:
    QString appDataRoot();
    QString profileListPath();
    QString profilePath(const QString &name);

    bool deleteProfile(const QString &name);
    QStringList profileList();

    QString tempPath();
    QString tempProfile();
    QString urlForPreview();
    void setPreviewUrl(const QString &url);

    QString jsPath();

    void cleanTemp();
    void cleanJS();

    void setValue(const QString &key, const QVariant &value);
    QVariant value(const QString &key);

    static MetaShot *ins();

    QString metaId();

signals:

public slots:
};

#endif // METASHOT_H
