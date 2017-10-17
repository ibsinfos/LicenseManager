/****************************************************************************
** Meta object code from reading C++ file 'qnodejs.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FBLeadBankPro/qnodejs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnodejs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QNodeJs_t {
    QByteArrayData data[13];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QNodeJs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QNodeJs_t qt_meta_stringdata_QNodeJs = {
    {
QT_MOC_LITERAL(0, 0, 7), // "QNodeJs"
QT_MOC_LITERAL(1, 8, 13), // "nodeJsStarted"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "nodeJsFinished"
QT_MOC_LITERAL(4, 38, 6), // "status"
QT_MOC_LITERAL(5, 45, 7), // "message"
QT_MOC_LITERAL(6, 53, 15), // "processFinished"
QT_MOC_LITERAL(7, 69, 5), // "start"
QT_MOC_LITERAL(8, 75, 4), // "path"
QT_MOC_LITERAL(9, 80, 4), // "args"
QT_MOC_LITERAL(10, 85, 4), // "stop"
QT_MOC_LITERAL(11, 90, 9), // "isRunning"
QT_MOC_LITERAL(12, 100, 11) // "finalString"

    },
    "QNodeJs\0nodeJsStarted\0\0nodeJsFinished\0"
    "status\0message\0processFinished\0start\0"
    "path\0args\0stop\0isRunning\0finalString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QNodeJs[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   59,    2, 0x08 /* Private */,
       7,    2,   60,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x0a /* Public */,
      11,    0,   66,    2, 0x0a /* Public */,
      12,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    8,    9,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::QString,

       0        // eod
};

void QNodeJs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QNodeJs *_t = static_cast<QNodeJs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nodeJsStarted(); break;
        case 1: _t->nodeJsFinished(); break;
        case 2: _t->status((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->processFinished(); break;
        case 4: _t->start((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2]))); break;
        case 5: _t->stop(); break;
        case 6: { bool _r = _t->isRunning();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { QString _r = _t->finalString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QNodeJs::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QNodeJs::nodeJsStarted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QNodeJs::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QNodeJs::nodeJsFinished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QNodeJs::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QNodeJs::status)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QNodeJs::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_QNodeJs.data,
      qt_meta_data_QNodeJs,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QNodeJs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNodeJs::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QNodeJs.stringdata0))
        return static_cast<void*>(const_cast< QNodeJs*>(this));
    return QThread::qt_metacast(_clname);
}

int QNodeJs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void QNodeJs::nodeJsStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QNodeJs::nodeJsFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QNodeJs::status(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
