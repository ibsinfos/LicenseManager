#include <QMessageBox>
#include <QDebug>

#include "profileselector.h"
#include "ui_profileselector.h"
#include "MockPage/metashot.h"
#include "MockPage/metashotprofile.h"
#include "MockPage/metashotprofilecreator.h"

ProfileSelector::ProfileSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileSelector)
{
    ui->setupUi(this);
    this->on_refreshButton_clicked();
    this->m_ProfileName =  MetaShot::ins()->value("currentProfile").toString();
}

ProfileSelector::~ProfileSelector()
{
    delete ui;
}

MetaShotProfile ProfileSelector::getProfile()
{
    return MetaShotProfile(this->m_ProfileName);
}

void ProfileSelector::on_newButton_clicked()
{
    MetaShotProfileCreator pfc;
    pfc.exec();
    this->on_refreshButton_clicked();
}

void ProfileSelector::on_editButton_clicked()
{
    MetaShotProfileCreator pfc;
    //qDebug() << this->ui->profileList->currentText();
    pfc.loadDataFromProfile(this->ui->profileList->currentText());
    pfc.exec();
    this->on_refreshButton_clicked();
}

void ProfileSelector::on_refreshButton_clicked()
{
    QStringList pList = MetaShot::ins()->profileList();
    while (this->ui->profileList->count()>0){
        this->ui->profileList->removeItem(this->ui->profileList->count()-1);
    }

    this->ui->profileList->addItems(pList);
    int i = MetaShot::ins()->value("currentProfileIndex").toInt();

    //qDebug() << i;
    if(i<this->ui->profileList->count()) this->ui->profileList->setCurrentIndex(i);
    //else this->ui->profileList->setCurrentIndex(i);
}

void ProfileSelector::on_deleteButton_clicked()
{
    QString p = this->ui->profileList->currentText();
    if (p=="Default"){
        QMessageBox::warning(this,"Error","Can not delete Default profile");
    }
    else{
        MetaShot::ins()->deleteProfile(p);
        this->on_refreshButton_clicked();
        QMessageBox::information(this,"Success","Profile Removed.");
        MetaShot::ins()->setValue("currentProfile","");
        MetaShot::ins()->setValue("currentProfileIndex",-1);
    }
}

void ProfileSelector::on_profileList_activated(const QString &arg1)
{
    this->m_ProfileName = arg1;
    MetaShot::ins()->setValue("currentProfile",arg1);
}

void ProfileSelector::on_profileList_activated(int index)
{
    MetaShot::ins()->setValue("currentProfileIndex",index);
    this->m_ProfileName = this->ui->profileList->itemText(index);
}
