#ifndef PAGEDASHBOARD_H
#define PAGEDASHBOARD_H

#include <QWidget>
#include <QSettings>
#include <QMovie>
#include <QTextBrowser>
#include <QMenu>
#include <QAction>
#include <QMap>
#include <QFile>


#include "fbgraphapi.h"
#include "qnodejs.h"
#include "MockPage/pjsobject.h"
#include "dbobject.h"
#include "smtp.h"


#include "pjsthreadmanager.h"

namespace Ui {
class PageDashboard;
}

class PageDashboard : public QWidget
{
    Q_OBJECT
private:
    FBGraphApi m_fbGraphApi;
    QNodeJs m_nodeJs;
    QMovie m_spinProgress;

    int m_filteredResult;

    QMenu m_tableMenu;
    QAction *m_removeAction;
    QAction *m_sendEmailAction;
    QAction *m_sendMessageAction;

    int m_maximumPJSList;

    int m_dashBoradState;//0-search 1-mockpage 2-sendmessage




    DbObject m_dbObject;
    QMap<Smtp*,QString> m_emailMap;
    QMap<QNodeJs*,QString> m_facebookMap;

    PJSThreadManager m_threadManager;
    QList<int> m_messageToBeSent;
    QList<int> m_emailToBeSent;

    QTimer m_emTimer;

public:
    explicit PageDashboard(QWidget *parent = 0);
    ~PageDashboard();

    QTextBrowser *getLogBrowser();

    void addLog(const QString &msg);

private:
    void updateRowNumbering(int start=0);


    void resizeHeight();


    void updateCountrySlectionBox();

    void updateCitySelection();


private slots:
    void on_searchButton_clicked();

    //void pjsMessage(int index,const QString &message);

    void fbSearchStarted();
    void fbSearchFinished();
    void fbSearchStopped();

    void fbSearchPaused();
    void fbSearchResumed();

    void transmitResult(const QVariantMap &data);

    void appendResult(const QVariantMap &data);

    void fbUpdateToken();

    void fbTotalResultFound(int number);

    void on_stopButton_clicked();


    void sendFacebookMessage(int row);
    void sendEmail(int row);
    void removeRow(int row);
    void actionWidgetSelectRow(int row,bool checked);

    void rowsState();

    void on_pauseButton_clicked();

    void messageSendingStarted();
    void messageSendingFinished();

    void tableContextMenu(const QPoint &pos);


    void removeSelection();
    void sendEmailSelection();
    void sendMessageSelection();


    void filterButton_clicked();
    void resetButton_clicked();
    void exportButton_clicked();


    void on_filterWidget_exportClicked();

    void on_filterWidget_filterClicked();

    void on_filterWidget_resetClicked();


    void mailStatus(const QString &message);
    void facebookMessageStatus(const QString &message);

    void mockPageActionStart();
    void mockPageActionStop();
    void mockPageActionPause();
    void mockPageActionResume();


    void showMockPagePreview(int row);

    void updateMessageFromThread(int row, const QString &message);

    void threadFinished();
    void threadStopped();
    void threadPaused();
    void errorFromThread(const QString &message);

    void sendEmailFromThread(int row);
    void sendFacebookMessageFromThread(int row);


    void emTimeout();

//    void on_countrySelectionBox_activated(int index);

    void on_leadListTable_itemSelectionChanged();

    void on_pushButton_clicked();

    void on_resetButton_clicked();

    void on_leadListTable_cellClicked(int row, int column);

private:
    Ui::PageDashboard *ui;
};

#endif // PAGEDASHBOARD_H
