#ifndef LEADBANKPROSIMPLEUI_H
#define LEADBANKPROSIMPLEUI_H

#include <QWidget>
#include "pagedashboard.h"

namespace Ui {
class LeadBankProSimpleUi;
}

class LeadBankProSimpleUi : public QWidget
{
    Q_OBJECT

public:
    explicit LeadBankProSimpleUi(QWidget *parent = 0);
    ~LeadBankProSimpleUi();

    PageDashboard *pageDashBoard();


private slots:
    void on_dashBoardButton_clicked();

    void on_setupButton_clicked();

    void on_emailSetupButton_clicked();

    void on_updatesButton_clicked();

    void on_supportButton_clicked();

private:
    Ui::LeadBankProSimpleUi *ui;
};

#endif // LEADBANKPROSIMPLEUI_H
