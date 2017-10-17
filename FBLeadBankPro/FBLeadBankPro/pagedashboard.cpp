#include "pagedashboard.h"
#include "ui_pagedashboard.h"

#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QCoreApplication>
#include <QDir>
#include <QItemSelectionModel>
#include <QDesktopServices>

#include "actionwidget.h"
#include "logbrowser.h"
#include "textrotator.h"
#include "filterwidget.h"
#include "mockpagepreview.h"
#include "MockPage/metashotprofile.h"
#include "MockPage/metashot.h"

PageDashboard::PageDashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageDashboard)
{
    this->m_removeAction = new QAction(this);
    this->m_sendEmailAction = new QAction(this);
    this->m_sendMessageAction = new QAction(this);

    ui->setupUi(this);


    this->m_dashBoradState = 0;
    this->m_spinProgress.setFileName(":/data/data/gif/one.gif");

    this->ui->progressSpinner->setMovie(&this->m_spinProgress);
    this->ui->progressSpinner->setVisible(false);


    this->connect(&this->m_fbGraphApi,SIGNAL(fbSearchStarted()),this,SLOT(fbSearchStarted()));
    this->connect(&this->m_fbGraphApi,SIGNAL(fbSearchFinished()),this,SLOT(fbSearchFinished()));
    this->connect(&this->m_fbGraphApi,SIGNAL(fbSearchStopped()),this,SLOT(fbSearchStopped()));
    this->connect(&this->m_fbGraphApi,SIGNAL(fbSearchPaused()),this,SLOT(fbSearchPaused()));
    this->connect(&this->m_fbGraphApi,SIGNAL(fbSearchResumed()),this,SLOT(fbSearchResumed()));



    this->connect(&this->m_fbGraphApi,SIGNAL(fbUpdateToken()),this,SLOT(fbUpdateToken()));
    this->connect(&this->m_fbGraphApi,SIGNAL(fbTotalResultFound(int)),this,SLOT(fbTotalResultFound(int)));


    this->connect(&this->m_fbGraphApi,SIGNAL(transmitResult(QVariantMap)),this,SLOT(appendResult(QVariantMap)));

    this->connect(&this->m_nodeJs,SIGNAL(nodeJsStarted()),this,SLOT(messageSendingStarted()));
    this->connect(&this->m_nodeJs,SIGNAL(nodeJsFinished()),this,SLOT(messageSendingFinished()));

    //this->ui->totalResultLabel->setVisible(false);
    //this->ui->filteredResultLabel->setVisible(false);

    this->connect(this->ui->leadListTable,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(tableContextMenu(QPoint)));

    this->m_removeAction->setText("Remove");
    this->m_sendEmailAction->setText("Send Email");
    this->m_sendMessageAction->setText("Send Message");
    this->m_tableMenu.addAction(this->m_removeAction);
    this->m_tableMenu.addAction(this->m_sendEmailAction);
    this->m_tableMenu.addAction(this->m_sendMessageAction);

    this->connect(this->m_removeAction,SIGNAL(triggered()),this,SLOT(removeSelection()));
    this->connect(this->m_sendEmailAction,SIGNAL(triggered()),this,SLOT(sendEmailSelection()));
    this->connect(this->m_sendMessageAction,SIGNAL(triggered()),this,SLOT(sendMessageSelection()));

    this->connect(this->ui->mockpageAction,SIGNAL(mockPageActionStart()),this,SLOT(mockPageActionStart()));
    this->connect(this->ui->mockpageAction,SIGNAL(mockPageActionPause()),this,SLOT(mockPageActionPause()));
    this->connect(this->ui->mockpageAction,SIGNAL(mockPageActionStop()),this,SLOT(mockPageActionStop()));
    this->connect(this->ui->mockpageAction,SIGNAL(mockPageActionResume()),this,SLOT(mockPageActionResume()));



    this->connect(&this->m_threadManager,SIGNAL(updateMessage(int,QString)),this,SLOT(updateMessageFromThread(int,QString)));
    this->connect(&this->m_threadManager,SIGNAL(error(QString)),this,SLOT(errorFromThread(QString)));
    this->connect(&this->m_threadManager,SIGNAL(sendEmail(int)),this,SLOT(sendEmailFromThread(int)));
    this->connect(&this->m_threadManager,SIGNAL(sendFacebookMessage(int)),this,SLOT(sendFacebookMessageFromThread(int)));
    this->connect(&this->m_threadManager, SIGNAL(threadFinished()),this,SLOT(threadFinished()));
    this->connect(&this->m_threadManager,SIGNAL(threadPaused()),this,SLOT(threadPaused()));
    this->connect(&this->m_threadManager,SIGNAL(threadStopped()),this,SLOT(threadStopped()));


    this->connect(&this->m_emTimer,SIGNAL(timeout()),this,SLOT(emTimeout()));
    this->m_emTimer.start(1000);

    this->updateCountrySlectionBox();
    this->ui->leadListTable->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);


    this->ui->pushButton->setHidden(true);
}

