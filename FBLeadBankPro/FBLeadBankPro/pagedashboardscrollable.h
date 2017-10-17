#ifndef PAGEDASHBOARDSCROLLABLE_H
#define PAGEDASHBOARDSCROLLABLE_H

#include <QWidget>

#include "pagedashboard.h"
namespace Ui {
class PageDashboardScrollable;
}

class PageDashboardScrollable : public QWidget
{
    Q_OBJECT

public:
    explicit PageDashboardScrollable(QWidget *parent = 0);
    ~PageDashboardScrollable();

    PageDashboard *pd();

private:
    Ui::PageDashboardScrollable *ui;
};

#endif // PAGEDASHBOARDSCROLLABLE_H
