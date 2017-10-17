/****************************************************************************
** Meta object code from reading C++ file 'leadbankpromainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FBLeadBankPro/leadbankpromainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'leadbankpromainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LeadBankProMainWindow_t {
    QByteArrayData data[6];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LeadBankProMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LeadBankProMainWindow_t qt_meta_stringdata_LeadBankProMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 21), // "LeadBankProMainWindow"
QT_MOC_LITERAL(1, 22, 27), // "on_actionLog_Window_toggled"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 4), // "arg1"
QT_MOC_LITERAL(4, 56, 30), // "on_action_Clear_Logs_triggered"
QT_MOC_LITERAL(5, 87, 29) // "on_actionLog_Window_triggered"

    },
    "LeadBankProMainWindow\0on_actionLog_Window_toggled\0"
    "\0arg1\0on_action_Clear_Logs_triggered\0"
    "on_actionLog_Window_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LeadBankProMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LeadBankProMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LeadBankProMainWindow *_t = static_cast<LeadBankProMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionLog_Window_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_action_Clear_Logs_triggered(); break;
        case 2: _t->on_actionLog_Window_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject LeadBankProMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LeadBankProMainWindow.data,
      qt_meta_data_LeadBankProMainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LeadBankProMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LeadBankProMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LeadBankProMainWindow.stringdata0))
        return static_cast<void*>(const_cast< LeadBankProMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int LeadBankProMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