PageDashboard::~PageDashboard()
{
    this->m_threadManager.stop();
    delete ui;
}

QTextBrowser *PageDashboard::getLogBrowser()
{
    return LogBrowser::ins()->getLogBrowser();
}

void PageDashboard::addLog(const QString &msg)
{
    LogBrowser::ins()->addLog(msg);
}

void PageDashboard::updateRowNumbering(int start)
{
    for(int i=start;i<this->ui->leadListTable->rowCount();++i){
        ActionWidget *w = dynamic_cast<ActionWidget*>(this->ui->leadListTable->cellWidget(i,0));
        w->setRow(i);
    }
}

void PageDashboard::resizeHeight()
{
    //this->ui->leadListTable->setFixedHeight(this->ui->leadListTable->verticalHeader()->length()+50);
    this->ui->leadListTable->setMinimumHeight(this->ui->leadListTable->verticalHeader()->length()+50);
}

void PageDashboard::updateCountrySlectionBox()
{
    //    //this->ui->countrySelectionBox->clear();
    //    QStringList cList;
    //    cList<<"Any";

    //    QFile f(":/data/data/countries.txt");
    //    if(f.open(QIODevice::ReadOnly)){
    //        while(!f.atEnd()){
    //            QByteArray r = f.readLine();
    //            QString nL(r.constData());
    //            nL = nL.replace("\n","");
    //            cList << nL.split("|").at(1);
    //        }
    //        f.close();
    //    }
    //    this->ui->countrySelectionBox->addItems(cList);
}

void PageDashboard::updateCitySelection()
{
    //    this->ui->citySlectionBox->clear();
    //    QStringList cList;
    //    cList<<"Any";
    //    QString name = this->ui->countrySelectionBox->currentText();
    //    QFile f(":/data/data/city/"+name);
    //    if(f.open(QIODevice::ReadOnly)){
    //        while(!f.atEnd()){
    //            QByteArray r = f.readLine();
    //            QString nL(r.constData());
    //            nL = nL.replace("\n","");
    //            cList << nL;
    //        }
    //        f.close();
    //    }
    //    this->ui->citySlectionBox->addItems(cList);
}

void PageDashboard::on_searchButton_clicked()
{
    if(this->ui->searchTextBox->text().isEmpty()) {
        QMessageBox::information(this,"Error!!!","Please provide a search string");
    }
    else{
          QSettings settings(MetaShot::ins()->appDataRoot()+"/lbp.s",QSettings::IniFormat);
        QString at = settings.value("ACCESS_TOKEN").toString();
        if(at.isEmpty()){
            QMessageBox::information(this,"Error!!!","Please enter an access token and save it on setup page.");
        }
        else{
            QString query = this->ui->searchTextBox->text();
            //            if(this->ui->citySlectionBox->currentIndex()!=0){
            //                query.append(",");
            //                query.append(this->ui->citySlectionBox->currentText());
            //            }

            //            if(this->ui->countrySelectionBox->currentIndex()!=0){
            //                query.append(",");
            //                query.append(this->ui->countrySelectionBox->currentText());
            //            }

            this->m_fbGraphApi.setAccessToken(at);
            this->m_fbGraphApi.searchLead(query,500);
        }
    }
}

void PageDashboard::fbSearchStarted()
{
    //this->ui->totalResultLabel->setVisible(false);
    //this->ui->filteredResultLabel->setVisible(false);

    this->m_filteredResult = 0;
    //this->ui->maxResult->setEnabled(false);
    this->ui->searchTextBox->setEnabled(false);
    this->ui->searchButton->setEnabled(false);
    //    this->ui->countrySelectionBox->setEnabled(false);
    //    this->ui->citySlectionBox->setEnabled(false);
    this->ui->progressSpinner->setVisible(true);

    this->ui->stopButton->setEnabled(true);

    this->m_spinProgress.start();
    this->ui->leadListTable->setRowCount(0);

    this->ui->pauseButton->setText("Pause");
    this->ui->pauseButton->setEnabled(true);
}

void PageDashboard::fbSearchFinished()
{
    //this->ui->maxResult->setEnabled(true);
    this->ui->searchTextBox->setEnabled(true);
    this->ui->searchButton->setEnabled(true);
    //    this->ui->countrySelectionBox->setEnabled(true);
    //    this->ui->citySlectionBox->setEnabled(true);
    this->ui->progressSpinner->setVisible(false);
    this->m_spinProgress.stop();

    this->ui->stopButton->setEnabled(false);
    this->ui->pauseButton->setEnabled(false);
}

void PageDashboard::fbSearchStopped()
{
    this->fbSearchFinished();
}

void PageDashboard::fbSearchPaused()
{
    this->ui->pauseButton->setEnabled(true);
    this->ui->pauseButton->setText("Resume");
}

