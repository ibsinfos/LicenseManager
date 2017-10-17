/********************************************************************************
** Form generated from reading UI file 'leadbankpromainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEADBANKPROMAINWINDOW_H
#define UI_LEADBANKPROMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include "leadbankprosimpleui.h"

QT_BEGIN_NAMESPACE

class Ui_LeadBankProMainWindow
{
public:
    QAction *actionLog_Window;
    QAction *action_Clear_Logs;
    LeadBankProSimpleUi *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Window;
    QMenu *menuAction;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LeadBankProMainWindow)
    {
        if (LeadBankProMainWindow->objectName().isEmpty())
            LeadBankProMainWindow->setObjectName(QStringLiteral("LeadBankProMainWindow"));
        LeadBankProMainWindow->resize(800, 500);
        LeadBankProMainWindow->setMinimumSize(QSize(800, 500));
        QIcon icon;
        icon.addFile(QStringLiteral(":/data/data/imgdata/128x128.png"), QSize(), QIcon::Normal, QIcon::Off);
        LeadBankProMainWindow->setWindowIcon(icon);
        actionLog_Window = new QAction(LeadBankProMainWindow);
        actionLog_Window->setObjectName(QStringLiteral("actionLog_Window"));
        action_Clear_Logs = new QAction(LeadBankProMainWindow);
        action_Clear_Logs->setObjectName(QStringLiteral("action_Clear_Logs"));
        centralWidget = new LeadBankProSimpleUi(LeadBankProMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LeadBankProMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LeadBankProMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Window = new QMenu(menuBar);
        menu_Window->setObjectName(QStringLiteral("menu_Window"));
        menuAction = new QMenu(menuBar);
        menuAction->setObjectName(QStringLiteral("menuAction"));
        LeadBankProMainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(LeadBankProMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LeadBankProMainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Window->menuAction());
        menuBar->addAction(menuAction->menuAction());
        menu_Window->addAction(actionLog_Window);
        menuAction->addAction(action_Clear_Logs);

        retranslateUi(LeadBankProMainWindow);

        QMetaObject::connectSlotsByName(LeadBankProMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LeadBankProMainWindow)
    {
        LeadBankProMainWindow->setWindowTitle(QApplication::translate("LeadBankProMainWindow", "FB LeadBank Pro", Q_NULLPTR));
        actionLog_Window->setText(QApplication::translate("LeadBankProMainWindow", "Log Window", Q_NULLPTR));
        action_Clear_Logs->setText(QApplication::translate("LeadBankProMainWindow", "&Clear Logs", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("LeadBankProMainWindow", "&File", Q_NULLPTR));
        menu_Window->setTitle(QApplication::translate("LeadBankProMainWindow", "&Window", Q_NULLPTR));
        menuAction->setTitle(QApplication::translate("LeadBankProMainWindow", "Action", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LeadBankProMainWindow: public Ui_LeadBankProMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEADBANKPROMAINWINDOW_H
