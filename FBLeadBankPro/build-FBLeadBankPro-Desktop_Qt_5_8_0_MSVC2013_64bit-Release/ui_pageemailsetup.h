/********************************************************************************
** Form generated from reading UI file 'pageemailsetup.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEEMAILSETUP_H
#define UI_PAGEEMAILSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
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

class Ui_PageEmailSetup
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *hostBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *portBox;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *sslRequired;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLineEdit *maxEmailPerDay;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *emailBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *passwordBox;
    QPushButton *showPassword;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *fromEmail;
    QLabel *label_6;
    QLineEdit *emailSubjectBox;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *emailImageWidth;
    QLabel *label_10;
    QLineEdit *emailImageHeight;
    QLabel *label_11;
    QLineEdit *imageLink;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QPlainTextEdit *emailMessageBox;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *saveButton;

    void setupUi(QWidget *PageEmailSetup)
    {
        if (PageEmailSetup->objectName().isEmpty())
            PageEmailSetup->setObjectName(QStringLiteral("PageEmailSetup"));
        PageEmailSetup->resize(537, 461);
        verticalLayout = new QVBoxLayout(PageEmailSetup);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(PageEmailSetup);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(85, 0));

        horizontalLayout_2->addWidget(label);

        hostBox = new QLineEdit(PageEmailSetup);
        hostBox->setObjectName(QStringLiteral("hostBox"));

        horizontalLayout_2->addWidget(hostBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(PageEmailSetup);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(85, 0));

        horizontalLayout->addWidget(label_2);

        portBox = new QLineEdit(PageEmailSetup);
        portBox->setObjectName(QStringLiteral("portBox"));

        horizontalLayout->addWidget(portBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        sslRequired = new QCheckBox(PageEmailSetup);
        sslRequired->setObjectName(QStringLiteral("sslRequired"));

        horizontalLayout_3->addWidget(sslRequired);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        widget = new QWidget(PageEmailSetup);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 30));
        widget->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_9 = new QHBoxLayout(widget);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(100, 0));
        label_7->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_9->addWidget(label_7);

        maxEmailPerDay = new QLineEdit(widget);
        maxEmailPerDay->setObjectName(QStringLiteral("maxEmailPerDay"));
        maxEmailPerDay->setMinimumSize(QSize(100, 0));
        maxEmailPerDay->setMaximumSize(QSize(100, 16777215));
        maxEmailPerDay->setMaxLength(6);

        horizontalLayout_9->addWidget(maxEmailPerDay);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        verticalLayout->addWidget(widget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(PageEmailSetup);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(90, 0));

        horizontalLayout_4->addWidget(label_3);

        emailBox = new QLineEdit(PageEmailSetup);
        emailBox->setObjectName(QStringLiteral("emailBox"));

        horizontalLayout_4->addWidget(emailBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(PageEmailSetup);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(90, 0));

        horizontalLayout_5->addWidget(label_4);

        passwordBox = new QLineEdit(PageEmailSetup);
        passwordBox->setObjectName(QStringLiteral("passwordBox"));
        passwordBox->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(passwordBox);

        showPassword = new QPushButton(PageEmailSetup);
        showPassword->setObjectName(QStringLiteral("showPassword"));

        horizontalLayout_5->addWidget(showPassword);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(PageEmailSetup);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        fromEmail = new QLineEdit(PageEmailSetup);
        fromEmail->setObjectName(QStringLiteral("fromEmail"));

        horizontalLayout_8->addWidget(fromEmail);

        label_6 = new QLabel(PageEmailSetup);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(90, 0));

        horizontalLayout_8->addWidget(label_6);

        emailSubjectBox = new QLineEdit(PageEmailSetup);
        emailSubjectBox->setObjectName(QStringLiteral("emailSubjectBox"));

        horizontalLayout_8->addWidget(emailSubjectBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_8);

        groupBox = new QGroupBox(PageEmailSetup);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 50));
        horizontalLayout_10 = new QHBoxLayout(groupBox);
        horizontalLayout_10->setSpacing(5);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(5, 0, 0, 0);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_10->addWidget(label_9);

        emailImageWidth = new QLineEdit(groupBox);
        emailImageWidth->setObjectName(QStringLiteral("emailImageWidth"));
        emailImageWidth->setMinimumSize(QSize(80, 0));
        emailImageWidth->setMaximumSize(QSize(80, 16777215));
        emailImageWidth->setMaxLength(3);

        horizontalLayout_10->addWidget(emailImageWidth);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_10->addWidget(label_10);

        emailImageHeight = new QLineEdit(groupBox);
        emailImageHeight->setObjectName(QStringLiteral("emailImageHeight"));
        emailImageHeight->setMinimumSize(QSize(80, 0));
        emailImageHeight->setMaximumSize(QSize(80, 16777215));
        emailImageHeight->setMaxLength(3);

        horizontalLayout_10->addWidget(emailImageHeight);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_10->addWidget(label_11);

        imageLink = new QLineEdit(groupBox);
        imageLink->setObjectName(QStringLiteral("imageLink"));

        horizontalLayout_10->addWidget(imageLink);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(PageEmailSetup);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(90, 0));

        horizontalLayout_6->addWidget(label_5);

        emailMessageBox = new QPlainTextEdit(PageEmailSetup);
        emailMessageBox->setObjectName(QStringLiteral("emailMessageBox"));

        horizontalLayout_6->addWidget(emailMessageBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        saveButton = new QPushButton(PageEmailSetup);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout_7->addWidget(saveButton);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(PageEmailSetup);

        QMetaObject::connectSlotsByName(PageEmailSetup);
    } // setupUi

    void retranslateUi(QWidget *PageEmailSetup)
    {
        PageEmailSetup->setWindowTitle(QApplication::translate("PageEmailSetup", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("PageEmailSetup", "HOST", Q_NULLPTR));
        hostBox->setPlaceholderText(QApplication::translate("PageEmailSetup", "SERVER IP OR DOMAIN", Q_NULLPTR));
        label_2->setText(QApplication::translate("PageEmailSetup", "PORT", Q_NULLPTR));
        portBox->setPlaceholderText(QApplication::translate("PageEmailSetup", "PORT OF THE SERVER", Q_NULLPTR));
        sslRequired->setText(QApplication::translate("PageEmailSetup", "SSL Required", Q_NULLPTR));
        label_7->setText(QApplication::translate("PageEmailSetup", "Max. Email/Day", Q_NULLPTR));
        maxEmailPerDay->setText(QApplication::translate("PageEmailSetup", "50", Q_NULLPTR));
        label_3->setText(QApplication::translate("PageEmailSetup", "Username", Q_NULLPTR));
        label_4->setText(QApplication::translate("PageEmailSetup", "Password", Q_NULLPTR));
        showPassword->setText(QApplication::translate("PageEmailSetup", "SHOW", Q_NULLPTR));
        label_8->setText(QApplication::translate("PageEmailSetup", "From", Q_NULLPTR));
        label_6->setText(QApplication::translate("PageEmailSetup", "Subject", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("PageEmailSetup", "Email Image", Q_NULLPTR));
        label_9->setText(QApplication::translate("PageEmailSetup", "Width", Q_NULLPTR));
        emailImageWidth->setInputMask(QString());
        emailImageWidth->setText(QString());
        label_10->setText(QApplication::translate("PageEmailSetup", "Height", Q_NULLPTR));
        emailImageHeight->setInputMask(QString());
        emailImageHeight->setText(QString());
        label_11->setText(QApplication::translate("PageEmailSetup", "Image Link", Q_NULLPTR));
        label_5->setText(QApplication::translate("PageEmailSetup", "Message", Q_NULLPTR));
        saveButton->setText(QApplication::translate("PageEmailSetup", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PageEmailSetup: public Ui_PageEmailSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEEMAILSETUP_H
