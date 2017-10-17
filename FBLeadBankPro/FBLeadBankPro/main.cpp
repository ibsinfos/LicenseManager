#include "leadbankpromainwindow.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QSettings>

#include "MockPage/metashot.h"
#include "MockPage/metashotprofile.h"

#include "textrotator.h"
#include "licenseengine.h"
#include "licensevalidator.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    TextRotator r;
//    qDebug() << r.message("Hi\nthis is a {message|text} from {k|l}.");

    MetaShot::ins()->appDataRoot();

    {
        QFile f(":/data/data/style.qss");
        if(f.open(QIODevice::ReadOnly|QIODevice::Text)){
            a.setStyleSheet(QString(f.readAll()));
            f.close();
        }

        QSettings settings(MetaShot::ins()->appDataRoot()+"/lbp.s",QSettings::IniFormat);
        QString at = "EAALqGKzsboYBADqbGVoHq4DZAIPU3oSEdJw3GCxLTgJJgEgH1eZAgvcgMiXAZCEuO0SpR0OfnaJvOB5e5WL7ZAXfSDgWvzw9TyfMyUffI4HIaI6rfN6afl124OZBFHv421GuU87hXNOJr6wAqZC23i6ly7DxOkfHvA4iyIKI7OZCLPZBmQ1XZBMUU";
        if(settings.value("ACCESS_TOKEN").toString().isEmpty()){
            settings.setValue("ACCESS_TOKEN",at);
        }



        settings.sync();
        //qDebug() << settings.allKeys();

        MetaShotProfile msp("Default");
        msp.set("profileName", "Default");
    }


    LicenseValidator v;
    v.show();


    //LeadBankProMainWindow w;
    //w.show();

    return a.exec();
}
