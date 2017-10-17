#include "metashotprofilecreator.h"
#include "ui_metashotprofilecreator.h"
#include "metashot.h"
#include "metashotprofile.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QApplication>
#include <QSize>
#include <QDesktopWidget>
#include <QFile>
#include <QWidget>
#include <QIntValidator>
#include "previewdialog.h"

MetaShotProfileCreator::MetaShotProfileCreator(QWidget *parent) :
    QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::MetaShotProfileCreator)
{


    ui->setupUi(this);
//    this->ui->overlayImageLabel->setVisible(false);
//    this->ui->overlayImageSize->setVisible(false);
//    this->ui->overlayImageSizeLabel->setVisible(false);

    this->ui->pushButton->setVisible(false);

    this->m_uaList.append("Mozilla/5.0 (Macintosh; Intel Mac OS X) AppleWebKit/538.1 (KHTML, like Gecko) Version/8.0 Safari/538.1");
    this->ui->totalThreads->setValidator(new QIntValidator(1,200));
    this->ui->totalThreads->setText("5");

    this->ui->timeOut->setValidator(new QIntValidator(1,1000));
    this->ui->timeOut->setText("120");

    this->ui->metaRefresh->setValidator(new QIntValidator(1,100));
    this->ui->metaRefresh->setText("10");


    this->ui->userAgentInput->setText("Mozilla/5.0 (Macintosh; Intel Mac OS X) AppleWebKit/538.1 (KHTML, like Gecko) Version/8.0 Safari/538.1");
    this->ui->browserWidthInput->setText("1280");
    this->ui->browserHeightInput->setText("720");


    this->loadUAList();

    this->connect(this->ui->userAgentSelectionBox,SIGNAL(currentIndexChanged(int)),this,SLOT(userAgentIndexChanged(int)));
    if(this->ui->userAgentSelectionBox->currentIndex()==0) this->ui->userAgentInput->setVisible(true);
    else this->ui->userAgentInput->setVisible(false);
}

MetaShotProfileCreator::~MetaShotProfileCreator()
{
    delete ui;
}

void MetaShotProfileCreator::loadUAList()
{
    QFile f(":/data/browser.txt");
    if(f.open(QIODevice::ReadOnly|QIODevice::Text)){
        while(!f.atEnd()){
            QByteArray m = f.readLine();
            QString ms = QString(m);
            ms = ms.replace("\n","");
            QStringList msl = ms.split("|||");
            this->m_uaList.append(msl.at(1));
            this->ui->userAgentSelectionBox->addItem(msl.at(0));
        }
        f.close();
    }
}

void MetaShotProfileCreator::loadDataFromProfile(const QString &name)
{
    MetaShotProfile msp(name);
    if(name == QLatin1String("Default")){
        this->ui->profileNameInput->setText(msp.get("profileName").toString());
    }
    else{
        MetaShotProfile msp(name);
        this->ui->profileNameInput->setText(msp.get("profileName").toString());

        this->ui->userAgentInput->setText(msp.get("userAgent").toString());
        this->ui->browserWidthInput->setText(msp.get("browserWidth").toString());
        this->ui->browserHeightInput->setText(msp.get("browserHeight").toString());

        this->ui->imageType->setCurrentIndex(msp.get("imageType").toInt());
        this->ui->imageHeightInput->setText(msp.get("imageHeight").toString());
        this->ui->imageWidthInput->setText(msp.get("imageWidth").toString());
        this->ui->imageQualitySlider->setValue(msp.get("imageQuality").toInt());

        this->ui->imageOverlayInput->setText(msp.get("imageOverlay").toString());
        this->ui->userAgentSelectionBox->setCurrentIndex(msp.get("userAgentIndex").toInt());
        this->ui->imageOverlaycheckBox->setChecked(msp.get("imageOverlayCheckBox").toBool());


        this->ui->overlayImageSize->setValue(msp.get("imageOverlaySize").toInt());


        this->ui->totalThreads->setText( msp.get("totalThreads").toString());
        this->ui->timeOut->setText(msp.get("timeOut").toString());
        this->ui->metaRefresh->setText(msp.get("metaRefresh").toString());
    }
}