void PageDashboard::fbSearchResumed()
{
    this->ui->pauseButton->setEnabled(true);
    this->ui->pauseButton->setText("Pause");
}

void PageDashboard::transmitResult(const QVariantMap &data)
{
    qDebug() << data;
}

void PageDashboard::appendResult(const QVariantMap &data)
{
    QStringList serialize = data.value("SERIALIZE").toStringList();

    //Verify location
    //    QVariantMap aLocation = data.value("location").toMap();
    ////    if(this->ui->countrySelectionBox->currentIndex()!=0)
    ////    {
    ////        //this->ui->filteredResultLabel->setVisible(true);
    ////        //this->ui->filteredResultLabel->setText(QString::number(this->m_filteredResult));

    ////        QString country = aLocation.value("country","").toString().toLower();
    ////        if(country!=this->ui->countrySelectionBox->currentText().toLower()){
    ////            return;
    ////        }
    ////        else{
    ////            ++this->m_filteredResult;
    ////            //this->ui->filteredResultLabel->setVisible(true);
    ////            //this->ui->filteredResultLabel->setText(QString::number(this->m_filteredResult));
    ////        }
    ////    }
    ////    else{
    ////        //this->ui->filteredResultLabel->setVisible(false);
    ////    }

    this->ui->leadListTable->insertRow(this->ui->leadListTable->rowCount());



    ActionWidget *actW = new ActionWidget();
    actW->setRow(this->ui->leadListTable->rowCount()-1);
    this->connect(actW,SIGNAL(removeRow(int)),this,SLOT(removeRow(int)));
    this->connect(actW,SIGNAL(sendEmail(int)),this,SLOT(sendEmailFromThread(int)));
    this->connect(actW,SIGNAL(sendFacebookMessage(int)),this,SLOT(sendFacebookMessageFromThread(int)));
    this->connect(actW,SIGNAL(showMockPagePreview(int)),this,SLOT(showMockPagePreview(int)));
    this->connect(actW,SIGNAL(rowSelection(int,bool)),this,SLOT(actionWidgetSelectRow(int,bool)));

    this->ui->leadListTable->setCellWidget(this->ui->leadListTable->rowCount()-1,0,actW);

    int col = 1;
    foreach (const QString &key , serialize) {
        if(key == "is_verified"){
            QString d = data.value(key).toString();
            actW->setVerifiedVisible(d == "Verified");
        }
        else if(key == "is_unclaimed"){
            QString d = data.value(key).toString();
            actW->setUnclaimedVisible(d == "Unclaimed");
        }
        else if(key!="location"){
            QString d = data.value(key).toString();
            //qDebug() <<key<<" " <<d;

            if(key == "emails"){
                if(d.isEmpty()) actW->setEmailEnabled(false);
                else actW->setEmailEnabled(true);
            }

            QTableWidgetItem *item = new QTableWidgetItem(d);
            this->ui->leadListTable->setItem(this->ui->leadListTable->rowCount()-1,col,item);
        }
        else{
            QString address;
            QVariantMap aMap = data.value("location").toMap();
            //qDebug()<<"ADDRESS: " << aMap;

            if(aMap.contains("street")){
                address = address + aMap.value("street").toString()+" ";
            }

            if(aMap.contains("city")){
                address = address + aMap.value("city").toString();
                if(aMap.contains("state")){
                    address = address+" " + aMap.value("state").toString();
                    if(aMap.contains("zip")){
                        address = address +" "+ aMap.value("zip").toString()+" ";
                    }
                    else{
                        address = address+" ";
                    }
                }
                else{
                    if(aMap.contains("zip")){
                        address = address +" "+ aMap.value("zip").toString()+" ";
                    }
                    else{
                        address = address+" ";
                    }
                }
            }
            else{
                if(aMap.contains("state")){
                    address = address + aMap.value("state").toString();
                    if(aMap.contains("zip")){
                        address = address +" "+ aMap.value("zip").toString()+" ";
                    }
                    else{
                        address = address+" ";
                    }
                }
            }

            if(aMap.contains("country")){
                address = address + aMap.value("country").toString();
            }

            QTableWidgetItem *item = new QTableWidgetItem(address);
            this->ui->leadListTable->setItem(this->ui->leadListTable->rowCount()-1,col,item);

        }
        ++col;
    }
    //this->ui->leadListTable->resizeColumnToContents(0);
    //this->ui->leadListTable->resizeRowToContents(0);
    this->ui->leadListTable->setRowHeight(this->ui->leadListTable->rowCount()-1,50);

    //int w = this->ui->leadListTable->columnWidth(0);
    int h = this->ui->leadListTable->rowHeight(this->ui->leadListTable->rowCount()-1);
    this->ui->leadListTable->setColumnWidth(0,250);
    actW->setFixedSize(250,h-2);

    //this->ui->leadListTable->setFixedSize(this->ui->leadListTable->horizontalHeader()->length() + 60, m_table->verticalHeader()->length() + 100);
    this->resizeHeight();
    this->ui->statsWidget->setTotalResult(QString::number(this->ui->leadListTable->rowCount()));
}

