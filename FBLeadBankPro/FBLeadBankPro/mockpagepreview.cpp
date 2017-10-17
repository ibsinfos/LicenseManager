#include "mockpagepreview.h"
#include "ui_mockpagepreview.h"
#include <QPixmap>

MockPagePreview::MockPagePreview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MockPagePreview)
{
    ui->setupUi(this);
}

MockPagePreview::~MockPagePreview()
{
    delete ui;
}

void MockPagePreview::setPreviewImage(const QString &path)
{
    this->ui->previewImage->setText("");
    QPixmap pix(path);
    pix = pix.scaled(560,315);
    this->ui->previewImage->setPixmap(pix);
}
