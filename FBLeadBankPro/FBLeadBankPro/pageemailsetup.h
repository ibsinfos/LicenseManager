#ifndef PAGEEMAILSETUP_H
#define PAGEEMAILSETUP_H

#include <QWidget>

namespace Ui {
class PageEmailSetup;
}

class PageEmailSetup : public QWidget
{
    Q_OBJECT

public:
    explicit PageEmailSetup(QWidget *parent = 0);
    ~PageEmailSetup();

private slots:
    void on_saveButton_clicked();

    void on_showPassword_clicked();

    void on_imageLink_returnPressed();

private:
    Ui::PageEmailSetup *ui;
};

#endif // PAGEEMAILSETUP_H
