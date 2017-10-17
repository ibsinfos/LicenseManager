#include "pjsobject.h"
#include <QUrl>
#include <QDir>
#include <QDebug>
#include <QApplication>
#include <QFile>
#include <QImage>
#include <QPixmap>
#include <QPainter>

#include "metashot.h"


PJSObject::PJSObject(QObject *parent) : QObject(parent)
{
    this->m_profile = 0;
    this->m_stop = false;
    this->m_delayOverlayImage = false;
    this->m_pjsExe = QDir::toNativeSeparators( QApplication::applicationDirPath()+"/"+this->m_pjsExe);
    this->m_pjsProcess = 0;

    //this->m_pjsProcess = new QProcess(this);
    //this->connect(this->m_pjsProcess,SIGNAL(started()),this,SLOT(started()));
    //this->connect(this->m_pjsProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finished(int,QProcess::ExitStatus)));

    this->connect(&this->m_timer,SIGNAL(timeout()),this,SLOT(timeOut()));
    this->connect(&this->m_timer,SIGNAL(timeout()),this,SLOT(requestTimeOut()));
}

void PJSObject::setup(int index, int number, const QString &url, const QString &target, const QString &profile, bool isPath)
{
    if(this->m_pjsProcess!=0) delete this->m_pjsProcess;

    this->m_pjsProcess = new QProcess(this);
    this->connect(this->m_pjsProcess,SIGNAL(started()),this,SLOT(started()));
    this->connect(this->m_pjsProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finished(int,QProcess::ExitStatus)));

    this->m_stop = false;
    if(this->m_profile!=0) delete this->m_profile;
    this->m_serialNumber = number;

    this->m_index = index;
    this->m_jsPath = QDir::toNativeSeparators(MetaShot::ins()->jsPath()+QString("/MetaShot-%1-%2.js").arg(MetaShot::ins()->metaId()).arg(number));
    this->m_url = url.startsWith("http")==false?"http://"+url:url;
    this->m_target = QDir::toNativeSeparators(target+"/"+QUrl(this->m_url).host()+QUrl(this->m_url).path().replace("/","-"));

    if(this->m_target.endsWith("-")){
        this->m_target = this->m_target.remove(this->m_target.size()-1,1);
    }
    this->m_profile = new MetaShotProfile(profile,isPath);
#ifdef Q_OS_WIN
    this->m_pjsExe = "pjs.exe";
#elif
    this->m_pjsExe = "pjs";
#endif
    this->m_target = this->m_target.replace("\\","/");

    //qDebug()<< this->m_url;
    this->m_target = this->m_target +"."+this->m_profile->imageType();
    this->m_imagePath = this->m_target;

    //Here we will start the process
    this->refreshJS();
    //emit pjsMessage(this->m_index,"Rendering");


    this->m_pjsProcess->start(this->m_pjsExe,QStringList()<<this->m_jsPath);
    this->m_requestTimer.start(this->m_profile->maxRequestTime()*1000);
}

int PJSObject::serialNumber()
{
    return this->m_serialNumber;
}

int PJSObject::index()
{
    return this->m_index;
}

void PJSObject::delayOverlayImage()
{
    this->m_delayOverlayImage = true;
}

bool PJSObject::isFinished()
{
    return this->m_status.endsWith("Finished",Qt::CaseInsensitive);
}

bool PJSObject::isProcessRunning()
{
    return this->m_pjsProcess->state()==QProcess::Running;
}

