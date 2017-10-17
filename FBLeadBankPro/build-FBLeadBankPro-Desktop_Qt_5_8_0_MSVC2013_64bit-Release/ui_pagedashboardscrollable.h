/********************************************************************************
** Form generated from reading UI file 'pagedashboardscrollable.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEDASHBOARDSCROLLABLE_H
#define UI_PAGEDASHBOARDSCROLLABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pagedashboard.h"

QT_BEGIN_NAMESPACE

class Ui_PageDashboardScrollable
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    PageDashboard *dashBoard;

    void setupUi(QWidget *PageDashboardScrollable)
    {
        if (PageDashboardScrollable->objectName().isEmpty())
            PageDashboardScrollable->setObjectName(QStringLiteral("PageDashboardScrollable"));
        PageDashboardScrollable->resize(400, 300);
        verticalLayout = new QVBoxLayout(PageDashboardScrollable);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        scrollArea = new QScrollArea(PageDashboardScrollable);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        dashBoard = new PageDashboard();
        dashBoard->setObjectName(QStringLiteral("dashBoard"));
        dashBoard->setGeometry(QRect(0, 0, 396, 296));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dashBoard->sizePolicy().hasHeightForWidth());
        dashBoard->setSizePolicy(sizePolicy);
        scrollArea->setWidget(dashBoard);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(PageDashboardScrollable);

        QMetaObject::connectSlotsByName(PageDashboardScrollable);
    } // setupUi

    void retranslateUi(QWidget *PageDashboardScrollable)
    {
        PageDashboardScrollable->setWindowTitle(QApplication::translate("PageDashboardScrollable", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PageDashboardScrollable: public Ui_PageDashboardScrollable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEDASHBOARDSCROLLABLE_H
