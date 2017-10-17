/********************************************************************************
** Form generated from reading UI file 'logbrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGBROWSER_H
#define UI_LOGBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogBrowser
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *logBrowser;

    void setupUi(QWidget *LogBrowser)
    {
        if (LogBrowser->objectName().isEmpty())
            LogBrowser->setObjectName(QStringLiteral("LogBrowser"));
        LogBrowser->resize(400, 300);
        LogBrowser->setFocusPolicy(Qt::ClickFocus);
        verticalLayout = new QVBoxLayout(LogBrowser);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        logBrowser = new QTextBrowser(LogBrowser);
        logBrowser->setObjectName(QStringLiteral("logBrowser"));

        horizontalLayout->addWidget(logBrowser);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LogBrowser);

        QMetaObject::connectSlotsByName(LogBrowser);
    } // setupUi

    void retranslateUi(QWidget *LogBrowser)
    {
        LogBrowser->setWindowTitle(QApplication::translate("LogBrowser", "Logs", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogBrowser: public Ui_LogBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGBROWSER_H
