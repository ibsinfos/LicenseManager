/********************************************************************************
** Form generated from reading UI file 'mockpagepreview.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOCKPAGEPREVIEW_H
#define UI_MOCKPAGEPREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MockPagePreview
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *previewImage;

    void setupUi(QDialog *MockPagePreview)
    {
        if (MockPagePreview->objectName().isEmpty())
            MockPagePreview->setObjectName(QStringLiteral("MockPagePreview"));
        MockPagePreview->resize(570, 325);
        MockPagePreview->setMinimumSize(QSize(570, 325));
        MockPagePreview->setMaximumSize(QSize(570, 325));
        verticalLayout = new QVBoxLayout(MockPagePreview);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        previewImage = new QLabel(MockPagePreview);
        previewImage->setObjectName(QStringLiteral("previewImage"));
        previewImage->setMinimumSize(QSize(560, 315));
        previewImage->setMaximumSize(QSize(560, 315));

        verticalLayout->addWidget(previewImage);


        retranslateUi(MockPagePreview);

        QMetaObject::connectSlotsByName(MockPagePreview);
    } // setupUi

    void retranslateUi(QDialog *MockPagePreview)
    {
        MockPagePreview->setWindowTitle(QApplication::translate("MockPagePreview", "MockPage Preview", Q_NULLPTR));
        previewImage->setText(QApplication::translate("MockPagePreview", "No image Found", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MockPagePreview: public Ui_MockPagePreview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOCKPAGEPREVIEW_H
