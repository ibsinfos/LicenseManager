#include "leadbankpromainwindow.h"
#include "ui_leadbankpromainwindow.h"
#include "leadbankprosimpleui.h"
#include "pagedashboard.h"
#include <QStackedWidget>
#include "logbrowser.h"

LeadBankProMainWindow::LeadBankProMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LeadBankProMainWindow)
{
    ui->setupUi(this);

    //this->ui->actionLog_Window->setChecked(false);
    //this->ui->centralWidget->pageDashBoard()->getLogBrowser()->setVisible(true);
}

LeadBankProMainWindow::~LeadBankProMainWindow()
{
    delete ui;
}

void LeadBankProMainWindow::on_actionLog_Window_toggled(bool arg1)
{
    if(arg1) LogBrowser::ins()->show();
    else LogBrowser::ins()->hide();
}

void LeadBankProMainWindow::on_action_Clear_Logs_triggered()
{
    LogBrowser::ins()->clearLogs();
}

void LeadBankProMainWindow::on_actionLog_Window_triggered()
{
    LogBrowser::ins()->show();
}
