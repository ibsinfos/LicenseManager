#ifndef PAGESETUP_H
#define PAGESETUP_H

#include <QWidget>
#include "MockPage/metashot.h"
#include "qmonster.h"

namespace Ui {
class PageSetup;
}

class PageSetup : public QWidget
{
    Q_OBJECT
private:
    QMonster *m_monster;
    QStringList m_argsList;
public:
    explicit PageSetup(QWidget *parent = 0);

    ~PageSetup();
private slots:
    void on_buttonSave_clicked();

    void on_getTokenButton_clicked();

    void on_loginToFacebook_clicked();


    void monsterFinished();
    void mosterStarted();
    void monsterStopped();
    void monsterPaused();
    void monsterResumed();
    void monsterNotFoundError();

    void on_logoutFromFacebook_clicked();

    void on_showPassword_clicked();

private:
    Ui::PageSetup *ui;
};

#endif // PAGESETUP_H
