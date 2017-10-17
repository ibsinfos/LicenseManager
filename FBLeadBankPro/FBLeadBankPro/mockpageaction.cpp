#include "mockpageaction.h"
#include "ui_mockpageaction.h"

MockPageAction::MockPageAction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MockPageAction)
{
    ui->setupUi(this);
    this->stopState();
}

MockPageAction::~MockPageAction()
{
    delete ui;
}

bool MockPageAction::isMockPageChecked()
{
    return this->ui->generateMockPageCheckBox->isChecked();
}

bool MockPageAction::isFacebookMessageChecked()
{
    return this->ui->sendFacebookMessageCheckBox->isChecked();
}

bool MockPageAction::isEmailChecked()
{
    return this->ui->sendEmailCheckBox->isChecked();
}

bool MockPageAction::isUseWebSiteAsMockPage()
{
    return this->ui->useWebSiteForMockPage->isChecked();
}

void MockPageAction::startState()
{
    this->ui->generateMockPageCheckBox->setEnabled(false);
    this->ui->sendEmailCheckBox->setEnabled(false);
    this->ui->sendFacebookMessageCheckBox->setEnabled(false);
    this->ui->useWebSiteForMockPage->setEnabled(false);

    this->ui->startButton->setEnabled(false);
    this->ui->pauseButton->setEnabled(true);
    this->ui->stopButton->setEnabled(true);
    this->ui->resumeButton->setEnabled(false);
}

void MockPageAction::pauseState()
{
    this->ui->generateMockPageCheckBox->setEnabled(false);
    this->ui->sendEmailCheckBox->setEnabled(false);
    this->ui->sendFacebookMessageCheckBox->setEnabled(false);
        this->ui->useWebSiteForMockPage->setEnabled(false);

    this->ui->startButton->setEnabled(false);
    this->ui->pauseButton->setEnabled(false);
    this->ui->stopButton->setEnabled(false);
    this->ui->resumeButton->setEnabled(true);
}

void MockPageAction::stopState()
{
    this->ui->generateMockPageCheckBox->setEnabled(true);
    this->ui->sendEmailCheckBox->setEnabled(true);
    this->ui->sendFacebookMessageCheckBox->setEnabled(true);
        this->ui->useWebSiteForMockPage->setEnabled(true);

    this->ui->startButton->setEnabled(true);
    this->ui->pauseButton->setEnabled(false);
    this->ui->stopButton->setEnabled(false);
    this->ui->resumeButton->setEnabled(false);
}

void MockPageAction::resumeState()
{
    this->ui->generateMockPageCheckBox->setEnabled(false);
    this->ui->sendEmailCheckBox->setEnabled(false);
    this->ui->sendFacebookMessageCheckBox->setEnabled(false);
        this->ui->useWebSiteForMockPage->setEnabled(false);

    this->ui->startButton->setEnabled(false);
    this->ui->pauseButton->setEnabled(true);
    this->ui->stopButton->setEnabled(true);
    this->ui->resumeButton->setEnabled(false);
}

void MockPageAction::on_startButton_clicked()
{
    emit mockPageActionStart();
    // this->startState();
}

void MockPageAction::on_stopButton_clicked()
{
    emit mockPageActionStop();
    //this->stopState();
}

void MockPageAction::on_pauseButton_clicked()
{
    emit mockPageActionPause();
    //this->pauseState();
}

void MockPageAction::on_resumeButton_clicked()
{
    emit mockPageActionResume();
    //this->resumeState();
}
