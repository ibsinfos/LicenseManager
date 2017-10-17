#include "targetfolder.h"
#include "ui_targetfolder.h"
#include <QFileDialog>
#include "MockPage/metashot.h"

TargetFolder::TargetFolder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TargetFolder)
{
    ui->setupUi(this);
    this->ui->targetPathInput->setText(MetaShot::ins()->value("targetPath").toString());
}

TargetFolder::~TargetFolder()
{
    delete ui;
}

QString TargetFolder::getTargetPath()
{
    return this->ui->targetPathInput->text();
}

void TargetFolder::on_browseButton_clicked()
{
    QString p = QFileDialog::getExistingDirectory(this,"Target path");
    if(!p.isEmpty()){
        MetaShot::ins()->setValue("targetPath",p);
        this->ui->targetPathInput->setText(p);
    }
}
