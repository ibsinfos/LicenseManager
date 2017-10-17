#include "leadbankprosimpleui.h"
#include "ui_leadbankprosimpleui.h"
#include <QDesktopServices>
#include <QUrl>

LeadBankProSimpleUi::LeadBankProSimpleUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeadBankProSimpleUi)
{
    ui->setupUi(this);

    QPixmap pix(":/data/data/imgdata/FB-Lead-Bank.png");
    pix = pix.scaled(300,100,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this->ui->leadBankProLabel->setPixmap(pix);

}

LeadBankProSimpleUi::~LeadBankProSimpleUi()
{
    delete ui;
}

PageDashboard *LeadBankProSimpleUi::pageDashBoard()
{
    return this->ui->pageDashboard->pd();
}

void LeadBankProSimpleUi::on_dashBoardButton_clicked()
{
    this->ui->mainStackedWidget->setCurrentIndex(0);
}

void LeadBankProSimpleUi::on_setupButton_clicked()
{
    this->ui->mainStackedWidget->setCurrentIndex(1);
}

void LeadBankProSimpleUi::on_emailSetupButton_clicked()
{
    this->ui->mainStackedWidget->setCurrentIndex(2);
}

void LeadBankProSimpleUi::on_updatesButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("http://fbleadbank.com")));
}

void LeadBankProSimpleUi::on_supportButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("http://support.fbleadbank.com")));
}
