#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <QWidget>

namespace Ui {
class FilterWidget;
}

class FilterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FilterWidget(QWidget *parent = 0);
    ~FilterWidget();

    QString nameFilterText();
    QString addressFilterText();
    bool isRemoveWithoutEmail();
    bool isRemoveWithoutAddress();
    bool isRemoveWithoutPhoneNumber();
    bool isRemoveUnclaimed();

signals:
    void resetClicked();
    void filterClicked();
    void exportClicked();

private slots:
    void on_resetButton_clicked();

    void on_filterButton_clicked();

    void on_exportButton_clicked();

private:
    Ui::FilterWidget *ui;
};

#endif // FILTERWIDGET_H
