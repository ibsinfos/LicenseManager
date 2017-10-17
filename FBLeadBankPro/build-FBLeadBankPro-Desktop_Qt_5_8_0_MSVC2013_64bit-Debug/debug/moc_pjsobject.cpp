/****************************************************************************
** Meta object code from reading C++ file 'pjsobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FBLeadBankPro/MockPage/pjsobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pjsobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PJSObject_t {
    QByteArrayData data[14];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PJSObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PJSObject_t qt_meta_stringdata_PJSObject = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PJSObject"
QT_MOC_LITERAL(1, 10, 10), // "pjsMessage"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "index"
QT_MOC_LITERAL(4, 28, 7), // "message"
QT_MOC_LITERAL(5, 36, 4), // "stop"
QT_MOC_LITERAL(6, 41, 5), // "pause"
QT_MOC_LITERAL(7, 47, 7), // "started"
QT_MOC_LITERAL(8, 55, 8), // "finished"
QT_MOC_LITERAL(9, 64, 8), // "exitCode"
QT_MOC_LITERAL(10, 73, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(11, 94, 10), // "exitStatus"
QT_MOC_LITERAL(12, 105, 7), // "timeOut"
QT_MOC_LITERAL(13, 113, 14) // "requestTimeOut"

    },
    "PJSObject\0pjsMessage\0\0index\0message\0"
    "stop\0pause\0started\0finished\0exitCode\0"
    "QProcess::ExitStatus\0exitStatus\0timeOut\0"
    "requestTimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PJSObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   54,    2, 0x0a /* Public */,
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    2,   57,    2, 0x08 /* Private */,
      12,    0,   62,    2, 0x08 /* Private */,
      13,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 10,    9,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PJSObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PJSObject *_t = static_cast<PJSObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pjsMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->stop(); break;
        case 2: _t->pause(); break;
        case 3: _t->started(); break;
        case 4: _t->finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 5: _t->timeOut(); break;
        case 6: _t->requestTimeOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PJSObject::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PJSObject::pjsMessage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PJSObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PJSObject.data,
      qt_meta_data_PJSObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PJSObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PJSObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PJSObject.stringdata0))
        return static_cast<void*>(const_cast< PJSObject*>(this));
    return QObject::qt_metacast(_clname);
}

int PJSObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void PJSObject::pjsMessage(int _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
