/********************************************************************************
** Form generated from reading UI file 'metashotprofilecreator.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_METASHOTPROFILECREATOR_H
#define UI_METASHOTPROFILECREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MetaShotProfileCreator
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *profileGroupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *profileNameLabel;
    QLineEdit *profileNameInput;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *userAgentgroupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *userAgentLabel;
    QComboBox *userAgentSelectionBox;
    QTextEdit *userAgentInput;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *browserGroupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *browserHeightInput;
    QSpacerItem *horizontalSpacer_4;
    QLabel *bowserWidthLabel;
    QLabel *browserHeightLabel;
    QLineEdit *browserWidthInput;
    QComboBox *comboBox;
    QLabel *label;
    QGroupBox *imageGroupBox;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QSlider *imageQualitySlider;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *imageWidthInput;
    QLineEdit *imageHeightInput;
    QComboBox *comboBox_2;
    QComboBox *imageType;
    QLabel *label_11;
    QGroupBox *imageOverlayBox;
    QGridLayout *gridLayout_3;
    QLineEdit *imageOverlayInput;
    QPushButton *imageOverlaySelect;
    QPushButton *previewButton;
    QLabel *overlayImageLabel;
    QSlider *overlayImageSize;
    QLabel *overlayImageSizeLabel;
    QCheckBox *imageOverlaycheckBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QLineEdit *metaRefresh;
    QLabel *label_7;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *timeOut;
    QLineEdit *totalThreads;
    QLabel *label_3;
    QLabel *label_10;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_12;
    QHBoxLayout *buttonBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *saveButton;

    void setupUi(QDialog *MetaShotProfileCreator)
    {
        if (MetaShotProfileCreator->objectName().isEmpty())
            MetaShotProfileCreator->setObjectName(QStringLiteral("MetaShotProfileCreator"));
        MetaShotProfileCreator->resize(585, 787);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/mockpage logo icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MetaShotProfileCreator->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(MetaShotProfileCreator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        profileGroupBox = new QGroupBox(MetaShotProfileCreator);
        profileGroupBox->setObjectName(QStringLiteral("profileGroupBox"));
        horizontalLayout = new QHBoxLayout(profileGroupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        profileNameLabel = new QLabel(profileGroupBox);
        profileNameLabel->setObjectName(QStringLiteral("profileNameLabel"));

        horizontalLayout->addWidget(profileNameLabel);

        profileNameInput = new QLineEdit(profileGroupBox);
        profileNameInput->setObjectName(QStringLiteral("profileNameInput"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(profileNameInput->sizePolicy().hasHeightForWidth());
        profileNameInput->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(profileNameInput);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(profileGroupBox);

        userAgentgroupBox = new QGroupBox(MetaShotProfileCreator);
        userAgentgroupBox->setObjectName(QStringLiteral("userAgentgroupBox"));
        userAgentgroupBox->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_2 = new QHBoxLayout(userAgentgroupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        userAgentLabel = new QLabel(userAgentgroupBox);
        userAgentLabel->setObjectName(QStringLiteral("userAgentLabel"));

        horizontalLayout_2->addWidget(userAgentLabel);

        userAgentSelectionBox = new QComboBox(userAgentgroupBox);
        userAgentSelectionBox->setObjectName(QStringLiteral("userAgentSelectionBox"));
        userAgentSelectionBox->setMinimumSize(QSize(150, 0));
        userAgentSelectionBox->setMaximumSize(QSize(500, 16777215));

        horizontalLayout_2->addWidget(userAgentSelectionBox);

        userAgentInput = new QTextEdit(userAgentgroupBox);
        userAgentInput->setObjectName(QStringLiteral("userAgentInput"));
        userAgentInput->setMaximumSize(QSize(16777215, 100));

        horizontalLayout_2->addWidget(userAgentInput);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(userAgentgroupBox);

        browserGroupBox = new QGroupBox(MetaShotProfileCreator);
        browserGroupBox->setObjectName(QStringLiteral("browserGroupBox"));
        gridLayout_2 = new QGridLayout(browserGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        browserHeightInput = new QLineEdit(browserGroupBox);
        browserHeightInput->setObjectName(QStringLiteral("browserHeightInput"));
        browserHeightInput->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(browserHeightInput, 2, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 5, 1, 1);

        bowserWidthLabel = new QLabel(browserGroupBox);
        bowserWidthLabel->setObjectName(QStringLiteral("bowserWidthLabel"));

        gridLayout_2->addWidget(bowserWidthLabel, 1, 0, 1, 1);

        browserHeightLabel = new QLabel(browserGroupBox);
        browserHeightLabel->setObjectName(QStringLiteral("browserHeightLabel"));

        gridLayout_2->addWidget(browserHeightLabel, 2, 0, 1, 1);

        browserWidthInput = new QLineEdit(browserGroupBox);
        browserWidthInput->setObjectName(QStringLiteral("browserWidthInput"));
        browserWidthInput->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(browserWidthInput, 1, 2, 1, 1);

        comboBox = new QComboBox(browserGroupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 0, 2, 1, 1);

        label = new QLabel(browserGroupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addWidget(browserGroupBox);

        imageGroupBox = new QGroupBox(MetaShotProfileCreator);
        imageGroupBox->setObjectName(QStringLiteral("imageGroupBox"));
        gridLayout = new QGridLayout(imageGroupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_8 = new QLabel(imageGroupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 1, 1, 1);

        imageQualitySlider = new QSlider(imageGroupBox);
        imageQualitySlider->setObjectName(QStringLiteral("imageQualitySlider"));
        imageQualitySlider->setMinimum(1);
        imageQualitySlider->setMaximum(100);
        imageQualitySlider->setPageStep(1);
        imageQualitySlider->setValue(75);
        imageQualitySlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(imageQualitySlider, 5, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 4, 3, 1, 1);

        label_5 = new QLabel(imageGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        label_4 = new QLabel(imageGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        label_6 = new QLabel(imageGroupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 1, 1, 1);

        imageWidthInput = new QLineEdit(imageGroupBox);
        imageWidthInput->setObjectName(QStringLiteral("imageWidthInput"));
        sizePolicy.setHeightForWidth(imageWidthInput->sizePolicy().hasHeightForWidth());
        imageWidthInput->setSizePolicy(sizePolicy);
        imageWidthInput->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(imageWidthInput, 3, 2, 1, 1);

        imageHeightInput = new QLineEdit(imageGroupBox);
        imageHeightInput->setObjectName(QStringLiteral("imageHeightInput"));
        imageHeightInput->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(imageHeightInput, 4, 2, 1, 1);

        comboBox_2 = new QComboBox(imageGroupBox);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 2, 2, 1, 1);

        imageType = new QComboBox(imageGroupBox);
        imageType->setObjectName(QStringLiteral("imageType"));
        imageType->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(imageType, 1, 2, 1, 1);

        label_11 = new QLabel(imageGroupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 2, 1, 1, 1);


        verticalLayout->addWidget(imageGroupBox);

        imageOverlayBox = new QGroupBox(MetaShotProfileCreator);
        imageOverlayBox->setObjectName(QStringLiteral("imageOverlayBox"));
        gridLayout_3 = new QGridLayout(imageOverlayBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        imageOverlayInput = new QLineEdit(imageOverlayBox);
        imageOverlayInput->setObjectName(QStringLiteral("imageOverlayInput"));

        gridLayout_3->addWidget(imageOverlayInput, 0, 1, 1, 1);

        imageOverlaySelect = new QPushButton(imageOverlayBox);
        imageOverlaySelect->setObjectName(QStringLiteral("imageOverlaySelect"));

        gridLayout_3->addWidget(imageOverlaySelect, 0, 2, 1, 1);

        previewButton = new QPushButton(imageOverlayBox);
        previewButton->setObjectName(QStringLiteral("previewButton"));

        gridLayout_3->addWidget(previewButton, 0, 3, 1, 1);

        overlayImageLabel = new QLabel(imageOverlayBox);
        overlayImageLabel->setObjectName(QStringLiteral("overlayImageLabel"));

        gridLayout_3->addWidget(overlayImageLabel, 1, 1, 1, 1);

        overlayImageSize = new QSlider(imageOverlayBox);
        overlayImageSize->setObjectName(QStringLiteral("overlayImageSize"));
        overlayImageSize->setEnabled(true);
        overlayImageSize->setMinimum(1);
        overlayImageSize->setMaximum(100);
        overlayImageSize->setSingleStep(1);
        overlayImageSize->setPageStep(1);
        overlayImageSize->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(overlayImageSize, 2, 1, 1, 1);

        overlayImageSizeLabel = new QLabel(imageOverlayBox);
        overlayImageSizeLabel->setObjectName(QStringLiteral("overlayImageSizeLabel"));

        gridLayout_3->addWidget(overlayImageSizeLabel, 2, 2, 1, 1);

        imageOverlaycheckBox = new QCheckBox(imageOverlayBox);
        imageOverlaycheckBox->setObjectName(QStringLiteral("imageOverlaycheckBox"));

        gridLayout_3->addWidget(imageOverlaycheckBox, 2, 0, 1, 1);


        verticalLayout->addWidget(imageOverlayBox);

        groupBox = new QGroupBox(MetaShotProfileCreator);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        metaRefresh = new QLineEdit(groupBox);
        metaRefresh->setObjectName(QStringLiteral("metaRefresh"));
        metaRefresh->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(metaRefresh, 1, 4, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 0, 4, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 0, 5, 1, 1);

        timeOut = new QLineEdit(groupBox);
        timeOut->setObjectName(QStringLiteral("timeOut"));
        timeOut->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(timeOut, 1, 2, 1, 1);

        totalThreads = new QLineEdit(groupBox);
        totalThreads->setObjectName(QStringLiteral("totalThreads"));
        totalThreads->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(totalThreads, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 0, 2, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(322, 16777215));

        gridLayout_4->addWidget(label_10, 1, 5, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(172, 16777215));

        gridLayout_4->addWidget(label_9, 1, 3, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 1, 6, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_4->addWidget(label_12, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QHBoxLayout();
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonBox->addItem(horizontalSpacer);

        pushButton = new QPushButton(MetaShotProfileCreator);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);

        buttonBox->addWidget(pushButton);

        saveButton = new QPushButton(MetaShotProfileCreator);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        buttonBox->addWidget(saveButton);


        verticalLayout->addLayout(buttonBox);


        retranslateUi(MetaShotProfileCreator);

        QMetaObject::connectSlotsByName(MetaShotProfileCreator);
    } // setupUi

    void retranslateUi(QDialog *MetaShotProfileCreator)
    {
        MetaShotProfileCreator->setWindowTitle(QApplication::translate("MetaShotProfileCreator", "Create New Profile", Q_NULLPTR));
        profileGroupBox->setTitle(QApplication::translate("MetaShotProfileCreator", "Profile", Q_NULLPTR));
        profileNameLabel->setText(QApplication::translate("MetaShotProfileCreator", "Name", Q_NULLPTR));
        userAgentgroupBox->setTitle(QApplication::translate("MetaShotProfileCreator", "User Agent", Q_NULLPTR));
        userAgentLabel->setText(QApplication::translate("MetaShotProfileCreator", "Browser Name", Q_NULLPTR));
        userAgentSelectionBox->clear();
        userAgentSelectionBox->insertItems(0, QStringList()
         << QApplication::translate("MetaShotProfileCreator", "Custom", Q_NULLPTR)
        );
        browserGroupBox->setTitle(QApplication::translate("MetaShotProfileCreator", "Browser", Q_NULLPTR));
        browserHeightInput->setText(QApplication::translate("MetaShotProfileCreator", "720", Q_NULLPTR));
        bowserWidthLabel->setText(QApplication::translate("MetaShotProfileCreator", "Width", Q_NULLPTR));
        browserHeightLabel->setText(QApplication::translate("MetaShotProfileCreator", "Height", Q_NULLPTR));
        browserWidthInput->setText(QApplication::translate("MetaShotProfileCreator", "1280", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MetaShotProfileCreator", "16:9", Q_NULLPTR)
        );
        label->setText(QApplication::translate("MetaShotProfileCreator", "Ratio", Q_NULLPTR));
        imageGroupBox->setTitle(QApplication::translate("MetaShotProfileCreator", "Image", Q_NULLPTR));
        label_8->setText(QApplication::translate("MetaShotProfileCreator", "Type", Q_NULLPTR));
        label_5->setText(QApplication::translate("MetaShotProfileCreator", "Height", Q_NULLPTR));
        label_4->setText(QApplication::translate("MetaShotProfileCreator", "Width", Q_NULLPTR));
        label_6->setText(QApplication::translate("MetaShotProfileCreator", "Quality", Q_NULLPTR));
        imageWidthInput->setText(QApplication::translate("MetaShotProfileCreator", "1280", Q_NULLPTR));
        imageHeightInput->setText(QApplication::translate("MetaShotProfileCreator", "720", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MetaShotProfileCreator", "16:9", Q_NULLPTR)
        );
        imageType->clear();
        imageType->insertItems(0, QStringList()
         << QApplication::translate("MetaShotProfileCreator", "PNG", Q_NULLPTR)
         << QApplication::translate("MetaShotProfileCreator", "JPG", Q_NULLPTR)
        );
        label_11->setText(QApplication::translate("MetaShotProfileCreator", "Ratio", Q_NULLPTR));
        imageOverlayBox->setTitle(QApplication::translate("MetaShotProfileCreator", "Image Overlay", Q_NULLPTR));
        imageOverlaySelect->setText(QApplication::translate("MetaShotProfileCreator", "Browse", Q_NULLPTR));
        previewButton->setText(QApplication::translate("MetaShotProfileCreator", "Preview", Q_NULLPTR));
        overlayImageLabel->setText(QApplication::translate("MetaShotProfileCreator", "Overlay Image Size", Q_NULLPTR));
        overlayImageSizeLabel->setText(QApplication::translate("MetaShotProfileCreator", "25%", Q_NULLPTR));
        imageOverlaycheckBox->setText(QString());
        groupBox->setTitle(QApplication::translate("MetaShotProfileCreator", "Process", Q_NULLPTR));
        metaRefresh->setInputMask(QString());
        metaRefresh->setText(QApplication::translate("MetaShotProfileCreator", "10", Q_NULLPTR));
        label_7->setText(QApplication::translate("MetaShotProfileCreator", "Meta Refresh", Q_NULLPTR));
        label_2->setText(QApplication::translate("MetaShotProfileCreator", "Document", Q_NULLPTR));
        timeOut->setInputMask(QString());
        timeOut->setText(QApplication::translate("MetaShotProfileCreator", "120", Q_NULLPTR));
        totalThreads->setInputMask(QString());
        totalThreads->setText(QApplication::translate("MetaShotProfileCreator", "5", Q_NULLPTR));
        label_3->setText(QApplication::translate("MetaShotProfileCreator", "Timeout", Q_NULLPTR));
        label_10->setText(QApplication::translate("MetaShotProfileCreator", "Sec", Q_NULLPTR));
        label_9->setText(QApplication::translate("MetaShotProfileCreator", "Sec", Q_NULLPTR));
        label_12->setText(QApplication::translate("MetaShotProfileCreator", "Sec", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MetaShotProfileCreator", "Close", Q_NULLPTR));
        saveButton->setText(QApplication::translate("MetaShotProfileCreator", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MetaShotProfileCreator: public Ui_MetaShotProfileCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METASHOTPROFILECREATOR_H
