#include "logbrowser.h"
#include "ui_logbrowser.h"

LogBrowser *LogBrowser::m_ins = Q_NULLPTR;

LogBrowser::LogBrowser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogBrowser)
{
    ui->setupUi(this);
}

LogBrowser::~LogBrowser()
{
    delete ui;
}

void LogBrowser::clearLogs()
{
    this->ui->logBrowser->clear();
}

QTextBrowser *LogBrowser::getLogBrowser()
{
    return this->ui->logBrowser;
}

LogBrowser *LogBrowser::ins()
{
    if(LogBrowser::m_ins==Q_NULLPTR){
        LogBrowser::m_ins = new LogBrowser();
    }
    return LogBrowser::m_ins;
}

void LogBrowser::addLog(const QString &msg)
{
    this->ui->logBrowser->append(msg);
}
