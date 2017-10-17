/****************************************************************************
** Meta object code from reading C++ file 'filterwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FBLeadBankPro/filterwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filterwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterWidget_t {
    QByteArrayData data[8];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterWidget_t qt_meta_stringdata_FilterWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FilterWidget"
QT_MOC_LITERAL(1, 13, 12), // "resetClicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "filterClicked"
QT_MOC_LITERAL(4, 41, 13), // "exportClicked"
QT_MOC_LITERAL(5, 55, 22), // "on_resetButton_clicked"
QT_MOC_LITERAL(6, 78, 23), // "on_filterButton_clicked"
QT_MOC_LITERAL(7, 102, 23) // "on_exportButton_clicked"

    },
    "FilterWidget\0resetClicked\0\0filterClicked\0"
    "exportClicked\0on_resetButton_clicked\0"
    "on_filterButton_clicked\0on_exportButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FilterWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilterWidget *_t = static_cast<FilterWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resetClicked(); break;
        case 1: _t->filterClicked(); break;
        case 2: _t->exportClicked(); break;
        case 3: _t->on_resetButton_clicked(); break;
        case 4: _t->on_filterButton_clicked(); break;
        case 5: _t->on_exportButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FilterWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FilterWidget::resetClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FilterWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FilterWidget::filterClicked)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FilterWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FilterWidget::exportClicked)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FilterWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FilterWidget.data,
      qt_meta_data_FilterWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FilterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FilterWidget.stringdata0))
        return static_cast<void*>(const_cast< FilterWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int FilterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FilterWidget::resetClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void FilterWidget::filterClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void FilterWidget::exportClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
