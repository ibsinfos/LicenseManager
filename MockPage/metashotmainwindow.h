#ifndef METASHOTMAINWINDOW_H
#define METASHOTMAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMutex>
#include <QMutexLocker>
#include <QDesktopServices>

#include "pjsobject.h"

namespace Ui {
class MetaShotMainWindow;
}

class MetaShotMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    PJSObject *m_pjs;
    int m_currentRow;
    bool m_stop;
    QString m_csvField;

    QTimer m_progressTimer;
    int m_progressCount;

    int m_maximumPJSList;
    QList <PJSObject*> m_pjsList;
    QList<int> m_taskCompleted;

    QList<int> m_renderingList;
    QList<int> m_unexpectedPauseList;

    QMutex m_mutex;
    bool m_pause;
public:
    explicit MetaShotMainWindow(QWidget *parent = 0);
    ~MetaShotMainWindow();

private:
    void enableStartState();
    void disbleStartState();
    void setProgressMessage();

    void clearPJSProcessAfterStop();
    void clearPJSProcessAfterFinish();
    void clearPJSProcessAfterPause();

    void resetState();

    QStringList parseCSV(const QByteArray &data);

private slots:
    void on_action_Exit_triggered();

    void on_action_Load_triggered();

    void on_newProfileButton_clicked();

    void on_addButton_clicked();

    void appendUrlToTable(const QString &url);

    void on_importButton_clicked();

    void on_browseButton_clicked();

    void on_profileList_activated(const QString &arg1);

    void on_profileList_activated(int index);

    void on_refreshProfileButton_clicked();

    void on_editProfileButton_clicked();

    void on_startButton_clicked();

    void on_pushButton_clicked();


    void pjsMessage(int index,const QString &message);

    void on_actionClear_URL_TABLE_triggered();


    void progressReport();

    void on_stopButton_clicked();

    void on_supportButton_clicked();

    void on_pauseButton_clicked();

private:
    Ui::MetaShotMainWindow *ui;
};

#endif // METASHOTMAINWINDOW_H
