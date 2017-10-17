/****************************************************************************
** Meta object code from reading C++ file 'pageemailsetup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FBLeadBankPro/pageemailsetup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pageemailsetup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PageEmailSetup_t {
    QByteArrayData data[5];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PageEmailSetup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PageEmailSetup_t qt_meta_stringdata_PageEmailSetup = {
    {
QT_MOC_LITERAL(0, 0, 14), // "PageEmailSetup"
QT_MOC_LITERAL(1, 15, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 23), // "on_showPassword_clicked"
QT_MOC_LITERAL(4, 62, 26) // "on_imageLink_returnPressed"

    },
    "PageEmailSetup\0on_saveButton_clicked\0"
    "\0on_showPassword_clicked\0"
    "on_imageLink_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PageEmailSetup[] = {

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
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PageEmailSetup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PageEmailSetup *_t = static_cast<PageEmailSetup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_saveButton_clicked(); break;
        case 1: _t->on_showPassword_clicked(); break;
        case 2: _t->on_imageLink_returnPressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PageEmailSetup::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PageEmailSetup.data,
      qt_meta_data_PageEmailSetup,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PageEmailSetup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PageEmailSetup::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PageEmailSetup.stringdata0))
        return static_cast<void*>(const_cast< PageEmailSetup*>(this));
    return QWidget::qt_metacast(_clname);
}

int PageEmailSetup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