void MetaShotProfileCreator::saveProfile(const QString &path, bool isPath)
{

    MetaShotProfile msp(path,isPath);
    msp.set("profileName", this->ui->profileNameInput->text());

    if(this->ui->userAgentSelectionBox->currentIndex()==0){
        msp.set("userAgent", this->ui->userAgentInput->toPlainText());

    }
    else{
        msp.set("userAgent", this->m_uaList.at(this->ui->userAgentSelectionBox->currentIndex()));
    }

    msp.set("userAgentIndex", this->ui->userAgentSelectionBox->currentIndex());

    msp.set("browserWidth", this->ui->browserWidthInput->text());
    msp.set("browserHeight", this->ui->browserHeightInput->text());
    msp.set("imageType", this->ui->imageType->currentIndex());
    msp.set("imageHeight", this->ui->imageHeightInput->text());
    msp.set("imageWidth", this->ui->imageWidthInput->text());

    msp.set("imageOverlayCheckBox", this->ui->imageOverlaycheckBox->isChecked());
    msp.set("imageQuality", this->ui->imageQualitySlider->value());
    msp.set("imageOverlay", this->ui->imageOverlayInput->text());
    msp.set("imageOverlaySize",this->ui->overlayImageSize->value());

    msp.set("totalThreads",this->ui->totalThreads->text());
    msp.set("timeOut",this->ui->timeOut->text());
    msp.set("metaRefresh",this->ui->metaRefresh->text());
}

void MetaShotProfileCreator::on_saveButton_clicked()
{
    if(this->ui->profileNameInput->text().isEmpty()){
        QMessageBox::warning(this,"Error","Please provide a profile name");
        return;
    }

    this->saveProfile(this->ui->profileNameInput->text(),false);

    QMessageBox::information(this,"Success","Profile created");
    if(!this->ui->pushButton->isVisible()){
        this->close();
    }
}

void MetaShotProfileCreator::on_imageOverlaySelect_clicked()
{
    QString p = QFileDialog::getOpenFileName(this,"Overlay Image","","Image(*.png)");
    if(!p.isEmpty()){
        this->ui->imageOverlayInput->setText(p);
    }
}

void MetaShotProfileCreator::userAgentIndexChanged(int index)
{
    if(index==0){
        this->ui->userAgentInput->setVisible(true);
    }
    else{
        this->ui->userAgentInput->setVisible(false);
    }
}

void MetaShotProfileCreator::on_previewButton_clicked()
{
    if(this->ui->imageHeightInput->text().isEmpty() || this->ui->imageWidthInput->text().isEmpty()){
        QMessageBox::information(this,"Error","Please setup image width and height");
        return;
    }
    if(this->ui->imageOverlayInput->text().isEmpty()){
        QMessageBox::information(this,"Error","Please select overlay image");
        return;
    }

    this->saveProfile(MetaShot::ins()->tempProfile(),true);

    PreviewDialog dialog;
    dialog.setOverlayImageSize(this->ui->overlayImageSize->value());
    dialog.setPreviewUrl(MetaShot::ins()->urlForPreview());
    dialog.load();
    dialog.exec();
    this->ui->overlayImageSize->setValue(dialog.overlayImageSize());
}

void MetaShotProfileCreator::on_overlayImageSize_valueChanged(int value)
{
    this->ui->overlayImageSizeLabel->setText(QString("%1 %").arg(value));
}

void MetaShotProfileCreator::on_comboBox_activated(int index)
{
    if(index==0){
        this->ui->browserWidthInput->setText("1280");
        this->ui->browserHeightInput->setText("720");
    }
}

void MetaShotProfileCreator::on_comboBox_2_activated(int index)
{
    if(index==0){
        this->ui->imageWidthInput->setText("1280");
        this->ui->imageHeightInput->setText("720");
    }
}

void MetaShotProfileCreator::on_pushButton_clicked()
{
    this->close();
}
