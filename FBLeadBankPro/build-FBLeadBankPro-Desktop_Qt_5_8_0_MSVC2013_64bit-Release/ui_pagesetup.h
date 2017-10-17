/********************************************************************************
** Form generated from reading UI file 'pagesetup.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGESETUP_H
#define UI_PAGESETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageSetup
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelAccessToken;
    QLineEdit *lineEditAccessToken;
    QPushButton *getTokenButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *facebookUser;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *facebookPassword;
    QPushButton *showPassword;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *maxFacebookMessagePerDay;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QPlainTextEdit *facebookMessageText;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *loginToFacebook;
    QPushButton *logoutFromFacebook;
    QPushButton *buttonSave;
    QLabel *connectionMessage;

    void setupUi(QWidget *PageSetup)
    {
        if (PageSetup->objectName().isEmpty())
            PageSetup->setObjectName(QStringLiteral("PageSetup"));
        PageSetup->resize(522, 431);
        verticalLayout = new QVBoxLayout(PageSetup);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelAccessToken = new QLabel(PageSetup);
        labelAccessToken->setObjectName(QStringLiteral("labelAccessToken"));

        horizontalLayout->addWidget(labelAccessToken);

        lineEditAccessToken = new QLineEdit(PageSetup);
        lineEditAccessToken->setObjectName(QStringLiteral("lineEditAccessToken"));
        lineEditAccessToken->setMinimumSize(QSize(180, 0));
        lineEditAccessToken->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(lineEditAccessToken);

        getTokenButton = new QPushButton(PageSetup);
        getTokenButton->setObjectName(QStringLiteral("getTokenButton"));

        horizontalLayout->addWidget(getTokenButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(PageSetup);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        facebookUser = new QLineEdit(PageSetup);
        facebookUser->setObjectName(QStringLiteral("facebookUser"));
        facebookUser->setMinimumSize(QSize(150, 0));
        facebookUser->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_5->addWidget(facebookUser);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(PageSetup);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        facebookPassword = new QLineEdit(PageSetup);
        facebookPassword->setObjectName(QStringLiteral("facebookPassword"));
        facebookPassword->setMinimumSize(QSize(150, 0));
        facebookPassword->setMaximumSize(QSize(150, 16777215));
        facebookPassword->setInputMask(QStringLiteral(""));
        facebookPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(facebookPassword);

        showPassword = new QPushButton(PageSetup);
        showPassword->setObjectName(QStringLiteral("showPassword"));

        horizontalLayout_6->addWidget(showPassword);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_6);

        widget = new QWidget(PageSetup);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 30));
        widget->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(130, 0));
        label_2->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_4->addWidget(label_2);

        maxFacebookMessagePerDay = new QLineEdit(widget);
        maxFacebookMessagePerDay->setObjectName(QStringLiteral("maxFacebookMessagePerDay"));
        maxFacebookMessagePerDay->setMinimumSize(QSize(120, 0));
        maxFacebookMessagePerDay->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_4->addWidget(maxFacebookMessagePerDay);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout->addWidget(widget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(PageSetup);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(150, 0));
        label->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(label);

        facebookMessageText = new QPlainTextEdit(PageSetup);
        facebookMessageText->setObjectName(QStringLiteral("facebookMessageText"));

        horizontalLayout_3->addWidget(facebookMessageText);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        loginToFacebook = new QPushButton(PageSetup);
        loginToFacebook->setObjectName(QStringLiteral("loginToFacebook"));

        horizontalLayout_2->addWidget(loginToFacebook);

        logoutFromFacebook = new QPushButton(PageSetup);
        logoutFromFacebook->setObjectName(QStringLiteral("logoutFromFacebook"));

        horizontalLayout_2->addWidget(logoutFromFacebook);

        buttonSave = new QPushButton(PageSetup);
        buttonSave->setObjectName(QStringLiteral("buttonSave"));

        horizontalLayout_2->addWidget(buttonSave);

        connectionMessage = new QLabel(PageSetup);
        connectionMessage->setObjectName(QStringLiteral("connectionMessage"));

        horizontalLayout_2->addWidget(connectionMessage);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(PageSetup);

        QMetaObject::connectSlotsByName(PageSetup);
    } // setupUi

    void retranslateUi(QWidget *PageSetup)
    {
        PageSetup->setWindowTitle(QApplication::translate("PageSetup", "Form", Q_NULLPTR));
        labelAccessToken->setText(QApplication::translate("PageSetup", "Facebook Access Token", Q_NULLPTR));
        lineEditAccessToken->setPlaceholderText(QApplication::translate("PageSetup", "Paste FB token here", Q_NULLPTR));
        getTokenButton->setText(QApplication::translate("PageSetup", "Get Token", Q_NULLPTR));
        label_3->setText(QApplication::translate("PageSetup", "Facebook username", Q_NULLPTR));
        label_4->setText(QApplication::translate("PageSetup", "Facebook password", Q_NULLPTR));
        showPassword->setText(QApplication::translate("PageSetup", "SHOW", Q_NULLPTR));
        label_2->setText(QApplication::translate("PageSetup", "Max. Message/Day", Q_NULLPTR));
        maxFacebookMessagePerDay->setText(QApplication::translate("PageSetup", "50", Q_NULLPTR));
        label->setText(QApplication::translate("PageSetup", "Facebook Message", Q_NULLPTR));
        loginToFacebook->setText(QApplication::translate("PageSetup", "Login", Q_NULLPTR));
        logoutFromFacebook->setText(QApplication::translate("PageSetup", "Logout", Q_NULLPTR));
        buttonSave->setText(QApplication::translate("PageSetup", "Save", Q_NULLPTR));
        connectionMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PageSetup: public Ui_PageSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGESETUP_H
