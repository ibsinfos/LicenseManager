/********************************************************************************
** Form generated from reading UI file 'actionwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIONWIDGET_H
#define UI_ACTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActionWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QCheckBox *selectRowCheckBox;
    QLabel *mockPageStatus;
    QPushButton *mockPagePreview;
    QPushButton *removeButton;
    QPushButton *facebookMessengerButton;
    QPushButton *emailButton;
    QPushButton *verifiedButton;
    QPushButton *unclaimedButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ActionWidget)
    {
        if (ActionWidget->objectName().isEmpty())
            ActionWidget->setObjectName(QStringLiteral("ActionWidget"));
        ActionWidget->setEnabled(true);
        ActionWidget->resize(561, 32);
        horizontalLayout = new QHBoxLayout(ActionWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 0, 0);
        selectRowCheckBox = new QCheckBox(ActionWidget);
        selectRowCheckBox->setObjectName(QStringLiteral("selectRowCheckBox"));

        horizontalLayout->addWidget(selectRowCheckBox);

        mockPageStatus = new QLabel(ActionWidget);
        mockPageStatus->setObjectName(QStringLiteral("mockPageStatus"));
        mockPageStatus->setMinimumSize(QSize(16, 16));
        mockPageStatus->setMaximumSize(QSize(16, 16));

        horizontalLayout->addWidget(mockPageStatus);

        mockPagePreview = new QPushButton(ActionWidget);
        mockPagePreview->setObjectName(QStringLiteral("mockPagePreview"));

        horizontalLayout->addWidget(mockPagePreview);

        removeButton = new QPushButton(ActionWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        horizontalLayout->addWidget(removeButton);

        facebookMessengerButton = new QPushButton(ActionWidget);
        facebookMessengerButton->setObjectName(QStringLiteral("facebookMessengerButton"));
        facebookMessengerButton->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(facebookMessengerButton->sizePolicy().hasHeightForWidth());
        facebookMessengerButton->setSizePolicy(sizePolicy);
        facebookMessengerButton->setMinimumSize(QSize(0, 0));
        facebookMessengerButton->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(facebookMessengerButton);

        emailButton = new QPushButton(ActionWidget);
        emailButton->setObjectName(QStringLiteral("emailButton"));
        sizePolicy.setHeightForWidth(emailButton->sizePolicy().hasHeightForWidth());
        emailButton->setSizePolicy(sizePolicy);
        emailButton->setMinimumSize(QSize(0, 0));
        emailButton->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(emailButton);

        verifiedButton = new QPushButton(ActionWidget);
        verifiedButton->setObjectName(QStringLiteral("verifiedButton"));

        horizontalLayout->addWidget(verifiedButton);

        unclaimedButton = new QPushButton(ActionWidget);
        unclaimedButton->setObjectName(QStringLiteral("unclaimedButton"));

        horizontalLayout->addWidget(unclaimedButton);

        horizontalSpacer = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(ActionWidget);

        QMetaObject::connectSlotsByName(ActionWidget);
    } // setupUi

    void retranslateUi(QWidget *ActionWidget)
    {
        ActionWidget->setWindowTitle(QApplication::translate("ActionWidget", "Form", Q_NULLPTR));
        selectRowCheckBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        mockPageStatus->setToolTip(QApplication::translate("ActionWidget", "Mockpage status", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        mockPageStatus->setText(QString());
#ifndef QT_NO_TOOLTIP
        mockPagePreview->setToolTip(QApplication::translate("ActionWidget", "Preview MockPage", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        mockPagePreview->setText(QString());
#ifndef QT_NO_TOOLTIP
        removeButton->setToolTip(QApplication::translate("ActionWidget", "Remove the row", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        removeButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        facebookMessengerButton->setToolTip(QApplication::translate("ActionWidget", "Send message using facebook", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        facebookMessengerButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        emailButton->setToolTip(QApplication::translate("ActionWidget", "Send Email", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        emailButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        verifiedButton->setToolTip(QApplication::translate("ActionWidget", "Verified Facebook page", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        verifiedButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        unclaimedButton->setToolTip(QApplication::translate("ActionWidget", "The page has not been claimed by anyone", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        unclaimedButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ActionWidget: public Ui_ActionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONWIDGET_H
