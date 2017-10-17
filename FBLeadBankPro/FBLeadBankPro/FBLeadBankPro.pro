#-------------------------------------------------
#
# Project created by QtCreator 2017-02-08T13:17:54
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FBLeadBankPro
TEMPLATE = app


SOURCES += main.cpp \
    actionwidget.cpp \
    dbobject.cpp \
    fbgraphapi.cpp \
    filterwidget.cpp \
    leadbankpromainwindow.cpp \
    leadbankprosimpleui.cpp \
    licenseengine.cpp \
    licensevalidator.cpp \
    logbrowser.cpp \
    mockpageaction.cpp \
    mockpagepreview.cpp \
    pagedashboard.cpp \
    pagedashboardscrollable.cpp \
    pageemailsetup.cpp \
    pagesetup.cpp \
    pjsthreadmanager.cpp \
    profileselector.cpp \
    qmonster.cpp \
    qnodejs.cpp \
    smtp.cpp \
    statswidget.cpp \
    targetfolder.cpp \
    textrotator.cpp \
    utility.cpp

HEADERS  += \
    actionwidget.h \
    dbobject.h \
    fbgraphapi.h \
    filterwidget.h \
    leadbankpromainwindow.h \
    leadbankprosimpleui.h \
    licenseengine.h \
    licensevalidator.h \
    logbrowser.h \
    mockpageaction.h \
    mockpagepreview.h \
    pagedashboard.h \
    pagedashboardscrollable.h \
    pageemailsetup.h \
    pagesetup.h \
    pjsthreadmanager.h \
    profileselector.h \
    qmonster.h \
    qnodejs.h \
    smtp.h \
    statswidget.h \
    targetfolder.h \
    textrotator.h \
    utility.h

RESOURCES += \
    leadbankpro.qrc

FORMS += \
    actionwidget.ui \
    filterwidget.ui \
    leadbankpromainwindow.ui \
    leadbankprosimpleui.ui \
    licensevalidator.ui \
    logbrowser.ui \
    mockpageaction.ui \
    mockpagepreview.ui \
    pagedashboard.ui \
    pagedashboardscrollable.ui \
    pageemailsetup.ui \
    pagesetup.ui \
    profileselector.ui \
    statswidget.ui \
    targetfolder.ui

DISTFILES += \
    Info.plist \
    LeadBankPro.ico \
    LeadBankPro.icns



include(MockPage/MockPage.pri)


macx{
    RC_FILE = LeadBankPro.icns
    QMAKE_INFO_PLIST=Info.plist
}

win32:RC_ICONS += LeadBankPro.ico
