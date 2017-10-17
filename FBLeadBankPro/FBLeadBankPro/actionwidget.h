#ifndef ACTIONWIDGET_H
#define ACTIONWIDGET_H

#include <QWidget>

namespace Ui {
class ActionWidget;
}

class ActionWidget : public QWidget
{
    Q_OBJECT
private:
    int m_row;
public:
    explicit ActionWidget(QWidget *parent = 0);
    ~ActionWidget();

    void setRow(int num);
    int row();

    void setEmailEnabled(bool b);

    void setVerifiedVisible(bool b);

    void setUnclaimedVisible(bool b);

    bool isVerified();
    bool isUnclaimed();

    void setMockPageStatus(const QString &pp, const QString &information);

    bool isSelected();

    void deselectRow();

private slots:
    void on_facebookMessengerButton_clicked();

    void on_emailButton_clicked();

    void on_removeButton_clicked();

    void on_mockPagePreview_clicked();

    void on_selectRowCheckBox_toggled(bool checked);

signals:
    void sendFacebookMessage(int row);
    void sendEmail(int row);
    void removeRow(int row);
    void showMockPagePreview(int row);
    void rowSelection(int row, bool b);

private:
    Ui::ActionWidget *ui;
};

#endif // ACTIONWIDGET_H