void PageDashboard::fbUpdateToken()
{
    //QMessageBox::information(this,"Error!!!","Please update the access token on Facebook Setup page");
}

void PageDashboard::fbTotalResultFound(int number)
{
    Q_UNUSED(number);
    //this->ui->totalResultLabel->setVisible(true);
    //this->ui->totalResultLabel->setText(QString::number(number));
}

void PageDashboard::on_stopButton_clicked()
{
    this->m_fbGraphApi.stopSearch();
}

void PageDashboard::sendFacebookMessage(int row)
{
    QString key = this->ui->leadListTable->item(row,1)->text();
    if(key.isEmpty()) return;
    this->addLog(QString("Sending facebook message to: %1").arg(this->ui->leadListTable->item(row,1)->text()));

        QSettings settings(MetaShot::ins()->appDataRoot()+"/lbp.s",QSettings::IniFormat);
    //qDebug() << "Send Facebook Message:"<<row;
    QString email = settings.value("FB_USER").toString();
    QString password = settings.value("FB_PASS").toString();
    QString to = this->ui->leadListTable->item(row,1)->text();
    QString msg = TextRotator().message(settings.value("FACEBOOK_MSG").toString());

    QString targetPath = this->ui->targetFolder->getTargetPath();


    MetaShotProfile prf = this->ui->profileSelector->getProfile();

    QString img;
    if(!targetPath.isEmpty()){
        img = targetPath+"/"+key+"."+prf.imageType();
    }


    //    qDebug() << "user: "<<email;
    //    qDebug() << "password: " <<password;
    //    qDebug() << "to: "<<to;
    //    qDebug() << "msg: "<<msg;
    QString scriptPath;
    QStringList args;
    args<<email<<password<<to<<msg;

    if(QFile::exists(img)){
        scriptPath = QDir::toNativeSeparators(QCoreApplication::applicationDirPath()+QLatin1String("/")+"facebook2.js");
        args<<img;
    }
    else{
        scriptPath = QDir::toNativeSeparators(QCoreApplication::applicationDirPath()+QLatin1String("/")+"facebook1.js");
    }

    if(!this->m_facebookMap.values().contains(key)){
        QNodeJs *njs = new QNodeJs();
        njs->connect(njs,SIGNAL(status(QString)),this,SLOT(facebookMessageStatus(QString)));
        this->m_facebookMap.insert(njs,key);
        njs->start(scriptPath,args);
    }
}

void PageDashboard::sendEmail(int row)
{
    QString key = this->ui->leadListTable->item(row,1)->text();
    QString to = this->ui->leadListTable->item(row,5)->text();

    QString targetPath = this->ui->targetFolder->getTargetPath();

    MetaShotProfile prf = this->ui->profileSelector->getProfile();
    QString img;
    if(!targetPath.isEmpty()){
        img = targetPath+"/"+key+"."+prf.imageType();
    }
    if(!to.contains("@")) {
        this->addLog("Invalid email "+to);
        return;
    }
    if(to.isEmpty()) return;
    if(key.isEmpty()) return;

    //qDebug() << "Send Email:"<<row;
    this->addLog(QString("Sending EMAIL to: %1").arg(this->ui->leadListTable->item(row,5)->text()));
    //this->addLog("Email sending capability is not possible yet");

        QSettings settings(MetaShot::ins()->appDataRoot()+"/lbp.s",QSettings::IniFormat);
    QString host = settings.value("HOST").toString();
    QString port = settings.value("PORT").toString();
    bool sslRequired = settings.value("SSL_REQUIRED").toBool();
    QString emailBox = settings.value("EMAIL_EMAIL").toString();
    QString passwordBox = settings.value("EMAIL_PASS").toString();
    QString emailSubjectBox = settings.value("EMAIL_SUBJECT").toString();
    QString emailMessageBox = TextRotator().message(settings.value("EMAIL_MSG").toString());
    //qDebug()<<"REAL TEXT: " << settings.value("EMAIL_MSG").toString();
    //qDebug()<<"ROTATED TEXT: " << emailMessageBox;


    QString from = settings.value("FROM_EMAIL").toString();

    emailMessageBox = emailMessageBox.replace("<img>",QString("<img src=\"cid:image1\">"));


    Q_UNUSED(sslRequired);
    //return;

    if(!this->m_emailMap.values().contains(key)){
        Smtp *s = new Smtp(emailBox,passwordBox,host,port.toInt());
        s->connect(s,SIGNAL(status(QString)),this,SLOT(mailStatus(QString)));
        this->m_emailMap.insert(s,key);
        QStringList lst;
        if(QFile::exists(img)){
            lst<<img;
        }
        s->sendMail(from,to,emailSubjectBox,emailMessageBox,lst);
    }
}

