#include "pageemailsetup.h"
#include "ui_pageemailsetup.h"
#include <QSettings>
#include <QMessageBox>
#include "MockPage/metashot.h"

PageEmailSetup::PageEmailSetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageEmailSetup)
{
    ui->setupUi(this);

        QSettings settings(MetaShot::ins()->appDataRoot()+"/lbp.s",QSettings::IniFormat);
    this->ui->hostBox->setText(settings.value("HOST").toString());
    this->ui->portBox->setText(settings.value("PORT").toString());
    this->ui->sslRequired->setChecked(settings.value("SSL_REQUIRED").toBool());
    this->ui->emailBox->setText(settings.value("EMAIL_EMAIL").toString());
    this->ui->passwordBox->setText(settings.value("EMAIL_PASS").toString());
    this->ui->emailSubjectBox->setText(settings.value("EMAIL_SUBJECT").toString());
    this->ui->emailMessageBox->setPlainText(settings.value("EMAIL_MSG").toString());
    this->ui->maxEmailPerDay->setText(settings.value("MAX_EMAIL").toString());
    this->ui->emailImageWidth->setText(        settings.value("EMAIL_IMAGE_WIDTH").toString());
        this->ui->emailImageHeight->setText( settings.value("EMAIL_IMAGE_HEIGHT").toString());

            this->ui->fromEmail->setText(settings.value("FROM_EMAIL").toString());
}

PageEmailSetup::~PageEmailSetup()
{
    delete ui;
}

void PageEmailSetup::on_saveButton_clicked()
{
        QSettings settings(MetaShot::ins()->appDataRoot()+"/lbp.s",QSettings::IniFormat);
    settings.setValue("HOST",this->ui->hostBox->text());
    settings.setValue("PORT",this->ui->portBox->text());
    settings.setValue("SSL_REQUIRED",this->ui->sslRequired->isChecked());
    settings.setValue("EMAIL_EMAIL",this->ui->emailBox->text());
    settings.setValue("EMAIL_PASS",this->ui->passwordBox->text());
    settings.setValue("EMAIL_SUBJECT", this->ui->emailSubjectBox->text());
    settings.setValue("EMAIL_MSG", this->ui->emailMessageBox->toPlainText());
    settings.setValue("MAX_EMAIL",this->ui->maxEmailPerDay->text());
       settings.setValue("FROM_EMAIL",this->ui->fromEmail->text());
       settings.setValue("EMAIL_IMAGE_WIDTH",this->ui->emailImageWidth->text());
       settings.setValue("EMAIL_IMAGE_HEIGHT",this->ui->emailImageHeight->text());

    settings.sync();
    QMessageBox::information(this,"Success","Information saved.");
}

void PageEmailSetup::on_showPassword_clicked()
{
    if(this->ui->passwordBox->echoMode() == QLineEdit::Password){
        this->ui->passwordBox->setEchoMode(QLineEdit::Normal);
        this->ui->showPassword->setText("HIDE");
    }
    else{
        this->ui->passwordBox->setEchoMode(QLineEdit::Password);
        this->ui->showPassword->setText("SHOW");
    }
}

void PageEmailSetup::on_imageLink_returnPressed()
{
    QString link = this->ui->imageLink->text();
    if(link.isEmpty()) return;

    QString html = QString("<a href=\"%1\"><img></a>").arg(link);
    QString h = this->ui->emailMessageBox->toPlainText().replace("<img>",html);
    this->ui->emailMessageBox->setPlainText(h);
}
