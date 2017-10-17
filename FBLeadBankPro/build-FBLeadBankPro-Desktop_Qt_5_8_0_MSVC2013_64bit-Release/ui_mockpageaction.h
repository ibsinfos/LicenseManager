/********************************************************************************
** Form generated from reading UI file 'mockpageaction.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOCKPAGEACTION_H
#define UI_MOCKPAGEACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MockPageAction
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *mockPageGroupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *generateMockPageCheckBox;
    QCheckBox *sendEmailCheckBox;
    QCheckBox *sendFacebookMessageCheckBox;
    QCheckBox *useWebSiteForMockPage;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *pauseButton;
    QPushButton *resumeButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MockPageAction)
    {
        if (MockPageAction->objectName().isEmpty())
            MockPageAction->setObjectName(QStringLiteral("MockPageAction"));
        MockPageAction->resize(400, 138);
        verticalLayout_3 = new QVBoxLayout(MockPageAction);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        mockPageGroupBox = new QGroupBox(MockPageAction);
        mockPageGroupBox->setObjectName(QStringLiteral("mockPageGroupBox"));
        verticalLayout_2 = new QVBoxLayout(mockPageGroupBox);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        generateMockPageCheckBox = new QCheckBox(mockPageGroupBox);
        generateMockPageCheckBox->setObjectName(QStringLiteral("generateMockPageCheckBox"));
        generateMockPageCheckBox->setChecked(true);

        verticalLayout->addWidget(generateMockPageCheckBox);

        sendEmailCheckBox = new QCheckBox(mockPageGroupBox);
        sendEmailCheckBox->setObjectName(QStringLiteral("sendEmailCheckBox"));

        verticalLayout->addWidget(sendEmailCheckBox);

        sendFacebookMessageCheckBox = new QCheckBox(mockPageGroupBox);
        sendFacebookMessageCheckBox->setObjectName(QStringLiteral("sendFacebookMessageCheckBox"));

        verticalLayout->addWidget(sendFacebookMessageCheckBox);

        useWebSiteForMockPage = new QCheckBox(mockPageGroupBox);
        useWebSiteForMockPage->setObjectName(QStringLiteral("useWebSiteForMockPage"));

        verticalLayout->addWidget(useWebSiteForMockPage);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        startButton = new QPushButton(mockPageGroupBox);
        startButton->setObjectName(QStringLiteral("startButton"));

        horizontalLayout->addWidget(startButton);

        stopButton = new QPushButton(mockPageGroupBox);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        horizontalLayout->addWidget(stopButton);

        pauseButton = new QPushButton(mockPageGroupBox);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        horizontalLayout->addWidget(pauseButton);

        resumeButton = new QPushButton(mockPageGroupBox);
        resumeButton->setObjectName(QStringLiteral("resumeButton"));

        horizontalLayout->addWidget(resumeButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_3->addWidget(mockPageGroupBox);


        retranslateUi(MockPageAction);

        QMetaObject::connectSlotsByName(MockPageAction);
    } // setupUi

    void retranslateUi(QWidget *MockPageAction)
    {
        MockPageAction->setWindowTitle(QApplication::translate("MockPageAction", "Form", Q_NULLPTR));
        mockPageGroupBox->setTitle(QApplication::translate("MockPageAction", "MockPage", Q_NULLPTR));
        generateMockPageCheckBox->setText(QApplication::translate("MockPageAction", "Generate Mock Page", Q_NULLPTR));
        sendEmailCheckBox->setText(QApplication::translate("MockPageAction", "Send email", Q_NULLPTR));
        sendFacebookMessageCheckBox->setText(QApplication::translate("MockPageAction", "Send facebook message", Q_NULLPTR));
        useWebSiteForMockPage->setText(QApplication::translate("MockPageAction", "Use Website URL Image", Q_NULLPTR));
        startButton->setText(QApplication::translate("MockPageAction", "Start", Q_NULLPTR));
        stopButton->setText(QApplication::translate("MockPageAction", "Stop", Q_NULLPTR));
        pauseButton->setText(QApplication::translate("MockPageAction", "Pause", Q_NULLPTR));
        resumeButton->setText(QApplication::translate("MockPageAction", "Resume", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MockPageAction: public Ui_MockPageAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOCKPAGEACTION_H