void PageDashboard::removeRow(int row)
{
    if(row>=this->ui->leadListTable->rowCount()) return;
    //qDebug() << "removeRow:"<<row;
    ActionWidget *w = dynamic_cast<ActionWidget*>(this->ui->leadListTable->cellWidget(row,0));
    w->deselectRow();
    this->addLog(QString("Removing row: %1").arg(row+1));
    //update row after removing row number
    this->ui->leadListTable->removeRow(row);
    this->addLog(QString("Removed row: %1").arg(row+1));
    this->addLog("Updating row count.");
    this->updateRowNumbering(row);
    this->resizeHeight();
}

void PageDashboard::actionWidgetSelectRow(int row, bool checked)
{
    //qDebug() << checked;
    if(checked){
        int col = this->ui->leadListTable->columnCount();
        QItemSelectionModel *m =  this->ui->leadListTable->selectionModel();
        for(int i=0;i<col;++i){
            m->select(this->ui->leadListTable->model()->index(row,i),QItemSelectionModel::Select);
        }
    }
    else{
        int col = this->ui->leadListTable->columnCount();
        QItemSelectionModel *m =  this->ui->leadListTable->selectionModel();
        for(int i=0;i<col;++i){
            m->select(this->ui->leadListTable->model()->index(row,i),QItemSelectionModel::Deselect);
        }
    }
}

void PageDashboard::rowsState()
{
    for(int i=0;i<this->ui->leadListTable->rowCount();++i){
        ActionWidget *w = dynamic_cast<ActionWidget*>(this->ui->leadListTable->cellWidget(i,0));
        this->actionWidgetSelectRow(i,w->isSelected());
    }
}

void PageDashboard::on_pauseButton_clicked()
{
    if(this->ui->pauseButton->text().toLower() == "pause"){
        this->m_fbGraphApi.pauseSearch();
    }
    else{
        this->m_fbGraphApi.resumeSearch();
    }
}

void PageDashboard::messageSendingStarted()
{
    //qDebug() << "Message sending started";
    this->addLog("Message sending process started.");
}

void PageDashboard::messageSendingFinished()
{
    //qDebug() << "Message sending finished";
    //qDebug() << this->m_nodeJs.finalString();
    this->addLog("Message sending process finished.");
    this->addLog(QString("Final message from message sending process: [[%1]]").arg(this->m_nodeJs.finalString()));
}

void PageDashboard::tableContextMenu(const QPoint &pos)
{
    this->m_tableMenu.exec(this->ui->leadListTable->mapToGlobal(pos));
}

void PageDashboard::removeSelection()
{
    QList<QTableWidgetItem*> d = this->ui->leadListTable->selectedItems();
    QList<int> rows;
    foreach(QTableWidgetItem *i,d){
        if(!rows.contains(i->row())) rows << i->row();
    }
    qDebug() << rows.size();
    std::sort(rows.begin(),rows.end(),std::greater<int>());
    //qDebug() << rows;
    for(int i=0;i<rows.size();++i){
        ActionWidget *w = dynamic_cast<ActionWidget*>(this->ui->leadListTable->cellWidget(i,0));
        w->deselectRow();
        this->ui->leadListTable->removeRow(i);
    }
    this->updateRowNumbering();
    this->resizeHeight();
}

void PageDashboard::sendEmailSelection()
{
    QList<QTableWidgetItem*> d = this->ui->leadListTable->selectedItems();
    if(d.size()==0) return;
    foreach (QTableWidgetItem *i, d) {
        if(!this->m_emailToBeSent.contains(i->row())) this->m_emailToBeSent << i->row();
    }

}

void PageDashboard::sendMessageSelection()
{
    QList<QTableWidgetItem*> d = this->ui->leadListTable->selectedItems();
    if(d.size()==0) return;
    foreach (QTableWidgetItem *i, d) {
        if(!this->m_messageToBeSent.contains(i->row())) this->m_messageToBeSent << i->row();
    }

}

