#include "pagesetup.h"
#include "ui_pagesetup.h"

#include <QUrl>
#include <QSettings>
#include <QMessageBox>
#include <QDesktopServices>
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QDebug>

PageSetup::PageSetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageSetup)
{
    this->m_monster = new QMonster();

    this->m_argsList << QString("--cookies-file=%1").arg(MetaShot::ins()->cookiesPath());
    this->m_argsList << QDir::toNativeSeparators(QApplication::applicationDirPath()+"/facebook.js");

    ui->setupUi(this);

        QSettings settings(MetaShot::ins()->appDataRoot()+"/lbp.s",QSettings::IniFormat);
    this->ui->lineEditAccessToken->setText(settings.value("ACCESS_TOKEN").toString());
    this->ui->facebookMessageText->setPlainText(settings.value("FACEBOOK_MSG").toString());
    //this->ui->emailText->setPlainText(settings.value("EMAIL_MSG").toString());
    this->ui->facebookUser->setText(settings.value("FB_USER").toString());
    this->ui->facebookPassword->setText(settings.value("FB_PASS").toString());
    this->ui->maxFacebookMessagePerDay->setText(settings.value("MAX_FACEBOOK_MSG").toString());


    this->connect(this->m_monster,SIGNAL(threadStarted()),this,SLOT(mosterStarted()));
    this->connect(this->m_monster,SIGNAL(threadStopped()),this,SLOT(monsterStopped()));
    this->connect(this->m_monster,SIGNAL(threadResumed()),this,SLOT(monsterResumed()));
    this->connect(this->m_monster,SIGNAL(threadFinished()),this,SLOT(monsterFinished()));
    this->connect(this->m_monster,SIGNAL(threadPaused()),this,SLOT(monsterPaused()));
    this->connect(this->m_monster,SIGNAL(processNotFoundError()),this,SLOT(monsterNotFoundError()));

    if(QFile::exists(MetaShot::ins()->cookiesPath()))
    {
        this->ui->connectionMessage->setText("Connected");
        this->ui->loginToFacebook->setEnabled(false);
    }
    else{
        this->ui->connectionMessage->setText("Disconnected");
        this->ui->logoutFromFacebook->setEnabled(false);
    }
}

PageSetup::~PageSetup()
{
    delete ui;
    this->m_monster->stop();
    delete  this->m_monster;
}

void PageSetup::on_buttonSave_clicked()
{
    if(this->ui->lineEditAccessToken->text().isEmpty()){
        QMessageBox::information(this,"Error!!!","Please enter an access token. It's important.");
    }
    else{
        QSettings settings(MetaShot::ins()->appDataRoot()+"/lbp.s",QSettings::IniFormat);
        settings.setValue("ACCESS_TOKEN",this->ui->lineEditAccessToken->text());
        settings.setValue("FACEBOOK_MSG",this->ui->facebookMessageText->toPlainText());
        //settings.setValue("EMAIL_MSG",this->ui->emailText->toPlainText());
        settings.setValue("FB_USER",this->ui->facebookUser->text());
        settings.setValue("FB_PASS",this->ui->facebookPassword->text());
        settings.setValue("MAX_FACEBOOK_MSG",this->ui->maxFacebookMessagePerDay->text());
        settings.sync();
        QMessageBox::information(this,"Success","Information saved.");
    }
}

void PageSetup::on_getTokenButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://developers.facebook.com/tools/explorer"));
}

void PageSetup::on_loginToFacebook_clicked()
{
    if(this->ui->facebookUser->text().isEmpty() || this->ui->facebookPassword->text().isEmpty()){
        QMessageBox::information(this,"Error","Facebook username or password can not be empty");
        return;
    }

    QStringList list;
    list<<this->m_argsList;
    list << this->ui->facebookUser->text();
    list <<this->ui->facebookPassword->text();

    this->m_monster->setExeArgs(list);
    this->m_monster->start();
}

void PageSetup::monsterFinished()
{

    this->ui->loginToFacebook->setText("Login");


    QString r = this->m_monster->processResult().replace("\n","");
    r = r.replace("\n","");
    qDebug() <<r;
    if(r.toLower().startsWith("success")){
        this->ui->connectionMessage->setText("Connected");
        this->ui->loginToFacebook->setEnabled(false);
        this->ui->logoutFromFacebook->setEnabled(true);
    }
    else{
        this->ui->connectionMessage->setText("Disconnected");
        this->ui->loginToFacebook->setEnabled(true);
        this->ui->logoutFromFacebook->setEnabled(false);
    }

    QMessageBox::information(this,"Message",r);

}

void PageSetup::mosterStarted()
{
    this->ui->loginToFacebook->setEnabled(false);
    this->ui->logoutFromFacebook->setEnabled(false);
    this->ui->loginToFacebook->setText("Please wait...");
}

void PageSetup::monsterStopped()
{
    this->ui->loginToFacebook->setEnabled(true);
        this->ui->loginToFacebook->setText("Login");
}

void PageSetup::monsterPaused()
{
    this->ui->loginToFacebook->setEnabled(true);
        this->ui->loginToFacebook->setText("Login");
}

void PageSetup::monsterResumed()
{
    this->ui->loginToFacebook->setEnabled(true);
        this->ui->loginToFacebook->setText("Login");
}

void PageSetup::monsterNotFoundError()
{
    this->ui->loginToFacebook->setEnabled(true);
    this->ui->loginToFacebook->setText("Login");
}

void PageSetup::on_logoutFromFacebook_clicked()
{
    QString f = MetaShot::ins()->cookiesPath();

    if (QFile::exists(f)){
        QFile::remove(f);
    }
    this->ui->loginToFacebook->setEnabled(true);
    this->ui->logoutFromFacebook->setEnabled(false);
    this->ui->connectionMessage->setText("Disconnected");

        QMessageBox::information(this,"Message","Logged out from facebook");
}

void PageSetup::on_showPassword_clicked()
{
    if(this->ui->facebookPassword->echoMode()==QLineEdit::Normal){
        this->ui->facebookPassword->setEchoMode(QLineEdit::Password);
        this->ui->showPassword->setText("SHOW");
    }
    else{
        this->ui->facebookPassword->setEchoMode(QLineEdit::Normal);
        this->ui->showPassword->setText("HIDE");
    }
}
