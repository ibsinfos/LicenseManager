/********************************************************************************
** Form generated from reading UI file 'pagedashboard.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEDASHBOARD_H
#define UI_PAGEDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "filterwidget.h"
#include "mockpageaction.h"
#include "profileselector.h"
#include "statswidget.h"
#include "targetfolder.h"

QT_BEGIN_NAMESPACE

class Ui_PageDashboard
{
public:
    QVBoxLayout *verticalLayout_3;
    StatsWidget *statsWidget;
    QWidget *pageDashboardTopBar;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    ProfileSelector *profileSelector;
    TargetFolder *targetFolder;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *searchTextBox;
    QPushButton *searchButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *progressSpinner;
    QVBoxLayout *verticalLayout;
    FilterWidget *filterWidget;
    MockPageAction *mockpageAction;
    QTableWidget *leadListTable;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *PageDashboard)
    {
        if (PageDashboard->objectName().isEmpty())
            PageDashboard->setObjectName(QStringLiteral("PageDashboard"));
        PageDashboard->resize(962, 741);
        PageDashboard->setStyleSheet(QLatin1String("QWidget#PageDashboard{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(PageDashboard);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        statsWidget = new StatsWidget(PageDashboard);
        statsWidget->setObjectName(QStringLiteral("statsWidget"));
        statsWidget->setMinimumSize(QSize(0, 150));
        statsWidget->setMaximumSize(QSize(16777215, 150));

        verticalLayout_3->addWidget(statsWidget);

        pageDashboardTopBar = new QWidget(PageDashboard);
        pageDashboardTopBar->setObjectName(QStringLiteral("pageDashboardTopBar"));
        pageDashboardTopBar->setMinimumSize(QSize(0, 130));
        pageDashboardTopBar->setMaximumSize(QSize(16777215, 130));
        pageDashboardTopBar->setStyleSheet(QLatin1String("#pageDashboardTopBar{\n"
"	padding:0px;\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(pageDashboardTopBar);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(1, 1, 1, 1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        profileSelector = new ProfileSelector(pageDashboardTopBar);
        profileSelector->setObjectName(QStringLiteral("profileSelector"));

        verticalLayout_2->addWidget(profileSelector);

        targetFolder = new TargetFolder(pageDashboardTopBar);
        targetFolder->setObjectName(QStringLiteral("targetFolder"));

        verticalLayout_2->addWidget(targetFolder);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        searchTextBox = new QLineEdit(pageDashboardTopBar);
        searchTextBox->setObjectName(QStringLiteral("searchTextBox"));

        horizontalLayout_3->addWidget(searchTextBox);

        searchButton = new QPushButton(pageDashboardTopBar);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        horizontalLayout_3->addWidget(searchButton);

        pauseButton = new QPushButton(pageDashboardTopBar);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setEnabled(false);

        horizontalLayout_3->addWidget(pauseButton);

        stopButton = new QPushButton(pageDashboardTopBar);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setEnabled(false);

        horizontalLayout_3->addWidget(stopButton);

        resetButton = new QPushButton(pageDashboardTopBar);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        horizontalLayout_3->addWidget(resetButton);

        pushButton = new QPushButton(pageDashboardTopBar);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout_2);

        progressSpinner = new QLabel(pageDashboardTopBar);
        progressSpinner->setObjectName(QStringLiteral("progressSpinner"));
        progressSpinner->setMinimumSize(QSize(32, 32));
        progressSpinner->setMaximumSize(QSize(32, 32));

        horizontalLayout_5->addWidget(progressSpinner);


        verticalLayout_3->addWidget(pageDashboardTopBar);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        filterWidget = new FilterWidget(PageDashboard);
        filterWidget->setObjectName(QStringLiteral("filterWidget"));
        filterWidget->setMinimumSize(QSize(0, 195));
        filterWidget->setMaximumSize(QSize(16777215, 195));
        filterWidget->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(filterWidget);

        mockpageAction = new MockPageAction(PageDashboard);
        mockpageAction->setObjectName(QStringLiteral("mockpageAction"));
        mockpageAction->setMinimumSize(QSize(0, 130));
        mockpageAction->setMaximumSize(QSize(16777215, 130));

        verticalLayout->addWidget(mockpageAction);

        leadListTable = new QTableWidget(PageDashboard);
        if (leadListTable->columnCount() < 8)
            leadListTable->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        leadListTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        leadListTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        leadListTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        leadListTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        leadListTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        leadListTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        leadListTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        leadListTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        leadListTable->setObjectName(QStringLiteral("leadListTable"));
        leadListTable->setMinimumSize(QSize(0, 0));
        leadListTable->setContextMenuPolicy(Qt::CustomContextMenu);
        leadListTable->setEditTriggers(QAbstractItemView::DoubleClicked);
        leadListTable->setAlternatingRowColors(true);
        leadListTable->setSelectionMode(QAbstractItemView::NoSelection);
        leadListTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        leadListTable->setShowGrid(true);
        leadListTable->setGridStyle(Qt::SolidLine);
        leadListTable->setCornerButtonEnabled(false);
        leadListTable->horizontalHeader()->setStretchLastSection(true);
        leadListTable->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(leadListTable);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(PageDashboard);

        QMetaObject::connectSlotsByName(PageDashboard);
    } // setupUi

    void retranslateUi(QWidget *PageDashboard)
    {
        PageDashboard->setWindowTitle(QApplication::translate("PageDashboard", "Form", Q_NULLPTR));
        searchTextBox->setPlaceholderText(QApplication::translate("PageDashboard", "Business type", Q_NULLPTR));
        searchButton->setText(QApplication::translate("PageDashboard", "Search", Q_NULLPTR));
        pauseButton->setText(QApplication::translate("PageDashboard", "Pause", Q_NULLPTR));
        stopButton->setText(QApplication::translate("PageDashboard", "Stop", Q_NULLPTR));
        resetButton->setText(QApplication::translate("PageDashboard", "Reset", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("PageDashboard", "Find pages using their id. Ids must be comma seperated for multiple pages", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("PageDashboard", "Find Pages", Q_NULLPTR));
        progressSpinner->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = leadListTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PageDashboard", "Actions", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = leadListTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PageDashboard", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = leadListTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("PageDashboard", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = leadListTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("PageDashboard", "Address", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = leadListTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("PageDashboard", "Phone", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = leadListTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("PageDashboard", "Email", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = leadListTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("PageDashboard", "Facebook", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = leadListTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("PageDashboard", "Website", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PageDashboard: public Ui_PageDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEDASHBOARD_H