void PageDashboard::filterButton_clicked()
{
    FilterWidget *w = this->ui->filterWidget;
    QString name = w->nameFilterText();
    QString address = w->addressFilterText();

    //qDebug() << name;
    //qDebug() << address;
    //    QString filter = textEdit->text();
    int count = 0;
    for( int i = 0; i < this->ui->leadListTable->rowCount(); ++i )
    {
        bool match = false;
        if(!name.isEmpty() && !address.isEmpty()){
            QTableWidgetItem *itemName = this->ui->leadListTable->item( i, 2 );
            QTableWidgetItem *itemAddress = this->ui->leadListTable->item(i,3);
            if( itemName->text().contains(name) || itemAddress->text().contains(address))
            {
                match = true;
            }
        }
        else if(name.isEmpty() && address.isEmpty()){
            match = true;
        }
        else if (!name.isEmpty() && address.isEmpty()) {
            QTableWidgetItem *itemName = this->ui->leadListTable->item( i, 2 );
            if(itemName->text().contains(name))
            {
                match = true;
            }
        }
        else if(name.isEmpty() && !address.isEmpty()){
            QTableWidgetItem *itemAddress = this->ui->leadListTable->item(i,3);
            if(itemAddress->text().contains(address))
            {
                match = true;
            }
        }
        this->ui->leadListTable->setRowHidden( i, !match );

        if(!this->ui->leadListTable->isRowHidden(i)){
            if(w->isRemoveWithoutAddress()){
                QTableWidgetItem *item = this->ui->leadListTable->item(i,3);//address
                if(item->text().isEmpty()|| item->text().toLower().trimmed() == "address"){
                    this->ui->leadListTable->setRowHidden( i, true );
                }
            }
        }

        if(!this->ui->leadListTable->isRowHidden(i)){
            if(w->isRemoveWithoutPhoneNumber()){
                QTableWidgetItem *item = this->ui->leadListTable->item(i,4);//phone
                if(item->text().isEmpty()){
                    this->ui->leadListTable->setRowHidden( i, true );
                }
            }
        }

        if(!this->ui->leadListTable->isRowHidden(i)){
            if(w->isRemoveWithoutEmail()){
                QTableWidgetItem *item = this->ui->leadListTable->item(i,5);//email
                if(item->text().isEmpty()){
                    this->ui->leadListTable->setRowHidden( i, true );
                }
            }
        }

        if(!this->ui->leadListTable->isRowHidden(i)){
            if(w->isRemoveUnclaimed()){
                ActionWidget *item = dynamic_cast<ActionWidget*>(this->ui->leadListTable->cellWidget(i,0));
                if(item->isUnclaimed()){
                    this->ui->leadListTable->setRowHidden( i, true);
                }
            }
        }

        if(!this->ui->leadListTable->isRowHidden(i)){
            ++count;
        }
    }

    this->ui->statsWidget->setTotalResultAfterFilter(QString::number(count));
    this->resizeHeight();
}

void PageDashboard::resetButton_clicked()
{
    this->filterButton_clicked();
}

void PageDashboard::exportButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "",
                                                    tr("CSV (*.csv)"));

    if(fileName.isEmpty()) return;

    QFile f(fileName);
    if(f.open(QIODevice::WriteOnly| QIODevice::Text)){
        QTextStream out(&f);
        out<< "id,name,location,phone,emails,link,website,is_unclaimed,is_verified"<<"\n";
        out.flush();

        for(int i=0;i<this->ui->leadListTable->rowCount();++i){
            if(!this->ui->leadListTable->isRowHidden(i)){
                for(int j=1;j<=9;++j){
                    if(j<=7){
                        QTableWidgetItem *item = this->ui->leadListTable->item(i,j);
                        out<<"\"" <<item->text().replace("'","\'").replace("\"","\'")<<"\"";
                    }
                    else{
                        ActionWidget *actW =  dynamic_cast<ActionWidget*>(this->ui->leadListTable->cellWidget(i,0));
                        if(j==8){
                            if(actW->isUnclaimed()){
                                out <<"\"True\"";
                            }
                            else{
                                out <<"\"False\"";
                            }
                        }
                        if(j==9){
                            if(actW->isVerified()){
                                out <<"\"True\"";
                            }
                            else{
                                out <<"\"False\"";
                            }
                        }
                    }
                    if(j!=9) out<<",";
                }
                out<<"\n";
                out.flush();
            }
        }
        f.close();
        QMessageBox::information(this,"Success","Data exported to the CSV file.");
    }
}

void PageDashboard::on_filterWidget_exportClicked()
{
    this->exportButton_clicked();
}

void PageDashboard::on_filterWidget_filterClicked()
{
    this->filterButton_clicked();
}

void PageDashboard::on_filterWidget_resetClicked()
{
    this->resetButton_clicked();
}

void PageDashboard::mailStatus(const QString &message)
{
    this->addLog(message);
    Smtp *m = dynamic_cast<Smtp*>(this->sender());


    if(this->m_emailMap.contains(m)){
        QString key = this->m_emailMap.take(m);
        if(message.toLower() == QString("Message sent").toLower()){
            this->addLog("Email Sent to: "+key);
            this->m_dbObject.addEmailLog(key);
        }
    }
    m->deleteLater();
}

void PageDashboard::facebookMessageStatus(const QString &message)
{
    this->addLog(message);
    QNodeJs *njs = dynamic_cast<QNodeJs*>(this->sender());
    if(message.toLower() == QString("finished")){
        if(this->m_facebookMap.contains(njs)){
            QString key = this->m_facebookMap.take(njs);
            this->addLog("Facebook message sent:"+key);
            this->m_dbObject.addFacebookLog(key);
        }
        njs->deleteLater();
    }
}

