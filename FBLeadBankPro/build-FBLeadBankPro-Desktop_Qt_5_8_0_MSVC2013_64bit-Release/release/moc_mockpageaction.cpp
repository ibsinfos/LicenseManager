/****************************************************************************
** Meta object code from reading C++ file 'mockpageaction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FBLeadBankPro/mockpageaction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mockpageaction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MockPageAction_t {
    QByteArrayData data[10];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MockPageAction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MockPageAction_t qt_meta_stringdata_MockPageAction = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MockPageAction"
QT_MOC_LITERAL(1, 15, 19), // "mockPageActionStart"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 18), // "mockPageActionStop"
QT_MOC_LITERAL(4, 55, 19), // "mockPageActionPause"
QT_MOC_LITERAL(5, 75, 20), // "mockPageActionResume"
QT_MOC_LITERAL(6, 96, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(7, 119, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(8, 141, 22), // "on_pauseButton_clicked"
QT_MOC_LITERAL(9, 164, 23) // "on_resumeButton_clicked"

    },
    "MockPageAction\0mockPageActionStart\0\0"
    "mockPageActionStop\0mockPageActionPause\0"
    "mockPageActionResume\0on_startButton_clicked\0"
    "on_stopButton_clicked\0on_pauseButton_clicked\0"
    "on_resumeButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MockPageAction[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MockPageAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MockPageAction *_t = static_cast<MockPageAction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mockPageActionStart(); break;
        case 1: _t->mockPageActionStop(); break;
        case 2: _t->mockPageActionPause(); break;
        case 3: _t->mockPageActionResume(); break;
        case 4: _t->on_startButton_clicked(); break;
        case 5: _t->on_stopButton_clicked(); break;
        case 6: _t->on_pauseButton_clicked(); break;
        case 7: _t->on_resumeButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MockPageAction::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MockPageAction::mockPageActionStart)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MockPageAction::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MockPageAction::mockPageActionStop)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MockPageAction::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MockPageAction::mockPageActionPause)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MockPageAction::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MockPageAction::mockPageActionResume)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MockPageAction::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MockPageAction.data,
      qt_meta_data_MockPageAction,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MockPageAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MockPageAction::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MockPageAction.stringdata0))
        return static_cast<void*>(const_cast< MockPageAction*>(this));
    return QWidget::qt_metacast(_clname);
}

int MockPageAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MockPageAction::mockPageActionStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MockPageAction::mockPageActionStop()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MockPageAction::mockPageActionPause()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MockPageAction::mockPageActionResume()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
