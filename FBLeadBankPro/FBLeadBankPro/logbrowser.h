#ifndef LOGBROWSER_H
#define LOGBROWSER_H

#include <QWidget>
#include <QTextBrowser>

namespace Ui {
class LogBrowser;
}

class LogBrowser : public QWidget
{
    Q_OBJECT
    static LogBrowser *m_ins;
public:
    explicit LogBrowser(QWidget *parent = 0);

    ~LogBrowser();

    void clearLogs();

    QTextBrowser *getLogBrowser();

    static LogBrowser *ins();

public slots:
    void addLog(const QString &msg);

private:
    Ui::LogBrowser *ui;
};

#endif // LOGBROWSER_H
