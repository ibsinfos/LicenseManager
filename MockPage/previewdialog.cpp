#include "previewdialog.h"
#include "ui_previewdialog.h"
#include <QPalette>
#include <QPainter>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QDebug>
#include "metashot.h"

PreviewDialog::PreviewDialog(QWidget *parent) :
    QDialog(parent,Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::PreviewDialog)
{
    this->m_finished = false;
    this->m_pjs = new PJSObject(this);
    this->m_pjs->delayOverlayImage();
    this->connect(this->m_pjs,SIGNAL(pjsMessage(int,QString)),this,SLOT(pjsMessage(int,QString)));

    this->m_draw = false;
    ui->setupUi(this);
    ui->previewWidget->installEventFilter(this);

    this->ui->overlaySlider->setEnabled(false);


}

PreviewDialog::~PreviewDialog()
{
    delete ui;
    MetaShot::ins()->cleanTemp();
}

void PreviewDialog::setImage(const QString &pix)
{
    this->m_pix = QPixmap();
    this->m_pix.load(pix);
    this->m_pix = this->m_pix.scaled(560,315,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this->m_draw = true;
}

void PreviewDialog::setPixMap(const QPixmap &pix)
{
    this->m_pix = QPixmap(pix);
    this->m_pix = this->m_pix.scaled(560,315,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this->m_draw = true;
}

void PreviewDialog::setOverlayImageSize(int val)
{
    this->ui->overlaySlider->setValue(val);
    this->ui->sliderValue->setText(QString::number(val)+" %");
}

int PreviewDialog::overlayImageSize()
{
    return this->ui->overlaySlider->value();
}

void PreviewDialog::setPreviewUrl(const QString &url)
{
    this->ui->urlBox->setText(url);
}

void PreviewDialog::load()
{
    this->on_goButton_clicked();
}

void PreviewDialog::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
}

bool PreviewDialog::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == this->ui->previewWidget && event->type() == QEvent::Paint) {
        if(this->m_draw){
            QPainter painter;
            painter.begin(this->ui->previewWidget);
            painter.setPen(Qt::NoPen);
            painter.drawPixmap( QPoint(0,0), this->m_pix );
            return true;
        }
    }
    return false;
}

void PreviewDialog::on_goButton_clicked()
{
    if(this->ui->urlBox->text().isEmpty()){
        QMessageBox::information(this,"Error","Please enter a url");
        return;
    }

    QString url = this->ui->urlBox->text();
    if(!url.startsWith("http")){
        url = "http://"+url;
    }
    MetaShot::ins()->setPreviewUrl(url);

    this->m_pjs->setup(0,1,url,MetaShot::ins()->tempPath(),MetaShot::ins()->tempProfile(),true);
    this->ui->goButton->setEnabled(false);
    this->ui->urlBox->setEnabled(false);
    this->ui->goButton->setText("Please Wait..");
    this->ui->overlaySlider->setEnabled(false);
    this->m_draw = false;

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    this->ui->previewWidget->setAutoFillBackground(true);
    this->ui->previewWidget->setPalette(Pal);
}

void PreviewDialog::pjsMessage(int index, const QString &message)
{
    Q_UNUSED(index);
    qDebug() << message;
    //qDebug() << (message=="Finished");
    if(message.startsWith("Finished",Qt::CaseInsensitive)){
        if(QFile::exists(this->m_pjs->imagePath())){
            this->m_finished = true;
            this->setPixMap(this->m_pjs->paintOverlayImage(this->ui->overlaySlider->value()));
            QPalette Pal(palette());
            Pal.setColor(QPalette::Background, Qt::white);
            this->ui->previewWidget->setAutoFillBackground(true);
            this->ui->previewWidget->setPalette(Pal);


            this->ui->overlaySlider->setEnabled(true);
        }
        else{
            QMessageBox::information(this,"Failed","Failed to show preview");
        }
        this->ui->goButton->setText("Preview");
        this->ui->goButton->setEnabled(true);
        this->ui->urlBox->setEnabled(true);
    }
    else if(message.startsWith("Failed",Qt::CaseInsensitive)){
        this->ui->goButton->setText("Go");
        this->ui->goButton->setEnabled(true);
        this->ui->urlBox->setEnabled(true);
        QMessageBox::information(this,"Failed","Failed to load the url");
    }
    else if(message.startsWith("Timeout",Qt::CaseInsensitive)){
        this->ui->goButton->setText("Go");
        this->ui->goButton->setEnabled(true);
        this->ui->urlBox->setEnabled(true);
        QMessageBox::information(this,"Timeout","Request Timeout");
    }
}

void PreviewDialog::on_overlaySlider_valueChanged(int value)
{
    //qDebug()<<value;
    this->ui->sliderValue->setText(QString::number(value)+" %");
    if(!this->ui->overlaySlider->isEnabled()) return;
    if(this->m_pjs->overlayImagePath().isEmpty()) return;
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    this->ui->previewWidget->setAutoFillBackground(true);
    this->ui->previewWidget->setPalette(Pal);

    if(this->m_finished){
        this->setPixMap(this->m_pjs->paintOverlayImage(value));
        QPalette Pal(palette());
        Pal.setColor(QPalette::Background, Qt::white);
        this->ui->previewWidget->setAutoFillBackground(true);
        this->ui->previewWidget->setPalette(Pal);
    }
}

void PreviewDialog::on_Save_clicked()
{
    this->close();
}
