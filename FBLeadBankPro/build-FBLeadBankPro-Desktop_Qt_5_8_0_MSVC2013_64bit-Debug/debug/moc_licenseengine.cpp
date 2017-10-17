/****************************************************************************
** Meta object code from reading C++ file 'licenseengine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../FBLeadBankCopy/FBLeadBankProSource/FBLeadBankPro/FBLeadBankPro/licenseengine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'licenseengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LicenseEngine_t {
    QByteArrayData data[14];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LicenseEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LicenseEngine_t qt_meta_stringdata_LicenseEngine = {
    {
QT_MOC_LITERAL(0, 0, 13), // "LicenseEngine"
QT_MOC_LITERAL(1, 14, 14), // "invalidLicense"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "message"
QT_MOC_LITERAL(4, 38, 12), // "validLicense"
QT_MOC_LITERAL(5, 51, 16), // "licenseActivated"
QT_MOC_LITERAL(6, 68, 5), // "error"
QT_MOC_LITERAL(7, 74, 23), // "licenseValidationReport"
QT_MOC_LITERAL(8, 98, 28), // "licenseValidationErrorReport"
QT_MOC_LITERAL(9, 127, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(10, 155, 4), // "code"
QT_MOC_LITERAL(11, 160, 15), // "validateLicense"
QT_MOC_LITERAL(12, 176, 7), // "license"
QT_MOC_LITERAL(13, 184, 10) // "product_id"

    },
    "LicenseEngine\0invalidLicense\0\0message\0"
    "validLicense\0licenseActivated\0error\0"
    "licenseValidationReport\0"
    "licenseValidationErrorReport\0"
    "QNetworkReply::NetworkError\0code\0"
    "validateLicense\0license\0product_id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LicenseEngine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,
       6,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   55,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
      11,    2,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,

       0        // eod
};

void LicenseEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LicenseEngine *_t = static_cast<LicenseEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->invalidLicense((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->validLicense(); break;
        case 2: _t->licenseActivated(); break;
        case 3: _t->error(); break;
        case 4: _t->licenseValidationReport(); break;
        case 5: _t->licenseValidationErrorReport((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 6: _t->validateLicense((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LicenseEngine::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LicenseEngine::invalidLicense)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LicenseEngine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LicenseEngine::validLicense)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LicenseEngine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LicenseEngine::licenseActivated)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (LicenseEngine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LicenseEngine::error)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject LicenseEngine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LicenseEngine.data,
      qt_meta_data_LicenseEngine,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LicenseEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LicenseEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LicenseEngine.stringdata0))
        return static_cast<void*>(const_cast< LicenseEngine*>(this));
    return QObject::qt_metacast(_clname);
}

int LicenseEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void LicenseEngine::invalidLicense(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LicenseEngine::validLicense()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void LicenseEngine::licenseActivated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void LicenseEngine::error()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
