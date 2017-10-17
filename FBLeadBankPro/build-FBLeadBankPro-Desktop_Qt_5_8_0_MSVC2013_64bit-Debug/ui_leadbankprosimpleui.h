/********************************************************************************
** Form generated from reading UI file 'leadbankprosimpleui.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEADBANKPROSIMPLEUI_H
#define UI_LEADBANKPROSIMPLEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pagedashboardscrollable.h"
#include "pageemailsetup.h"
#include "pagesetup.h"

QT_BEGIN_NAMESPACE

class Ui_LeadBankProSimpleUi
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *topContentArea;
    QHBoxLayout *horizontalLayout_2;
    QLabel *leadBankProLabel;
    QWidget *mainContentArea;
    QHBoxLayout *horizontalLayout;
    QWidget *leftSideBarLeadBankProSimpleUi;
    QVBoxLayout *verticalLayout_2;
    QPushButton *dashBoardButton;
    QPushButton *setupButton;
    QPushButton *emailSetupButton;
    QPushButton *updatesButton;
    QPushButton *supportButton;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QWidget *contentArea;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *mainStackedWidget;
    PageDashboardScrollable *pageDashboard;
    PageSetup *pageSetup;
    PageEmailSetup *pageEmailSetup;

    void setupUi(QWidget *LeadBankProSimpleUi)
    {
        if (LeadBankProSimpleUi->objectName().isEmpty())
            LeadBankProSimpleUi->setObjectName(QStringLiteral("LeadBankProSimpleUi"));
        LeadBankProSimpleUi->resize(550, 378);
        verticalLayout = new QVBoxLayout(LeadBankProSimpleUi);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topContentArea = new QWidget(LeadBankProSimpleUi);
        topContentArea->setObjectName(QStringLiteral("topContentArea"));
        topContentArea->setMinimumSize(QSize(0, 100));
        topContentArea->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_2 = new QHBoxLayout(topContentArea);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        leadBankProLabel = new QLabel(topContentArea);
        leadBankProLabel->setObjectName(QStringLiteral("leadBankProLabel"));
        leadBankProLabel->setMinimumSize(QSize(0, 100));
        leadBankProLabel->setMaximumSize(QSize(16777215, 100));
        leadBankProLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        leadBankProLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(leadBankProLabel);


        verticalLayout->addWidget(topContentArea);

        mainContentArea = new QWidget(LeadBankProSimpleUi);
        mainContentArea->setObjectName(QStringLiteral("mainContentArea"));
        horizontalLayout = new QHBoxLayout(mainContentArea);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftSideBarLeadBankProSimpleUi = new QWidget(mainContentArea);
        leftSideBarLeadBankProSimpleUi->setObjectName(QStringLiteral("leftSideBarLeadBankProSimpleUi"));
        leftSideBarLeadBankProSimpleUi->setMinimumSize(QSize(150, 0));
        leftSideBarLeadBankProSimpleUi->setMaximumSize(QSize(150, 16777215));
        leftSideBarLeadBankProSimpleUi->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(leftSideBarLeadBankProSimpleUi);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 2, 0);
        dashBoardButton = new QPushButton(leftSideBarLeadBankProSimpleUi);
        dashBoardButton->setObjectName(QStringLiteral("dashBoardButton"));
        dashBoardButton->setStyleSheet(QStringLiteral(""));
        dashBoardButton->setFlat(false);

        verticalLayout_2->addWidget(dashBoardButton);

        setupButton = new QPushButton(leftSideBarLeadBankProSimpleUi);
        setupButton->setObjectName(QStringLiteral("setupButton"));

        verticalLayout_2->addWidget(setupButton);

        emailSetupButton = new QPushButton(leftSideBarLeadBankProSimpleUi);
        emailSetupButton->setObjectName(QStringLiteral("emailSetupButton"));

        verticalLayout_2->addWidget(emailSetupButton);

        updatesButton = new QPushButton(leftSideBarLeadBankProSimpleUi);
        updatesButton->setObjectName(QStringLiteral("updatesButton"));

        verticalLayout_2->addWidget(updatesButton);

        supportButton = new QPushButton(leftSideBarLeadBankProSimpleUi);
        supportButton->setObjectName(QStringLiteral("supportButton"));

        verticalLayout_2->addWidget(supportButton);

        label = new QLabel(leftSideBarLeadBankProSimpleUi);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("    color:black;\n"
"    text-align:left;\n"
"    background-color: #f8f8f8;\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 0px;\n"
"    border-color: beige;\n"
"    font: 15px;\n"
"    padding: 6px;"));

        verticalLayout_2->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 243, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addWidget(leftSideBarLeadBankProSimpleUi);

        contentArea = new QWidget(mainContentArea);
        contentArea->setObjectName(QStringLiteral("contentArea"));
        verticalLayout_3 = new QVBoxLayout(contentArea);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        mainStackedWidget = new QStackedWidget(contentArea);
        mainStackedWidget->setObjectName(QStringLiteral("mainStackedWidget"));
        pageDashboard = new PageDashboardScrollable();
        pageDashboard->setObjectName(QStringLiteral("pageDashboard"));
        mainStackedWidget->addWidget(pageDashboard);
        pageSetup = new PageSetup();
        pageSetup->setObjectName(QStringLiteral("pageSetup"));
        mainStackedWidget->addWidget(pageSetup);
        pageEmailSetup = new PageEmailSetup();
        pageEmailSetup->setObjectName(QStringLiteral("pageEmailSetup"));
        mainStackedWidget->addWidget(pageEmailSetup);

        verticalLayout_3->addWidget(mainStackedWidget);


        horizontalLayout->addWidget(contentArea);


        verticalLayout->addWidget(mainContentArea);


        retranslateUi(LeadBankProSimpleUi);

        QMetaObject::connectSlotsByName(LeadBankProSimpleUi);
    } // setupUi

    void retranslateUi(QWidget *LeadBankProSimpleUi)
    {
        LeadBankProSimpleUi->setWindowTitle(QApplication::translate("LeadBankProSimpleUi", "Form", Q_NULLPTR));
        leadBankProLabel->setText(QString());
        dashBoardButton->setText(QApplication::translate("LeadBankProSimpleUi", "Dashboard", Q_NULLPTR));
        setupButton->setText(QApplication::translate("LeadBankProSimpleUi", "Facebook Setup", Q_NULLPTR));
        emailSetupButton->setText(QApplication::translate("LeadBankProSimpleUi", "Email Setup", Q_NULLPTR));
        updatesButton->setText(QApplication::translate("LeadBankProSimpleUi", "Updates", Q_NULLPTR));
        supportButton->setText(QApplication::translate("LeadBankProSimpleUi", "Support", Q_NULLPTR));
        label->setText(QApplication::translate("LeadBankProSimpleUi", "Version 1.0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LeadBankProSimpleUi: public Ui_LeadBankProSimpleUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEADBANKPROSIMPLEUI_H
