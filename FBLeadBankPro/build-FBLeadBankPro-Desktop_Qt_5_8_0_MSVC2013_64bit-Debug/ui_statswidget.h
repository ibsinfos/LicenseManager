/********************************************************************************
** Form generated from reading UI file 'statswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATSWIDGET_H
#define UI_STATSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatsWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *totalResultAfterFilter;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *totalMessageSent;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLabel *emailSentToday;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *totalResultFound;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QLabel *facebookMessageSentToday;

    void setupUi(QWidget *StatsWidget)
    {
        if (StatsWidget->objectName().isEmpty())
            StatsWidget->setObjectName(QStringLiteral("StatsWidget"));
        StatsWidget->resize(803, 150);
        StatsWidget->setMinimumSize(QSize(0, 150));
        StatsWidget->setMaximumSize(QSize(16777215, 150));
        verticalLayout_4 = new QVBoxLayout(StatsWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(StatsWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setMaximumSize(QSize(16777215, 150));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 760, 150));
        scrollAreaWidgetContents->setMinimumSize(QSize(760, 150));
        scrollAreaWidgetContents->setMaximumSize(QSize(760, 150));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(150, 150));
        widget_3->setMaximumSize(QSize(150, 150));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(150, 25));
        label_3->setMaximumSize(QSize(150, 25));
        label_3->setStyleSheet(QLatin1String("QLabel{\n"
"    background-color: rgb(0, 0, 0);\n"
"    font: 10pt;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        totalResultAfterFilter = new QLabel(widget_3);
        totalResultAfterFilter->setObjectName(QStringLiteral("totalResultAfterFilter"));
        totalResultAfterFilter->setMinimumSize(QSize(150, 125));
        totalResultAfterFilter->setMaximumSize(QSize(150, 125));
        totalResultAfterFilter->setStyleSheet(QLatin1String("QLabel{\n"
"    background-color: rgb(58, 138, 255);\n"
"    font: 40pt;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        totalResultAfterFilter->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(totalResultAfterFilter);


        gridLayout->addWidget(widget_3, 0, 2, 1, 1);

        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(150, 150));
        widget_2->setMaximumSize(QSize(150, 150));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(150, 25));
        label_2->setMaximumSize(QSize(150, 25));
        label_2->setStyleSheet(QLatin1String("QLabel{\n"
"    background-color: rgb(0, 0, 0);\n"
"    font: 10pt;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        totalMessageSent = new QLabel(widget_2);
        totalMessageSent->setObjectName(QStringLiteral("totalMessageSent"));
        totalMessageSent->setMinimumSize(QSize(150, 125));
        totalMessageSent->setMaximumSize(QSize(150, 125));
        totalMessageSent->setStyleSheet(QLatin1String("QLabel{\n"
"    background-color: rgb(58, 138, 255);\n"
"    font: 40pt;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        totalMessageSent->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(totalMessageSent);


        gridLayout->addWidget(widget_2, 0, 5, 1, 1);

        widget_4 = new QWidget(scrollAreaWidgetContents);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(150, 150));
        widget_4->setMaximumSize(QSize(150, 150));
        verticalLayout_5 = new QVBoxLayout(widget_4);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(150, 25));
        label_4->setMaximumSize(QSize(150, 25));
        label_4->setStyleSheet(QLatin1String("QLabel{\n"
"    background-color: rgb(0, 0, 0);\n"
"    font: 10pt;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_4);

        emailSentToday = new QLabel(widget_4);
        emailSentToday->setObjectName(QStringLiteral("emailSentToday"));
        emailSentToday->setMinimumSize(QSize(150, 125));
        emailSentToday->setMaximumSize(QSize(150, 125));
        emailSentToday->setStyleSheet(QLatin1String("QLabel{\n"
"    background-color: rgb(58, 138, 255);\n"
"    font: 40pt;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        emailSentToday->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(emailSentToday);


        gridLayout->addWidget(widget_4, 0, 3, 1, 1);

        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(150, 150));
        widget->setMaximumSize(QSize(150, 150));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(150, 25));
        label->setMaximumSize(QSize(150, 25));
        label->setStyleSheet(QLatin1String("QLabel{\n"
"    background-color: rgb(0, 0, 0);\n"
"    font: 10pt;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        totalResultFound = new QLabel(widget);
        totalResultFound->setObjectName(QStringLiteral("totalResultFound"));
        totalResultFound->setMinimumSize(QSize(150, 125));
        totalResultFound->setMaximumSize(QSize(150, 125));
        totalResultFound->setStyleSheet(QLatin1String("QLabel{\n"
"    background-color: rgb(58, 138, 255);\n"
"    font: 40pt;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        totalResultFound->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(totalResultFound);


        gridLayout->addWidget(widget, 0, 1, 1, 1);

        widget_5 = new QWidget(scrollAreaWidgetContents);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(150, 150));
        widget_5->setMaximumSize(QSize(150, 150));
        verticalLayout_6 = new QVBoxLayout(widget_5);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(150, 25));
        label_5->setMaximumSize(QSize(150, 25));
        label_5->setStyleSheet(QLatin1String("QLabel{\n"
"    background-color: rgb(0, 0, 0);\n"
"    font: 10pt;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_5);

        facebookMessageSentToday = new QLabel(widget_5);
        facebookMessageSentToday->setObjectName(QStringLiteral("facebookMessageSentToday"));
        facebookMessageSentToday->setStyleSheet(QLatin1String("QLabel{\n"
"    background-color: rgb(58, 138, 255);\n"
"    font: 40pt;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        facebookMessageSentToday->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(facebookMessageSentToday);


        gridLayout->addWidget(widget_5, 0, 4, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);


        retranslateUi(StatsWidget);

        QMetaObject::connectSlotsByName(StatsWidget);
    } // setupUi

    void retranslateUi(QWidget *StatsWidget)
    {
        StatsWidget->setWindowTitle(QApplication::translate("StatsWidget", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("StatsWidget", "Result After Filtering", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        totalResultAfterFilter->setToolTip(QApplication::translate("StatsWidget", "Total result after filtering", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        totalResultAfterFilter->setText(QApplication::translate("StatsWidget", "0", Q_NULLPTR));
        label_2->setText(QApplication::translate("StatsWidget", "FB+EMAIL", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        totalMessageSent->setToolTip(QApplication::translate("StatsWidget", "Total facebook message and email sent in last 24 Hours", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        totalMessageSent->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        totalMessageSent->setText(QApplication::translate("StatsWidget", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        widget_4->setToolTip(QApplication::translate("StatsWidget", "Total email sent is last 24 Hour", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("StatsWidget", "Email Counter", Q_NULLPTR));
        emailSentToday->setText(QApplication::translate("StatsWidget", "0", Q_NULLPTR));
        label->setText(QApplication::translate("StatsWidget", "Total Result", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        totalResultFound->setToolTip(QApplication::translate("StatsWidget", "Total result from search", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        totalResultFound->setText(QApplication::translate("StatsWidget", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        widget_5->setToolTip(QApplication::translate("StatsWidget", "Total facbook message sent in last 24 Hour", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("StatsWidget", "Message Counter", Q_NULLPTR));
        facebookMessageSentToday->setText(QApplication::translate("StatsWidget", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StatsWidget: public Ui_StatsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATSWIDGET_H
