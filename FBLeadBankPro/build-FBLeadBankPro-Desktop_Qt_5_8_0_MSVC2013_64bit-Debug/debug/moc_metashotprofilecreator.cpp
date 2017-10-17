/****************************************************************************
** Meta object code from reading C++ file 'metashotprofilecreator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FBLeadBankPro/MockPage/metashotprofilecreator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'metashotprofilecreator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MetaShotProfileCreator_t {
    QByteArrayData data[17];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MetaShotProfileCreator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MetaShotProfileCreator_t qt_meta_stringdata_MetaShotProfileCreator = {
    {
QT_MOC_LITERAL(0, 0, 22), // "MetaShotProfileCreator"
QT_MOC_LITERAL(1, 23, 19), // "loadDataFromProfile"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 4), // "name"
QT_MOC_LITERAL(4, 49, 11), // "saveProfile"
QT_MOC_LITERAL(5, 61, 4), // "path"
QT_MOC_LITERAL(6, 66, 6), // "isPath"
QT_MOC_LITERAL(7, 73, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(8, 95, 29), // "on_imageOverlaySelect_clicked"
QT_MOC_LITERAL(9, 125, 21), // "userAgentIndexChanged"
QT_MOC_LITERAL(10, 147, 5), // "index"
QT_MOC_LITERAL(11, 153, 24), // "on_previewButton_clicked"
QT_MOC_LITERAL(12, 178, 32), // "on_overlayImageSize_valueChanged"
QT_MOC_LITERAL(13, 211, 5), // "value"
QT_MOC_LITERAL(14, 217, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(15, 239, 23), // "on_comboBox_2_activated"
QT_MOC_LITERAL(16, 263, 21) // "on_pushButton_clicked"

    },
    "MetaShotProfileCreator\0loadDataFromProfile\0"
    "\0name\0saveProfile\0path\0isPath\0"
    "on_saveButton_clicked\0"
    "on_imageOverlaySelect_clicked\0"
    "userAgentIndexChanged\0index\0"
    "on_previewButton_clicked\0"
    "on_overlayImageSize_valueChanged\0value\0"
    "on_comboBox_activated\0on_comboBox_2_activated\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MetaShotProfileCreator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       4,    2,   67,    2, 0x0a /* Public */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    1,   74,    2, 0x08 /* Private */,
      11,    0,   77,    2, 0x08 /* Private */,
      12,    1,   78,    2, 0x08 /* Private */,
      14,    1,   81,    2, 0x08 /* Private */,
      15,    1,   84,    2, 0x08 /* Private */,
      16,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

       0        // eod
};

void MetaShotProfileCreator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MetaShotProfileCreator *_t = static_cast<MetaShotProfileCreator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadDataFromProfile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->saveProfile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->on_saveButton_clicked(); break;
        case 3: _t->on_imageOverlaySelect_clicked(); break;
        case 4: _t->userAgentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_previewButton_clicked(); break;
        case 6: _t->on_overlayImageSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_comboBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_comboBox_2_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MetaShotProfileCreator::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MetaShotProfileCreator.data,
      qt_meta_data_MetaShotProfileCreator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MetaShotProfileCreator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MetaShotProfileCreator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MetaShotProfileCreator.stringdata0))
        return static_cast<void*>(const_cast< MetaShotProfileCreator*>(this));
    return QDialog::qt_metacast(_clname);
}

int MetaShotProfileCreator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
