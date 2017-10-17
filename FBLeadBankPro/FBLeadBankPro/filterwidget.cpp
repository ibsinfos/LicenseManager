#include "filterwidget.h"
#include "ui_filterwidget.h"

FilterWidget::FilterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterWidget)
{
    ui->setupUi(this);
}

FilterWidget::~FilterWidget()
{
    delete ui;
}

QString FilterWidget::nameFilterText()
{
    return this->ui->nameFilter->text();
}

QString FilterWidget::addressFilterText()
{
    return this->ui->addressFilter->text();
}

bool FilterWidget::isRemoveWithoutEmail()
{
    return this->ui->removeWithoutEmail->isChecked();
}

bool FilterWidget::isRemoveWithoutAddress()
{
    return this->ui->removeWithoutAddress->isChecked();
}

bool FilterWidget::isRemoveWithoutPhoneNumber()
{
    return this->ui->removeWithoutPhoneNumber->isChecked();
}

bool FilterWidget::isRemoveUnclaimed()
{
    return this->ui->removeUnclaimed->isChecked();
}

void FilterWidget::on_resetButton_clicked()
{
    this->ui->nameFilter->setText("");
    this->ui->addressFilter->setText("");
    this->ui->removeUnclaimed->setChecked(false);
    this->ui->removeWithoutAddress->setChecked(false);
    this->ui->removeWithoutEmail->setChecked(false);
    this->ui->removeWithoutPhoneNumber->setChecked(false);

    emit resetClicked();
}

void FilterWidget::on_filterButton_clicked()
{
    emit filterClicked();
}

void FilterWidget::on_exportButton_clicked()
{
    emit exportClicked();
}
