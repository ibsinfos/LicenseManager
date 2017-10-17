/****************************************************************************
** Meta object code from reading C++ file 'actionwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FBLeadBankPro/actionwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'actionwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ActionWidget_t {
    QByteArrayData data[15];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ActionWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ActionWidget_t qt_meta_stringdata_ActionWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ActionWidget"
QT_MOC_LITERAL(1, 13, 19), // "sendFacebookMessage"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "row"
QT_MOC_LITERAL(4, 38, 9), // "sendEmail"
QT_MOC_LITERAL(5, 48, 9), // "removeRow"
QT_MOC_LITERAL(6, 58, 19), // "showMockPagePreview"
QT_MOC_LITERAL(7, 78, 12), // "rowSelection"
QT_MOC_LITERAL(8, 91, 1), // "b"
QT_MOC_LITERAL(9, 93, 34), // "on_facebookMessengerButton_cl..."
QT_MOC_LITERAL(10, 128, 22), // "on_emailButton_clicked"
QT_MOC_LITERAL(11, 151, 23), // "on_removeButton_clicked"
QT_MOC_LITERAL(12, 175, 26), // "on_mockPagePreview_clicked"
QT_MOC_LITERAL(13, 202, 28), // "on_selectRowCheckBox_toggled"
QT_MOC_LITERAL(14, 231, 7) // "checked"

    },
    "ActionWidget\0sendFacebookMessage\0\0row\0"
    "sendEmail\0removeRow\0showMockPagePreview\0"
    "rowSelection\0b\0on_facebookMessengerButton_clicked\0"
    "on_emailButton_clicked\0on_removeButton_clicked\0"
    "on_mockPagePreview_clicked\0"
    "on_selectRowCheckBox_toggled\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ActionWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       5,    1,   70,    2, 0x06 /* Public */,
       6,    1,   73,    2, 0x06 /* Public */,
       7,    2,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,

       0        // eod
};

void ActionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ActionWidget *_t = static_cast<ActionWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendFacebookMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendEmail((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->removeRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->showMockPagePreview((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->rowSelection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->on_facebookMessengerButton_clicked(); break;
        case 6: _t->on_emailButton_clicked(); break;
        case 7: _t->on_removeButton_clicked(); break;
        case 8: _t->on_mockPagePreview_clicked(); break;
        case 9: _t->on_selectRowCheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ActionWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ActionWidget::sendFacebookMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ActionWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ActionWidget::sendEmail)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ActionWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ActionWidget::removeRow)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ActionWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ActionWidget::showMockPagePreview)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ActionWidget::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ActionWidget::rowSelection)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject ActionWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ActionWidget.data,
      qt_meta_data_ActionWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ActionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ActionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ActionWidget.stringdata0))
        return static_cast<void*>(const_cast< ActionWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ActionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ActionWidget::sendFacebookMessage(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ActionWidget::sendEmail(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ActionWidget::removeRow(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ActionWidget::showMockPagePreview(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ActionWidget::rowSelection(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
