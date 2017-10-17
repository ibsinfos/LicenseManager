#include "actionwidget.h"
#include "ui_actionwidget.h"
#include <QDebug>
#include <QPixmap>

ActionWidget::ActionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionWidget)
{
    ui->setupUi(this);
#ifdef Q_OS_MAC
    this->ui->horizontalLayout->setSpacing(15);
#endif
#ifdef Q_OS_WIN
      this->ui->horizontalLayout->setSpacing(5);
#endif
    int square = this->height();
    this->ui->facebookMessengerButton->setFixedSize(square,square);
    this->ui->emailButton->setFixedSize(square,square);
    this->ui->removeButton->setFixedSize(square,square);
    this->ui->verifiedButton->setFixedSize(square,square);
    this->ui->unclaimedButton->setFixedSize(square,square);
    this->ui->mockPagePreview->setFixedSize(square,square);
    this->ui->mockPageStatus->setFixedSize(square,square);


    this->setVerifiedVisible(false);
    this->setUnclaimedVisible(false);
}

ActionWidget::~ActionWidget()
{
    delete ui;
}

void ActionWidget::setRow(int num)
{
    this->m_row = num;
}

int ActionWidget::row()
{
    return this->m_row;
}

void ActionWidget::setEmailEnabled(bool b)
{
    this->ui->emailButton->setEnabled(b);
}

void ActionWidget::setVerifiedVisible(bool b)
{
    this->ui->verifiedButton->setVisible(b);
}

void ActionWidget::setUnclaimedVisible(bool b)
{
    this->ui->unclaimedButton->setVisible(b);
}

bool ActionWidget::isVerified()
{
    return this->ui->verifiedButton->isVisible();
}

bool ActionWidget::isUnclaimed()
{
    return this->ui->unclaimedButton->isVisible();
}

void ActionWidget::setMockPageStatus(const QString &pp, const QString &information)
{
    QPixmap p(pp);
    int square = 16;
    p = p.scaled(square,square,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this->ui->mockPageStatus->setPixmap(p);
    this->ui->mockPageStatus->setToolTip(information);
}

bool ActionWidget::isSelected()
{
    return this->ui->selectRowCheckBox->isChecked();
}

void ActionWidget::deselectRow()
{
    this->ui->selectRowCheckBox->setChecked(false);
}

void ActionWidget::on_facebookMessengerButton_clicked()
{
    emit sendFacebookMessage(this->m_row);
}

void ActionWidget::on_emailButton_clicked()
{
    emit sendEmail(this->m_row);
}

void ActionWidget::on_removeButton_clicked()
{
    emit removeRow(this->m_row);
}

void ActionWidget::on_mockPagePreview_clicked()
{
    emit showMockPagePreview(this->m_row);
}

void ActionWidget::on_selectRowCheckBox_toggled(bool checked)
{
    emit rowSelection(this->m_row,checked);
}
