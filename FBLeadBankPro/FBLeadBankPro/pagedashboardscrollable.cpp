#include "pagedashboardscrollable.h"
#include "ui_pagedashboardscrollable.h"

PageDashboardScrollable::PageDashboardScrollable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageDashboardScrollable)
{
    ui->setupUi(this);
}

PageDashboardScrollable::~PageDashboardScrollable()
{
    delete ui;
}

PageDashboard *PageDashboardScrollable::pd()
{
    return this->ui->dashBoard;
}
