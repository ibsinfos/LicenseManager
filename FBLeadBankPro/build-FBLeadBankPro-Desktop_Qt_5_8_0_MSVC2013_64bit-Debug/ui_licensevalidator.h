/********************************************************************************
** Form generated from reading UI file 'licensevalidator.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LICENSEVALIDATOR_H
#define UI_LICENSEVALIDATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LicenseValidator
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *licenseBox;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *productKeyBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *validateButton;
    QLabel *message;

    void setupUi(QWidget *LicenseValidator)
    {
        if (LicenseValidator->objectName().isEmpty())
            LicenseValidator->setObjectName(QStringLiteral("LicenseValidator"));
        LicenseValidator->resize(400, 300);
        verticalLayout = new QVBoxLayout(LicenseValidator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(LicenseValidator);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(33);
        label->setFont(font);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        licenseBox = new QLineEdit(LicenseValidator);
        licenseBox->setObjectName(QStringLiteral("licenseBox"));
        licenseBox->setMaximumSize(QSize(299, 16777215));

        horizontalLayout->addWidget(licenseBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        productKeyBox = new QLineEdit(LicenseValidator);
        productKeyBox->setObjectName(QStringLiteral("productKeyBox"));
        productKeyBox->setMaximumSize(QSize(299, 16777215));
        productKeyBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(productKeyBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        validateButton = new QPushButton(LicenseValidator);
        validateButton->setObjectName(QStringLiteral("validateButton"));
        validateButton->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(validateButton);


        verticalLayout->addLayout(horizontalLayout_3);

        message = new QLabel(LicenseValidator);
        message->setObjectName(QStringLiteral("message"));

        verticalLayout->addWidget(message, 0, Qt::AlignHCenter);


        retranslateUi(LicenseValidator);

        QMetaObject::connectSlotsByName(LicenseValidator);
    } // setupUi

    void retranslateUi(QWidget *LicenseValidator)
    {
        LicenseValidator->setWindowTitle(QApplication::translate("LicenseValidator", "FB LeadBank Pro", Q_NULLPTR));
        label->setText(QApplication::translate("LicenseValidator", "License Validator", Q_NULLPTR));
        licenseBox->setPlaceholderText(QApplication::translate("LicenseValidator", "Please Enter your license", Q_NULLPTR));
        productKeyBox->setPlaceholderText(QApplication::translate("LicenseValidator", "Please enter your product key.", Q_NULLPTR));
        validateButton->setText(QApplication::translate("LicenseValidator", "Validate", Q_NULLPTR));
        message->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LicenseValidator: public Ui_LicenseValidator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LICENSEVALIDATOR_H
