QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MockPage
TEMPLATE = app


SOURCES += main.cpp\
        metashotmainwindow.cpp \
    pjsobject.cpp \
    metashotprofilecreator.cpp \
    metashot.cpp \
    metashotprofile.cpp \
    previewdialog.cpp \
    pjsthread.cpp \
    licenseengine.cpp \
    licensevalidator.cpp

HEADERS  += metashotmainwindow.h \
    pjsobject.h \
    metashotprofilecreator.h \
    metashot.h \
    metashotprofile.h \
    previewdialog.h \
    pjsthread.h \
    licenseengine.h \
    licensevalidator.h

FORMS    += metashotmainwindow.ui \
    metashotprofilecreator.ui \
    previewdialog.ui \
    licensevalidator.ui

RESOURCES += \
    metashot.qrc

Debug:DESTDIR = debug
Debug:OBJECTS_DIR = debug/.obj
Debug:MOC_DIR = debug/.moc
Debug:RCC_DIR = debug/.rcc
Debug:UI_DIR = debug/.ui

win32:RC_FILE = icon.rc
