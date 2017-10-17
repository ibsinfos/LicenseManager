/********************************************************************************
** Form generated from reading UI file 'filterwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERWIDGET_H
#define UI_FILTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *nameFilter;
    QLineEdit *addressFilter;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QCheckBox *removeWithoutEmail;
    QCheckBox *removeWithoutAddress;
    QCheckBox *removeWithoutPhoneNumber;
    QCheckBox *removeUnclaimed;
    QHBoxLayout *horizontalLayout;
    QPushButton *filterButton;
    QPushButton *resetButton;
    QPushButton *exportButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *FilterWidget)
    {
        if (FilterWidget->objectName().isEmpty())
            FilterWidget->setObjectName(QStringLiteral("FilterWidget"));
        FilterWidget->resize(400, 141);
        verticalLayout_3 = new QVBoxLayout(FilterWidget);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(FilterWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        nameFilter = new QLineEdit(groupBox);
        nameFilter->setObjectName(QStringLiteral("nameFilter"));

        horizontalLayout_2->addWidget(nameFilter);

        addressFilter = new QLineEdit(groupBox);
        addressFilter->setObjectName(QStringLiteral("addressFilter"));

        horizontalLayout_2->addWidget(addressFilter);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        removeWithoutEmail = new QCheckBox(groupBox);
        removeWithoutEmail->setObjectName(QStringLiteral("removeWithoutEmail"));

        verticalLayout->addWidget(removeWithoutEmail);

        removeWithoutAddress = new QCheckBox(groupBox);
        removeWithoutAddress->setObjectName(QStringLiteral("removeWithoutAddress"));

        verticalLayout->addWidget(removeWithoutAddress);

        removeWithoutPhoneNumber = new QCheckBox(groupBox);
        removeWithoutPhoneNumber->setObjectName(QStringLiteral("removeWithoutPhoneNumber"));

        verticalLayout->addWidget(removeWithoutPhoneNumber);

        removeUnclaimed = new QCheckBox(groupBox);
        removeUnclaimed->setObjectName(QStringLiteral("removeUnclaimed"));

        verticalLayout->addWidget(removeUnclaimed);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        filterButton = new QPushButton(groupBox);
        filterButton->setObjectName(QStringLiteral("filterButton"));

        horizontalLayout->addWidget(filterButton);

        resetButton = new QPushButton(groupBox);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        horizontalLayout->addWidget(resetButton);

        exportButton = new QPushButton(groupBox);
        exportButton->setObjectName(QStringLiteral("exportButton"));

        horizontalLayout->addWidget(exportButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox);


        retranslateUi(FilterWidget);

        QMetaObject::connectSlotsByName(FilterWidget);
    } // setupUi

    void retranslateUi(QWidget *FilterWidget)
    {
        FilterWidget->setWindowTitle(QApplication::translate("FilterWidget", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("FilterWidget", "Filter", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        nameFilter->setToolTip(QApplication::translate("FilterWidget", "Name", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        nameFilter->setPlaceholderText(QApplication::translate("FilterWidget", "Name", Q_NULLPTR));
        addressFilter->setPlaceholderText(QApplication::translate("FilterWidget", "Address", Q_NULLPTR));
        removeWithoutEmail->setText(QApplication::translate("FilterWidget", "Remove without email", Q_NULLPTR));
        removeWithoutAddress->setText(QApplication::translate("FilterWidget", "Remove without address", Q_NULLPTR));
        removeWithoutPhoneNumber->setText(QApplication::translate("FilterWidget", "Remove without phone number", Q_NULLPTR));
        removeUnclaimed->setText(QApplication::translate("FilterWidget", "Remove unclaimed", Q_NULLPTR));
        filterButton->setText(QApplication::translate("FilterWidget", "Filter", Q_NULLPTR));
        resetButton->setText(QApplication::translate("FilterWidget", "Reset", Q_NULLPTR));
        exportButton->setText(QApplication::translate("FilterWidget", "Export", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FilterWidget: public Ui_FilterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERWIDGET_H
