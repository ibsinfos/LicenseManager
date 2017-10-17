/****************************************************************************
** Meta object code from reading C++ file 'qmonster.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FBLeadBankPro/qmonster.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmonster.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QMonster_t {
    QByteArrayData data[12];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMonster_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMonster_t qt_meta_stringdata_QMonster = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QMonster"
QT_MOC_LITERAL(1, 9, 13), // "threadStarted"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "threadStopped"
QT_MOC_LITERAL(4, 38, 12), // "threadPaused"
QT_MOC_LITERAL(5, 51, 13), // "threadResumed"
QT_MOC_LITERAL(6, 65, 14), // "threadFinished"
QT_MOC_LITERAL(7, 80, 20), // "processNotFoundError"
QT_MOC_LITERAL(8, 101, 5), // "start"
QT_MOC_LITERAL(9, 107, 4), // "stop"
QT_MOC_LITERAL(10, 112, 5), // "pause"
QT_MOC_LITERAL(11, 118, 6) // "resume"

    },
    "QMonster\0threadStarted\0\0threadStopped\0"
    "threadPaused\0threadResumed\0threadFinished\0"
    "processNotFoundError\0start\0stop\0pause\0"
    "resume"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMonster[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
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

void QMonster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMonster *_t = static_cast<QMonster *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->threadStarted(); break;
        case 1: _t->threadStopped(); break;
        case 2: _t->threadPaused(); break;
        case 3: _t->threadResumed(); break;
        case 4: _t->threadFinished(); break;
        case 5: _t->processNotFoundError(); break;
        case 6: _t->start(); break;
        case 7: _t->stop(); break;
        case 8: _t->pause(); break;
        case 9: _t->resume(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QMonster::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMonster::threadStarted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QMonster::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMonster::threadStopped)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QMonster::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMonster::threadPaused)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QMonster::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMonster::threadResumed)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QMonster::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMonster::threadFinished)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QMonster::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMonster::processNotFoundError)) {
                *result = 5;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QMonster::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_QMonster.data,
      qt_meta_data_QMonster,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QMonster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMonster::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QMonster.stringdata0))
        return static_cast<void*>(const_cast< QMonster*>(this));
    return QThread::qt_metacast(_clname);
}

int QMonster::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void QMonster::threadStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QMonster::threadStopped()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QMonster::threadPaused()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void QMonster::threadResumed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void QMonster::threadFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void QMonster::processNotFoundError()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