void PageDashboard::mockPageActionStart()
{

    qDebug() << "mockPageActionStart";

    MetaShotProfile prf = this->ui->profileSelector->getProfile();
    QString profile = prf.profileName();
    QString imageDir = this->ui->targetFolder->getTargetPath();
    this->m_threadManager.clearAll();

    qDebug() << profile;
    qDebug() << imageDir;

    if(profile.isEmpty() || !prf.isProfileExists()) {
        this->addLog("Can not start MockPage, Profile can not be empty");
        QMessageBox::information(this,"Error!!!","Can not start MockPage, Profile can not be empty");
        return;
    }

    if(imageDir.isEmpty()) {
        this->addLog("Can not start MockPage, Target dir is empty");
        QMessageBox::information(this,"Error!!!","Can not start MockPage, Target dir is empty");
        return;
    }

    if(this->ui->leadListTable->rowCount()==0){
        QMessageBox::information(this,"Error!","Can nto start MockPage. No item in the table");
        return;
    }
    else{
        for(int i=0;i<this->ui->leadListTable->rowCount();++i){
            if(!this->ui->leadListTable->isRowHidden(i)){
                QString facebookId = this->ui->leadListTable->item(i,1)->text();
                qDebug() << facebookId;

                QString facebookUrl = this->ui->leadListTable->item(i,6)->text();
                qDebug() << facebookUrl;

                QString website = this->ui->leadListTable->item(i,7)->text();
                    qDebug() << website;

                    if(this->ui->mockpageAction->isUseWebSiteAsMockPage() && !website.isEmpty()){
                        if(!website.startsWith("http")){
                            website = "http://"+website;
                        }
                        this->m_threadManager.addFacebookId(i,facebookId,website);
                    }
                    else{

                        this->m_threadManager.addFacebookId(i,facebookId,facebookUrl);
                    }
                qDebug() << i;


            }
        }
    }


    this->m_threadManager.setProfile(profile);
    this->m_threadManager.setMaxThread(prf.get("totalThreads").toInt());
    this->m_threadManager.setImageDir(imageDir);

    this->m_threadManager.sendEmailEnabled(this->ui->mockpageAction->isEmailChecked());
    this->m_threadManager.sendMessageEnabled(this->ui->mockpageAction->isFacebookMessageChecked());
    this->m_threadManager.generateMockPageEnabled(this->ui->mockpageAction->isMockPageChecked());


    this->m_threadManager.start();
    this->ui->mockpageAction->startState();
    //this->ui->leadListTable->setEnabled(false);
}

void PageDashboard::mockPageActionStop()
{
    this->m_threadManager.stop();
    this->ui->mockpageAction->stopState();
    //this->ui->leadListTable->setEnabled(true);
}

void PageDashboard::mockPageActionPause()
{
    this->m_threadManager.pause();
    this->ui->mockpageAction->pauseState();
    // this->ui->leadListTable->setEnabled(false);
}

void PageDashboard::mockPageActionResume()
{
    //    for(int i=0;i<this->ui->leadListTable->rowCount();++i){
    //        if(!this->ui->leadListTable->isRowHidden(i)){
    //            QString facebookId = this->ui->leadListTable->item(i,1)->text();
    //            this->m_threadManager.addFacebookId(i,facebookId);
    //            qDebug() << i;
    //            qDebug() << facebookId;
    //        }
    //    }

    this->m_threadManager.start();
    this->ui->mockpageAction->resumeState();
}

void PageDashboard::showMockPagePreview(int row)
{
    QString key = this->ui->leadListTable->item(row,1)->text();

    QString targetPath = this->ui->targetFolder->getTargetPath();
    MetaShotProfile prf = this->ui->profileSelector->getProfile();
    QString img;
    if(!targetPath.isEmpty()){
        img = targetPath+"/"+key+"."+prf.imageType();
    }

    if(QFile::exists(img)){
        MockPagePreview pr;
        if(!img.isEmpty()) {
            pr.setPreviewImage(img);
        }
        pr.exec();
    }
    else{
        QMessageBox::information(this,"Error","MockPreview image does not exists");
    }
}

void PageDashboard::updateMessageFromThread(int row, const QString &message)
{
    qDebug() << "Got message from thread";
    qDebug() << row;
    qDebug() << message;

    if(row<this->ui->leadListTable->rowCount()){
        //qDebug() << message;

        ActionWidget *actW = dynamic_cast<ActionWidget*>(this->ui->leadListTable->cellWidget(row,0));

        QString pp;
        if(message.startsWith("Finished",Qt::CaseInsensitive)){
            pp = (":/icons/green.png");
        }
        else if(message.startsWith("Rendering",Qt::CaseInsensitive)){
            pp = (":/icons/yellow.png");
        }
        else if(message.startsWith("Timeout",Qt::CaseInsensitive)){
            pp = (":/icons/black.png");
        }
        else if(message.startsWith("Failed",Qt::CaseInsensitive)){
            pp = (":/icons/black.png");
        }
        else if(message.startsWith("Stopped",Qt::CaseInsensitive)){
            pp = (":/icons/red.png");
        }
        else if(message.startsWith("Paused",Qt::CaseInsensitive)){
            pp = (":/icons/red.png");
        }
        actW->setMockPageStatus(pp,message);
    }

}

