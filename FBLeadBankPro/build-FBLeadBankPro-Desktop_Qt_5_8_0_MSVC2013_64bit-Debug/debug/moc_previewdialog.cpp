/****************************************************************************
** Meta object code from reading C++ file 'previewdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FBLeadBankPro/MockPage/previewdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'previewdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PreviewDialog_t {
    QByteArrayData data[9];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PreviewDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PreviewDialog_t qt_meta_stringdata_PreviewDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PreviewDialog"
QT_MOC_LITERAL(1, 14, 19), // "on_goButton_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 10), // "pjsMessage"
QT_MOC_LITERAL(4, 46, 5), // "index"
QT_MOC_LITERAL(5, 52, 7), // "message"
QT_MOC_LITERAL(6, 60, 29), // "on_overlaySlider_valueChanged"
QT_MOC_LITERAL(7, 90, 5), // "value"
QT_MOC_LITERAL(8, 96, 15) // "on_Save_clicked"

    },
    "PreviewDialog\0on_goButton_clicked\0\0"
    "pjsMessage\0index\0message\0"
    "on_overlaySlider_valueChanged\0value\0"
    "on_Save_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PreviewDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    2,   35,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       8,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

       0        // eod
};

void PreviewDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PreviewDialog *_t = static_cast<PreviewDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_goButton_clicked(); break;
        case 1: _t->pjsMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->on_overlaySlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_Save_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject PreviewDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PreviewDialog.data,
      qt_meta_data_PreviewDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PreviewDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PreviewDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PreviewDialog.stringdata0))
        return static_cast<void*>(const_cast< PreviewDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PreviewDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
