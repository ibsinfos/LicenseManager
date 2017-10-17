#ifndef STATSWIDGET_H
#define STATSWIDGET_H

#include <QWidget>

namespace Ui {
class StatsWidget;
}

class StatsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatsWidget(QWidget *parent = 0);
    ~StatsWidget();

    void setTotalResult(const QString &s);
    void setTotalResultAfterFilter(const QString &s);
    void setTotalEmailAndMessageSent(const QString &s);

    void setEmailSentInLast24Hour(qint64 number, int limit);
    void setFacebookMessageSentInLast24Hour(qint64 number, int limit);

private:
    Ui::StatsWidget *ui;
};

#endif // STATSWIDGET_H
