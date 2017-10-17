#ifndef LEADBANKPROMAINWINDOW_H
#define LEADBANKPROMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class LeadBankProMainWindow;
}

class LeadBankProMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LeadBankProMainWindow(QWidget *parent = 0);
    ~LeadBankProMainWindow();
private slots:
    void on_actionLog_Window_toggled(bool arg1);

    void on_action_Clear_Logs_triggered();

    void on_actionLog_Window_triggered();

private:
    Ui::LeadBankProMainWindow *ui;
};

#endif // LEADBANKPROMAINWINDOW_H
