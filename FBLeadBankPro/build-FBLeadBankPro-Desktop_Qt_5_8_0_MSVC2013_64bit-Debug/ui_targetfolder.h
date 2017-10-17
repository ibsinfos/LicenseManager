/********************************************************************************
** Form generated from reading UI file 'targetfolder.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARGETFOLDER_H
#define UI_TARGETFOLDER_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TargetFolder
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *targetLabel;
    QLineEdit *targetPathInput;
    QPushButton *browseButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *TargetFolder)
    {
        if (TargetFolder->objectName().isEmpty())
            TargetFolder->setObjectName(QStringLiteral("TargetFolder"));
        TargetFolder->resize(400, 33);
        horizontalLayout = new QHBoxLayout(TargetFolder);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        targetLabel = new QLabel(TargetFolder);
        targetLabel->setObjectName(QStringLiteral("targetLabel"));
        targetLabel->setMinimumSize(QSize(80, 0));
        targetLabel->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(targetLabel);

        targetPathInput = new QLineEdit(TargetFolder);
        targetPathInput->setObjectName(QStringLiteral("targetPathInput"));

        horizontalLayout->addWidget(targetPathInput);

        browseButton = new QPushButton(TargetFolder);
        browseButton->setObjectName(QStringLiteral("browseButton"));

        horizontalLayout->addWidget(browseButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(TargetFolder);

        QMetaObject::connectSlotsByName(TargetFolder);
    } // setupUi

    void retranslateUi(QWidget *TargetFolder)
    {
        TargetFolder->setWindowTitle(QApplication::translate("TargetFolder", "Form", Q_NULLPTR));
        targetLabel->setText(QApplication::translate("TargetFolder", "Target Path", Q_NULLPTR));
        browseButton->setText(QApplication::translate("TargetFolder", "Browse", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TargetFolder: public Ui_TargetFolder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARGETFOLDER_H
