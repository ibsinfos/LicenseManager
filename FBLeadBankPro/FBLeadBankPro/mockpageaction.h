#ifndef MOCKPAGEACTION_H
#define MOCKPAGEACTION_H

#include <QWidget>

namespace Ui {
class MockPageAction;
}

class MockPageAction : public QWidget
{
    Q_OBJECT

public:
    explicit MockPageAction(QWidget *parent = 0);
    ~MockPageAction();

    bool isMockPageChecked();
    bool isFacebookMessageChecked();
    bool isEmailChecked();
    bool isUseWebSiteAsMockPage();


    void startState();
    void pauseState();
    void stopState();
    void resumeState();

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_pauseButton_clicked();

    void on_resumeButton_clicked();

signals:
    void mockPageActionStart();
    void mockPageActionStop();
    void mockPageActionPause();
    void mockPageActionResume();

private:
    Ui::MockPageAction *ui;
};

#endif // MOCKPAGEACTION_H