QPixmap PJSObject::paintOverlayImage(int value)
{
    QPixmap base(this->m_target), overlay(this->m_profile->imageOverlay());
    int w = overlay.width()* (value/100.0);
    int h = overlay.height()*(value/100.0);
    overlay = overlay.scaled(w,h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    int drX = (base.width()-overlay.width())/2;
    int drY = (base.height()-overlay.height())/2;

    QPixmap result(base.width(), base.height());
    result.fill(Qt::transparent); // force alpha channel
    {
        QPainter painter(&result);
        painter.setRenderHint(QPainter::Antialiasing);

        painter.drawPixmap(0, 0, base);
        painter.drawPixmap(drX, drY, overlay);

        QPainterPath path;
        path.addRect(0,0,result.width(),result.height());
        QPen pen(Qt::black, 5);
        painter.setPen(pen);
        //p.fillPath(path, Qt::red);
        painter.drawPath(path);
    }

    result = result.scaled(this->m_profile->imageWidth().toInt(), this->m_profile->imageHeight().toInt(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    return result;
}

QString PJSObject::imagePath()
{
    return this->m_imagePath;
}

QString PJSObject::overlayImagePath()
{
    return this->m_profile->imageOverlay();
}

PJSObject::~PJSObject()
{
    delete this->m_profile;
    if(QFile::exists(this->m_jsPath)){
        QFile::remove(this->m_jsPath);
    }
}

void PJSObject::stop()
{
    this->m_stop = true;
    if(this->m_pjsProcess->state()==QProcess::Running){
        //this->m_pjsProcess->terminate();
        this->m_pjsProcess->kill();
        this->m_pjsProcess->waitForFinished();

        this->m_status = "Stopped";
        emit pjsMessage(this->m_index,"Stopped");
    }
    this->m_timer.stop();

}

void PJSObject::pause()
{
    this->m_stop = true;
    if(this->m_pjsProcess->state()==QProcess::Running){
        //this->m_pjsProcess->terminate();
        this->m_pjsProcess->kill();
        this->m_pjsProcess->waitForFinished();
        this->m_status = "Paused";
        emit pjsMessage(this->m_index,"Paused");
    }
    this->m_timer.stop();
}

void PJSObject::refreshJS()
{
    QFile f(this->m_jsPath);
    if(f.open(QIODevice::WriteOnly|QIODevice::Text)){
        QString data = "var page = require('webpage').create();\n";

        data.append(QString("page.viewportSize = {width: %1,height: %2};\n").arg(this->m_profile->browserWidth()).arg(this->m_profile->browserHeight()));

        data.append(QString("page.settings.userAgent = '%1';\n").arg(this->m_profile->userAgent()));
        data.append(QString("page.open('%1',").arg(this->m_url));
        data.append(QString("function() {\n"));
        //if(!this->m_profile->imageHeight().isEmpty() && !this->m_profile->imageWidth().isEmpty()){
            //data.append(QString("\tpage.clipRect = {top:0, left:0, width:%1, height:%2};\n").arg(this->m_profile->imageWidth()).arg(this->m_profile->imageHeight()));
        //}

        data.append(QString("\tpage.clipRect = {top:0, left:0, width:%1, height:%2};\n").arg(this->m_profile->browserWidth()).arg(this->m_profile->browserHeight()));
        data.append(QString("\tpage.render('%1',{format: '%2', quality: '%3'});\n")
                    .arg(this->m_target)
                    .arg(this->m_profile->imageType())
                    .arg(this->m_profile->imageQuality()));
        data.append("\tphantom.exit();\n});\n");
        f.write(data.toLocal8Bit());
        f.close();
    }
}

void PJSObject::started()
{
    //qDebug() << "process Started";
    this->m_status = "Rendering";
    emit pjsMessage(this->m_index,"Rendering");
}

void PJSObject::finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    //qDebug()<< "Process Finished";
    //qDebug() << exitCode;
    //qDebug()<< exitStatus;
    Q_UNUSED(exitCode);
    Q_UNUSED(exitStatus);
    bool canFinish = false;

    this->m_requestTimer.stop();
    this->m_timer.stop();

    //Add overlay image
    if(!this->m_profile->imageOverlay().isEmpty() && !this->m_stop &&!this->m_delayOverlayImage)
    {

        if(QFile::exists(this->m_target) && QFile::exists(this->m_profile->imageOverlay())){
            QPixmap base(this->m_target), overlay(this->m_profile->imageOverlay()); // come from your code
            if(this->m_profile->imageOverlayCheckbox()){
                int w = overlay.width()* (this->m_profile->imageOverlaySizeScale()/100.0);
                int h = overlay.height()*(this->m_profile->imageOverlaySizeScale()/100.0);
                overlay = overlay.scaled(w,h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
            }

            int drX = (base.width()-overlay.width())/2;
            int drY = (base.height()-overlay.height())/2;

            QPixmap result(base.width(), base.height());
            result.fill(Qt::transparent); // force alpha channel
            {
                QPainter painter(&result);
                painter.setRenderHint(QPainter::Antialiasing);

                painter.drawPixmap(0, 0, base);
                painter.drawPixmap(drX, drY, overlay);

                QPainterPath path;
                path.addRect(0,0,result.width(),result.height());
                QPen pen(Qt::black, 5);
                painter.setPen(pen);
                //p.fillPath(path, Qt::red);
                painter.drawPath(path);
            }

            result = result.scaled(this->m_profile->imageWidth().toInt(), this->m_profile->imageHeight().toInt(),Qt::KeepAspectRatio,Qt::SmoothTransformation);

            result.save(this->m_target,
                    this->m_profile->imageType().toLocal8Bit().data(),
                    this->m_profile->imageQuality().toInt()
                    );
            canFinish = true;
        }
    }
    else{
        canFinish = true;
    }


    if(canFinish && !this->m_stop){
        this->m_status = "Finished";
        emit pjsMessage(this->m_index,"Finished");
    }
    else{
        //Here we will start the process
        if(!this->m_stop){
            //Add meta refresh
            this->m_requestTimer.stop();
            this->m_timer.start(this->m_profile->refreshTime()*1000);
            emit pjsMessage(this->m_index,"Failed");
            this->m_status = "Failed";
        }
    }
}

void PJSObject::timeOut()
{
    this->m_requestTimer.start(this->m_profile->maxRequestTime()*1000);
    this->m_timer.stop();
    this->refreshJS();
    this->m_pjsProcess->start(this->m_pjsExe,QStringList()<<this->m_jsPath);

}

void PJSObject::requestTimeOut()
{
    this->m_requestTimer.stop();
    this->m_timer.stop();

    if(this->m_pjsProcess->state()==QProcess::Running){
        this->m_pjsProcess->kill();
        this->m_pjsProcess->waitForFinished();
    }

    this->m_status = "Timeout";
    emit pjsMessage(this->m_index,"Timeout");
}
