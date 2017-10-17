#include "metashotmainwindow.h"
#include "ui_metashotmainwindow.h"

#include <QUrl>
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QFile>
#include <QSettings>
#include <QStatusBar>
#include <QStringList>

#include "metashot.h"

#include "metashotprofilecreator.h"

MetaShotMainWindow::MetaShotMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MetaShotMainWindow)
{
    this->m_pause = false;
    this->m_csvField = QString("URL");
    this->setWindowIcon(QIcon(":/icons/mockpage logo icon.png"));
    this->m_maximumPJSList = 1;
    this->m_progressCount = 0;
    this->m_stop = false;

    ui->setupUi(this);

    this->on_refreshProfileButton_clicked();
    this->ui->targetPathInput->setText(MetaShot::ins()->value("targetPath").toString());

    this->connect(&this->m_progressTimer,SIGNAL(timeout()),this,SLOT(progressReport()));
    this->m_progressTimer.start(500);

    this->enableStartState();
    this->ui->urlTable->setColumnWidth(0,32);

    QPixmap pix;
    pix.load(":/icons/mockpage logo 1024x300.png");
    pix = pix.scaled(341,100,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this->ui->coverImage->setPixmap(pix);
    this->ui->coverImage->setFixedWidth(341);
    this->ui->coverImage->setFixedHeight(100);
}

MetaShotMainWindow::~MetaShotMainWindow()
{
    delete ui;
    this->clearPJSProcessAfterStop();
}

void MetaShotMainWindow::enableStartState()
{
    MetaShotProfile msp(this->ui->profileList->currentText());
    this->m_maximumPJSList = msp.get("totalThreads").toInt();
    if(this->m_maximumPJSList<=0) this->m_maximumPJSList = 1;


    this->ui->pushButton->setEnabled(true);
    this->ui->editProfileButton->setEnabled(true);
    this->ui->profileList->setEnabled(true);
    this->ui->pauseButton->setEnabled(false);

    this->ui->browseButton->setEnabled(true);
    this->ui->targetPathInput->setEnabled(true);
    this->ui->action_Load->setEnabled(true);
    this->ui->addButton->setEnabled(true);
    this->ui->importButton->setEnabled(true);
    this->ui->startButton->setEnabled(true);
    this->ui->actionClear_URL_TABLE->setEnabled(true);
    this->ui->statusBar->showMessage("");
    this->ui->stopButton->setEnabled(false);
}

void MetaShotMainWindow::disbleStartState()
{
    this->ui->pauseButton->setEnabled(true);

    this->ui->pushButton->setEnabled(false);
    this->ui->editProfileButton->setEnabled(false);
    this->ui->profileList->setEnabled(false);


    this->ui->browseButton->setEnabled(false);
    this->ui->targetPathInput->setEnabled(false);

    this->ui->action_Load->setEnabled(false);
    this->ui->addButton->setEnabled(false);
    this->ui->importButton->setEnabled(false);

    this->ui->startButton->setEnabled(false);
    this->ui->actionClear_URL_TABLE->setEnabled(false);
    this->ui->stopButton->setEnabled(true);
}

void MetaShotMainWindow::setProgressMessage()
{
    QString message = QString("Processing row [ ");
    foreach (int i, this->m_renderingList) {
        message.append(QString::number(i+1));
        message.append(",");
    }
    if(message.endsWith(",")){
        message = message.remove(message.length()-1,1);
    }
    message.append(" ]");
    if(this->m_progressCount<5){
        for(int i=0;i<this->m_progressCount;++i){
            message.append(".");
        }
    }
    else{
        this->m_progressCount = 0;
    }

    this->ui->statusBar->showMessage(message);
    ++this->m_progressCount;
}

void MetaShotMainWindow::clearPJSProcessAfterStop()
{
    foreach (PJSObject *obj, this->m_pjsList) {
        QApplication::processEvents();
        obj->stop();
        delete obj;
    }
    this->m_pjsList.clear();
}

void MetaShotMainWindow::clearPJSProcessAfterFinish()
{
    foreach (PJSObject *obj, this->m_pjsList) {
        QApplication::processEvents();
        delete obj;
    }
    this->m_pjsList.clear();

}

void MetaShotMainWindow::clearPJSProcessAfterPause()
{
    foreach (PJSObject *obj, this->m_pjsList) {
        QApplication::processEvents();
        obj->pause();
        delete obj;
    }
    this->m_pjsList.clear();
}

void MetaShotMainWindow::resetState()
{
    this->m_taskCompleted.clear();
    this->ui->urlTable->setRowCount(0);
    this->m_pause = false;
    this->m_stop = false;
    this->m_currentRow = 0;
    this->m_unexpectedPauseList.clear();
}

QStringList MetaShotMainWindow::parseCSV(const QByteArray &data)
{
    QString string = QString(data);
    enum State {Normal, Quote} state = Normal;
    QStringList fields;
    QString value;

    for (int i = 0; i < string.size(); i++)
    {
        QChar current = string.at(i);

        // Normal state
        if (state == Normal)
        {
            // Comma
            if (current == ',')
            {
                // Save field
                fields.append(value);
                value.clear();
            }

            // Double-quote
            else if (current == '"')
                state = Quote;

            // Other character
            else
                value += current;
        }

        // In-quote state
        else if (state == Quote)
        {
            // Another double-quote
            if (current == '"')
            {
                if (i+1 < string.size())
                {
                    QChar next = string.at(i+1);

                    // A double double-quote?
                    if (next == '"')
                    {
                        value += '"';
                        i++;
                    }
                    else
                        state = Normal;
                }
            }

            // Other character
            else
                value += current;
        }
    }
    if (!value.isEmpty())
        fields.append(value);

    return fields;
}

void MetaShotMainWindow::on_action_Exit_triggered()
{
    qApp->quit();
}

void MetaShotMainWindow::on_action_Load_triggered()
{
    this->on_importButton_clicked();
}

void MetaShotMainWindow::on_newProfileButton_clicked()
{
    MetaShotProfileCreator pfc;
    pfc.exec();
    this->on_refreshProfileButton_clicked();
}

void MetaShotMainWindow::on_addButton_clicked()
{
    if(this->ui->urlInput->text().isEmpty())
    {
        QMessageBox::warning(this,"No Url Found!!!","Please enter a valid url with http and \nthen hit Add");
    }
    else{
        this->appendUrlToTable(this->ui->urlInput->text());
    }
}

void MetaShotMainWindow::appendUrlToTable(const QString &url)
{
    QWidget *col1 = new QWidget();
    col1->setToolTip("Pending");

    QLabel *label = new QLabel();
    label->setMaximumSize(16,16);
    label->setScaledContents(true);
    label->setObjectName("ms_status");

    QPixmap pix;
    pix.load(":/icons/red.png");
    pix = pix.scaled(16,16,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    label->setPixmap(pix);

    QVBoxLayout layout(col1);
    layout.addWidget(label);
    layout.setAlignment(Qt::AlignCenter);

    layout.setContentsMargins(0,0,0,0);

    col1->setLayout(&layout);
    //col1->setFixedSize(16,16);

    QTableWidgetItem *col2 = new QTableWidgetItem("Pending");
    QTableWidgetItem *col3 = new QTableWidgetItem(url);
    this->ui->urlTable->insertRow(this->ui->urlTable->rowCount());

    this->ui->urlTable->setCellWidget(this->ui->urlTable->rowCount()-1,0,col1);

    this->ui->urlTable->setItem(this->ui->urlTable->rowCount()-1,1,col2);
    this->ui->urlTable->setItem(this->ui->urlTable->rowCount()-1,2,col3);
    this->ui->urlTable->resizeColumnToContents(1);
    //this->ui->urlTable->setColumnWidth(0,32);
    int w = this->ui->urlTable->columnWidth(0);
    int h = this->ui->urlTable->rowHeight(this->ui->urlTable->rowCount()-1);
    col1->setFixedSize(w,h);

}

void MetaShotMainWindow::on_importButton_clicked()
{
    QString p=QFileDialog::getOpenFileName(this,"Add URL From Text File","","Text Files(*.txt *.csv)");
    if(p.endsWith("csv",Qt::CaseInsensitive)){
        QDialog w;
        w.setWindowFlags( Qt::WindowSystemMenuHint | Qt::WindowTitleHint);
        w.setWindowTitle("Enter CSV Field");

        QLineEdit l;
        l.setFixedWidth(250);

        QPushButton b;
        b.setText("Open");

        QHBoxLayout layout;
        layout.addWidget(&l);

        layout.addWidget(&b);

        w.setLayout(&layout);
        w.connect(&l,SIGNAL(returnPressed()),&w,SLOT(close()));
        w.connect(&b,SIGNAL(clicked(bool)),&w,SLOT(close()));
        w.exec();
        this->m_csvField = l.text();
    }

    if(!p.isEmpty()){
        this->resetState();
        this->clearPJSProcessAfterPause();
        this->ui->urlTable->setRowCount(0);
        QFile f(p);
        bool firstLine = true;
        int indexNumber = 0;
        if(f.open(QIODevice::ReadOnly|QIODevice::Text)){
            while (!f.atEnd()) {
                QByteArray line = f.readLine().replace("\n","");
                QString url;
                //qDebug() << p;

                if(p.endsWith("txt")){
                    url = QLatin1String(line.constData());
                }
                else if(p.endsWith("csv")){
                    QStringList data =  this->parseCSV(line);
                    if(firstLine){
                        if(data.contains(this->m_csvField,Qt::CaseInsensitive))
                        {
                            int i =0;
                            foreach (QString s, data)
                            {
                                if(s.toUpper() == this->m_csvField.toUpper()){
                                    indexNumber = i;
                                    break;
                                }
                                ++i;
                            }
                        }
                        else{
                            break;
                        }

                    }
                    else{
                        url = data.at(indexNumber);
                    }
                }


                if(url.startsWith("http") || url.startsWith("www")){
                    this->appendUrlToTable(url);
                }

                firstLine = false;
            }
            f.close();
        }
    }
}

void MetaShotMainWindow::on_browseButton_clicked()
{
    QString p = QFileDialog::getExistingDirectory(this,"Target path");
    if(!p.isEmpty()){
        MetaShot::ins()->setValue("targetPath",p);
        this->ui->targetPathInput->setText(p);
    }
}

void MetaShotMainWindow::on_profileList_activated(const QString &arg1)
{
    MetaShot::ins()->setValue("currentProfile",arg1);
    MetaShotProfile msp(arg1);
    this->m_maximumPJSList = msp.get("totalThreads").toInt();
    if(this->m_maximumPJSList<=0) this->m_maximumPJSList = 1;

    //qDebug()<< "PROFILE activated";

    while(this->m_pjsList.size()<this->m_maximumPJSList){
        PJSObject *pjs = new PJSObject(this);
        this->connect(pjs,SIGNAL(pjsMessage(int,QString)),this,SLOT(pjsMessage(int,QString)));
        this->m_pjsList.append(pjs);
    }
}

void MetaShotMainWindow::on_profileList_activated(int index)
{
    MetaShot::ins()->setValue("currentProfileIndex",index);
}

void MetaShotMainWindow::on_refreshProfileButton_clicked()
{
    QStringList pList = MetaShot::ins()->profileList();
    while (this->ui->profileList->count()>0){
        this->ui->profileList->removeItem(this->ui->profileList->count()-1);
    }

    this->ui->profileList->addItems(pList);
    int i = MetaShot::ins()->value("currentProfileIndex").toInt();
    if(this->ui->profileList->count()<i) this->ui->profileList->setCurrentIndex(i-1);
    else this->ui->profileList->setCurrentIndex(i);
}

void MetaShotMainWindow::on_editProfileButton_clicked()
{
    MetaShotProfileCreator pfc;
    pfc.loadDataFromProfile(this->ui->profileList->currentText());
    pfc.exec();
    this->on_refreshProfileButton_clicked();
}

void MetaShotMainWindow::on_startButton_clicked()
{
    if(this->ui->targetPathInput->text().isEmpty()){
        QMessageBox::warning(this,"Error","Please set target path");
        return;
    }
    if(this->ui->profileList->count()==0){
        QMessageBox::warning(this,"Error","Please create a new profile");
        return;
    }
    if(this->ui->urlTable->rowCount()==0){
        QMessageBox::warning(this,"Error","Please add or import urls");
        return;
    }
    this->disbleStartState();
    this->m_stop = false;


    //Settings for process
    int r;
    {
        QMutexLocker locker(&this->m_mutex);
        if(!this->m_pause){
            this->m_currentRow = 0;
            r = qMin(this->m_maximumPJSList,this->ui->urlTable->rowCount() - this->m_currentRow);
        }
        else{
            r = qMin(this->m_maximumPJSList,this->m_unexpectedPauseList.size());
        }
    }
    if(!this->m_pause) this->m_taskCompleted.clear();
    QString profile = this->ui->profileList->currentText();

    if(this->m_pause){
        for(int i=0;i<r;++i){
            QApplication::processEvents();
            QMutexLocker locker(&this->m_mutex);
            int row = this->m_unexpectedPauseList.takeFirst();
            QString url = this->ui->urlTable->item(row,2)->text();
            QString target = this->ui->targetPathInput->text();
            if(this->m_pjsList.size()<r){
                PJSObject *pjs = new PJSObject(this);
                this->connect(pjs,SIGNAL(pjsMessage(int,QString)),this,SLOT(pjsMessage(int,QString)));
                this->m_pjsList.append(pjs);
            }
            this->m_pjsList.at(i)->setup(row,i,url,target,profile,false);
        }
    }
    else{
        for(int i=0;i<r;++i){
            QApplication::processEvents();
            int row;
            {
                QMutexLocker locker(&this->m_mutex);
                row = this->m_currentRow;
            }
            QString url = this->ui->urlTable->item(row,2)->text();
            QString target = this->ui->targetPathInput->text();

            if(this->m_pjsList.size()<r){
                PJSObject *pjs = new PJSObject(this);
                this->connect(pjs,SIGNAL(pjsMessage(int,QString)),this,SLOT(pjsMessage(int,QString)));
                this->m_pjsList.append(pjs);
                {
                    QMutexLocker locker(&this->m_mutex);
                    this->m_currentRow++;
                }
            }
            this->m_pjsList.at(i)->setup(row,i,url,target,profile,false);
        }
    }

    //qDebug() << r;
    //qDebug() << this->ui->urlTable->rowCount();

    this->m_pause = false;
}

void MetaShotMainWindow::on_pushButton_clicked()
{
    QString p = this->ui->profileList->currentText();
    if (p=="Default"){
        QMessageBox::warning(this,"Error","Can not delete Default profile");
    }
    else{
        MetaShot::ins()->deleteProfile(p);
        this->on_refreshProfileButton_clicked();
        QMessageBox::information(this,"Success","Profile Removed.");
    }
}

void MetaShotMainWindow::pjsMessage(int index, const QString &message)
{
    if(index<this->ui->urlTable->rowCount()){
        //qDebug() << message;
        if(message.startsWith("rendering",Qt::CaseInsensitive)){
            this->m_renderingList.append(index);
            //qDebug() << this->m_renderingList;
            this->setProgressMessage();
        }
        else{
            if(this->m_renderingList.contains(index)){
                int i =this->m_renderingList.indexOf(index);
                this->m_renderingList.removeAt(i);
            }
        }
        QWidget *col1= this->ui->urlTable->cellWidget(index,0);
        QLabel *label = col1->findChild<QLabel*>("ms_status");
        col1->setToolTip(message);

        QTableWidgetItem *col2 = this->ui->urlTable->item(index,1);
        col2->setText(message);

        QPixmap pix;
        if(message.startsWith("Finished",Qt::CaseInsensitive)){
            pix.load(":/icons/green.png");
        }
        else if(message.startsWith("Rendering",Qt::CaseInsensitive)){
            pix.load(":/icons/yellow.png");
        }
        else if(message.startsWith("Timeout",Qt::CaseInsensitive)){
            pix.load(":/icons/black.png");
        }
        else if(message.startsWith("Failed",Qt::CaseInsensitive)){
            pix.load(":/icons/black.png");
        }
        else if(message.startsWith("Stopped",Qt::CaseInsensitive)){
            pix.load(":/icons/red.png");
        }
        else if(message.startsWith("Paused",Qt::CaseInsensitive)){
            pix.load(":/icons/red.png");
        }


        pix = pix.scaled(16,16,Qt::KeepAspectRatio,Qt::SmoothTransformation);

        label->setPixmap(pix);

        this->ui->urlTable->resizeColumnToContents(1);
    }

    if(this->m_stop) return;
    if(message.startsWith("Finished",Qt::CaseInsensitive) || message.startsWith("TimeOut",Qt::CaseInsensitive) ){
        int row;
        int rowCount;
        bool uPLEmpty=false;
        {
            QMutexLocker locker(&this->m_mutex);
            if(this->m_unexpectedPauseList.isEmpty()){
                row = this->m_currentRow++;
            }
            this->m_taskCompleted.append(index);
            rowCount = this->ui->urlTable->rowCount();
            uPLEmpty = this->m_unexpectedPauseList.empty();
        }

        if(row<rowCount){
            QString url;
            int nrow;
            if(uPLEmpty){
                nrow = row;
                url = this->ui->urlTable->item(row,2)->text();
            }
            else{
                nrow = this->m_unexpectedPauseList.takeFirst();
                url = this->ui->urlTable->item(nrow,2)->text();
            }
            QString target = this->ui->targetPathInput->text();
            QString profile = this->ui->profileList->currentText();

            PJSObject *pjs = dynamic_cast<PJSObject*>(this->sender());
            pjs->setup(nrow,pjs->serialNumber(),url,target,profile);
        }

        if(this->m_taskCompleted.size()==this->ui->urlTable->rowCount()){
            this->enableStartState();
            this->clearPJSProcessAfterFinish();
            QMessageBox::information(this,"Task Finished","All task complete");
        }

        //qDebug() << this->m_taskCompleted;
    }
}

void MetaShotMainWindow::on_actionClear_URL_TABLE_triggered()
{
    if(this->ui->startButton->isEnabled()){
        this->ui->urlTable->setRowCount(0);
    }
}

void MetaShotMainWindow::progressReport()
{
    if(!this->ui->startButton->isEnabled()){
        this->setProgressMessage();
    }
}

void MetaShotMainWindow::on_stopButton_clicked()
{
    this->m_stop = true;
    this->clearPJSProcessAfterStop();
    this->enableStartState();
}

void MetaShotMainWindow::on_supportButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("http://support.philkasik.com")));
}

void MetaShotMainWindow::on_pauseButton_clicked()
{
    this->m_pause = true;
    {
        QMutexLocker locker(&this->m_mutex);
        foreach (PJSObject *ob, this->m_pjsList) {
            if(!this->m_unexpectedPauseList.contains(ob->index())){
                if(!ob->isFinished()){
                    this->m_unexpectedPauseList.append(ob->index());
                    //qDebug() << ob->index();
                }
            }
        }
    }
    this->clearPJSProcessAfterPause();
    this->enableStartState();
}
