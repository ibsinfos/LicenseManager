/****************************************************************************
** Meta object code from reading C++ file 'pjsthreadmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FBLeadBankPro/pjsthreadmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pjsthreadmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PJSThreadManager_t {
    QByteArrayData data[15];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PJSThreadManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PJSThreadManager_t qt_meta_stringdata_PJSThreadManager = {
    {
QT_MOC_LITERAL(0, 0, 16), // "PJSThreadManager"
QT_MOC_LITERAL(1, 17, 13), // "updateMessage"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "row"
QT_MOC_LITERAL(4, 36, 7), // "message"
QT_MOC_LITERAL(5, 44, 5), // "error"
QT_MOC_LITERAL(6, 50, 13), // "threadStopped"
QT_MOC_LITERAL(7, 64, 14), // "threadFinished"
QT_MOC_LITERAL(8, 79, 12), // "threadPaused"
QT_MOC_LITERAL(9, 92, 9), // "sendEmail"
QT_MOC_LITERAL(10, 102, 19), // "sendFacebookMessage"
QT_MOC_LITERAL(11, 122, 4), // "stop"
QT_MOC_LITERAL(12, 127, 5), // "start"
QT_MOC_LITERAL(13, 133, 5), // "pause"
QT_MOC_LITERAL(14, 139, 10) // "pjsMessage"

    },
    "PJSThreadManager\0updateMessage\0\0row\0"
    "message\0error\0threadStopped\0threadFinished\0"
    "threadPaused\0sendEmail\0sendFacebookMessage\0"
    "stop\0start\0pause\0pjsMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PJSThreadManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    1,   74,    2, 0x06 /* Public */,
       6,    0,   77,    2, 0x06 /* Public */,
       7,    0,   78,    2, 0x06 /* Public */,
       8,    0,   79,    2, 0x06 /* Public */,
       9,    1,   80,    2, 0x06 /* Public */,
      10,    1,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    0,   88,    2, 0x0a /* Public */,
      14,    2,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

       0        // eod
};

void PJSThreadManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PJSThreadManager *_t = static_cast<PJSThreadManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->threadStopped(); break;
        case 3: _t->threadFinished(); break;
        case 4: _t->threadPaused(); break;
        case 5: _t->sendEmail((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->sendFacebookMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->stop(); break;
        case 8: _t->start(); break;
        case 9: _t->pause(); break;
        case 10: _t->pjsMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PJSThreadManager::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PJSThreadManager::updateMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PJSThreadManager::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PJSThreadManager::error)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PJSThreadManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PJSThreadManager::threadStopped)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PJSThreadManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PJSThreadManager::threadFinished)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PJSThreadManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PJSThreadManager::threadPaused)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (PJSThreadManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PJSThreadManager::sendEmail)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (PJSThreadManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PJSThreadManager::sendFacebookMessage)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject PJSThreadManager::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_PJSThreadManager.data,
      qt_meta_data_PJSThreadManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PJSThreadManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PJSThreadManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PJSThreadManager.stringdata0))
        return static_cast<void*>(const_cast< PJSThreadManager*>(this));
    return QThread::qt_metacast(_clname);
}

int PJSThreadManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void PJSThreadManager::updateMessage(int _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PJSThreadManager::error(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PJSThreadManager::threadStopped()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void PJSThreadManager::threadFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void PJSThreadManager::threadPaused()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void PJSThreadManager::sendEmail(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PJSThreadManager::sendFacebookMessage(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
