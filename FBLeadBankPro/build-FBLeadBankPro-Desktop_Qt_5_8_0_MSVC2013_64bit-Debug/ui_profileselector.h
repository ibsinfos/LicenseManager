/********************************************************************************
** Form generated from reading UI file 'profileselector.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILESELECTOR_H
#define UI_PROFILESELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileSelector
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *profileLabel;
    QComboBox *profileList;
    QPushButton *newButton;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QPushButton *refreshButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ProfileSelector)
    {
        if (ProfileSelector->objectName().isEmpty())
            ProfileSelector->setObjectName(QStringLiteral("ProfileSelector"));
        ProfileSelector->resize(632, 44);
        horizontalLayout = new QHBoxLayout(ProfileSelector);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        profileLabel = new QLabel(ProfileSelector);
        profileLabel->setObjectName(QStringLiteral("profileLabel"));
        profileLabel->setMinimumSize(QSize(50, 0));
        profileLabel->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(profileLabel);

        profileList = new QComboBox(ProfileSelector);
        profileList->setObjectName(QStringLiteral("profileList"));
        profileList->setMinimumSize(QSize(220, 0));

        horizontalLayout->addWidget(profileList);

        newButton = new QPushButton(ProfileSelector);
        newButton->setObjectName(QStringLiteral("newButton"));

        horizontalLayout->addWidget(newButton);

        deleteButton = new QPushButton(ProfileSelector);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        editButton = new QPushButton(ProfileSelector);
        editButton->setObjectName(QStringLiteral("editButton"));

        horizontalLayout->addWidget(editButton);

        refreshButton = new QPushButton(ProfileSelector);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));

        horizontalLayout->addWidget(refreshButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(ProfileSelector);

        profileList->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(ProfileSelector);
    } // setupUi

    void retranslateUi(QWidget *ProfileSelector)
    {
        ProfileSelector->setWindowTitle(QApplication::translate("ProfileSelector", "Form", Q_NULLPTR));
        profileLabel->setText(QApplication::translate("ProfileSelector", "Profile", Q_NULLPTR));
        newButton->setText(QApplication::translate("ProfileSelector", "New", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("ProfileSelector", "Delete", Q_NULLPTR));
        editButton->setText(QApplication::translate("ProfileSelector", "Edit", Q_NULLPTR));
        refreshButton->setText(QApplication::translate("ProfileSelector", "Refresh", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProfileSelector: public Ui_ProfileSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILESELECTOR_H
