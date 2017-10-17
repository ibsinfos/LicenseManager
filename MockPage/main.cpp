#include "metashotmainwindow.h"
#include <QApplication>
#include "metashot.h"
#include "licensevalidator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MetaShot::ins()->appDataRoot();

    LicenseValidator v;
    v.show();

    return a.exec();
}
