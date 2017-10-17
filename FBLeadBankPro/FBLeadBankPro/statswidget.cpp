#include "statswidget.h"
#include "ui_statswidget.h"
#include <QDebug>

StatsWidget::StatsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatsWidget)
{
    ui->setupUi(this);
}

StatsWidget::~StatsWidget()
{
    delete ui;
}

void StatsWidget::setTotalResult(const QString &s)
{
    this->ui->totalResultFound->setText(s);
}

void StatsWidget::setTotalResultAfterFilter(const QString &s)
{
    this->ui->totalResultAfterFilter->setText(s);
}

void StatsWidget::setTotalEmailAndMessageSent(const QString &s)
{
    this->ui->totalMessageSent->setText(s);
}

void StatsWidget::setEmailSentInLast24Hour(qint64 number, int limit)
{
    this->ui->emailSentToday->setText(QString::number(number));
    //qDebug() << limit;
    //qDebug() << number;
    if((limit-number)<=10){
        this->ui->emailSentToday->setStyleSheet("QLabel{background-color: rgb(255, 0, 0);font: 40pt;color: rgb(255, 255, 255);}");
    }
    else{

        this->ui->emailSentToday->setStyleSheet("QLabel{background-color: rgb(0, 255, 0);font: 40pt;color: rgb(255, 255, 255);}");
    }
}

void StatsWidget::setFacebookMessageSentInLast24Hour(qint64 number, int limit)
{
    this->ui->facebookMessageSentToday->setText(QString::number(number));
    if((limit-number)<10){
        this->ui->facebookMessageSentToday->setStyleSheet("QLabel{background-color: rgb(255, 0, 0);font: 40pt;color: rgb(255, 255, 255);}");
    }
    else{
        this->ui->facebookMessageSentToday->setStyleSheet("QLabel{background-color: rgb(0, 255, 0);font: 40pt;color: rgb(255, 255, 255);}");
    }
}
