/********************************************************************************
** Form generated from reading UI file 'previewdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWDIALOG_H
#define UI_PREVIEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreviewDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *urlBox;
    QPushButton *goButton;
    QHBoxLayout *horizontalLayout_2;
    QSlider *overlaySlider;
    QLabel *sliderValue;
    QWidget *previewWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *Save;

    void setupUi(QDialog *PreviewDialog)
    {
        if (PreviewDialog->objectName().isEmpty())
            PreviewDialog->setObjectName(QStringLiteral("PreviewDialog"));
        PreviewDialog->resize(594, 422);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/mockpage logo icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        PreviewDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(PreviewDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        urlBox = new QLineEdit(PreviewDialog);
        urlBox->setObjectName(QStringLiteral("urlBox"));
        urlBox->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(urlBox);

        goButton = new QPushButton(PreviewDialog);
        goButton->setObjectName(QStringLiteral("goButton"));

        horizontalLayout->addWidget(goButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        overlaySlider = new QSlider(PreviewDialog);
        overlaySlider->setObjectName(QStringLiteral("overlaySlider"));
        overlaySlider->setMinimum(1);
        overlaySlider->setMaximum(100);
        overlaySlider->setPageStep(1);
        overlaySlider->setValue(1);
        overlaySlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(overlaySlider);

        sliderValue = new QLabel(PreviewDialog);
        sliderValue->setObjectName(QStringLiteral("sliderValue"));

        horizontalLayout_2->addWidget(sliderValue);


        verticalLayout->addLayout(horizontalLayout_2);

        previewWidget = new QWidget(PreviewDialog);
        previewWidget->setObjectName(QStringLiteral("previewWidget"));
        previewWidget->setMinimumSize(QSize(560, 315));
        previewWidget->setMaximumSize(QSize(560, 315));

        verticalLayout->addWidget(previewWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        Save = new QPushButton(PreviewDialog);
        Save->setObjectName(QStringLiteral("Save"));

        horizontalLayout_4->addWidget(Save);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(PreviewDialog);

        QMetaObject::connectSlotsByName(PreviewDialog);
    } // setupUi

    void retranslateUi(QDialog *PreviewDialog)
    {
        PreviewDialog->setWindowTitle(QApplication::translate("PreviewDialog", "Preview", Q_NULLPTR));
        urlBox->setText(QApplication::translate("PreviewDialog", "http://facebook.com", Q_NULLPTR));
        goButton->setText(QApplication::translate("PreviewDialog", "Preview", Q_NULLPTR));
        sliderValue->setText(QString());
        Save->setText(QApplication::translate("PreviewDialog", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PreviewDialog: public Ui_PreviewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWDIALOG_H
