#ifndef PROFILESELECTOR_H
#define PROFILESELECTOR_H

#include <QWidget>
#include "MockPage/metashotprofile.h"

namespace Ui {
class ProfileSelector;
}

class ProfileSelector : public QWidget
{
    Q_OBJECT
private:
    int m_maximumPJSList;
    QString m_ProfileName;

public:
    explicit ProfileSelector(QWidget *parent = 0);
    ~ProfileSelector();

    MetaShotProfile getProfile();


private slots:
    void on_newButton_clicked();

    void on_editButton_clicked();

    void on_refreshButton_clicked();

    void on_deleteButton_clicked();

    void on_profileList_activated(const QString &arg1);

    void on_profileList_activated(int index);

private:
    Ui::ProfileSelector *ui;
};

#endif // PROFILESELECTOR_H