void PageDashboard::threadFinished()
{
    qDebug() << "Thread finished";
    this->ui->mockpageAction->stopState();
}
void PageDashboard::threadStopped()
{
    qDebug() << "Thread stopped";
    //this->ui->mockpageAction->stopState();
}

void PageDashboard::threadPaused()
{
    qDebug()<< "Thread paused";
    //this->ui->mockpageAction->pauseState();
}

void PageDashboard::errorFromThread(const QString &message)
{
    this->ui->mockpageAction->stopState();
    QMessageBox::information(this,"Error!!!",message);
}

void PageDashboard::sendEmailFromThread(int row)
{
    if(!this->m_emailToBeSent.contains(row)) this->m_emailToBeSent.append(row);
}

void PageDashboard::sendFacebookMessageFromThread(int row)
{
    if(!this->m_messageToBeSent.contains(row)) this->m_messageToBeSent.append(row);
}

void PageDashboard::emTimeout()
{
    //qDebug() << "email sender";
    //qDebug() << this->m_emailToBeSent.size();
    //qDebug() << this->m_messageToBeSent.size();

    if(this->m_emailMap.isEmpty())
    {
        if(!this->m_emailToBeSent.isEmpty()){
            int row = this->m_emailToBeSent.takeFirst();
            qDebug() << "Email to be sent:"<<row;
            this->sendEmail(row);
        }
    }

    if(this->m_facebookMap.isEmpty()){
        if(!this->m_messageToBeSent.isEmpty()){
            int row = this->m_messageToBeSent.takeFirst();
            qDebug() << "Message to be sent:"<<row;
            this->addLog("Message to be sent row number:"+QString::number(row));
            this->sendFacebookMessage(row);
        }
    }
        QSettings s(MetaShot::ins()->appDataRoot()+"/lbp.s",QSettings::IniFormat);
    int emailLimit = s.value("MAX_FACEBOOK_MSG",QString::number(50)).toInt();
    int facebookLimit = s.value("MAX_EMAIL",QString::number(50)).toInt();

    this->ui->statsWidget->setTotalEmailAndMessageSent(QString::number(this->m_dbObject.totalTextSent24()));

    this->ui->statsWidget->setEmailSentInLast24Hour(this->m_dbObject.totalEmailSentToday(),emailLimit);
    this->ui->statsWidget->setFacebookMessageSentInLast24Hour(this->m_dbObject.totalFacebookMessageSentToday(),facebookLimit);
}

//void PageDashboard::on_countrySelectionBox_activated(int index)
//{
//    Q_UNUSED(index);
//    this->updateCitySelection();
//}

void PageDashboard::on_leadListTable_itemSelectionChanged()
{
    //qDebug() << "Item selection changed";
    this->rowsState();
}

void PageDashboard::on_pushButton_clicked()
{
    QString s = this->ui->searchTextBox->text();
    if(!s.isEmpty()){
        QSettings settings(MetaShot::ins()->appDataRoot()+"/lbp.s",QSettings::IniFormat);
        QString at = settings.value("ACCESS_TOKEN").toString();

        QStringList d = s.split(",");

        //qDebug() << at;
        if(at.isEmpty()){
            QMessageBox::information(this,"Error!!!","Please enter an access token and save it on setup page.");
            return;
        }



        //this->ui->maxResult->setEnabled(false);
        this->ui->searchTextBox->setEnabled(false);
        this->ui->searchButton->setEnabled(false);
        //this->ui->countrySelectionBox->setEnabled(false);
        //this->ui->citySlectionBox->setEnabled(false);
        this->ui->progressSpinner->setVisible(true);

        this->ui->stopButton->setEnabled(true);

        this->m_spinProgress.start();
        this->ui->leadListTable->setRowCount(0);

        this->ui->pauseButton->setText("Pause");
        this->ui->pauseButton->setEnabled(true);
        this->m_fbGraphApi.setAccessToken(at);
        this->m_fbGraphApi.pageEnque(d);
    }
}

void PageDashboard::on_resetButton_clicked()
{
    this->ui->leadListTable->setRowCount(0);
    this->ui->statsWidget->setTotalResult("0");
    this->ui->statsWidget->setTotalResultAfterFilter("0");
}

void PageDashboard::on_leadListTable_cellClicked(int row, int column)
{
    if (column == 6 || column == 7)
    {
        QString url = this->ui->leadListTable->item(row,column)->text();
        if(!url.startsWith("http")){
            url = "http://"+url;
        }
        QDesktopServices::openUrl(url);
    }
}
