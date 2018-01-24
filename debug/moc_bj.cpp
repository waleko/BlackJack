/****************************************************************************
** Meta object code from reading C++ file 'bj.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bj.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bj.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BJ_t {
    QByteArrayData data[7];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BJ_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BJ_t qt_meta_stringdata_BJ = {
    {
QT_MOC_LITERAL(0, 0, 2), // "BJ"
QT_MOC_LITERAL(1, 3, 2), // "pl"
QT_MOC_LITERAL(2, 6, 0), // ""
QT_MOC_LITERAL(3, 7, 3), // "min"
QT_MOC_LITERAL(4, 11, 6), // "betnew"
QT_MOC_LITERAL(5, 18, 4), // "game"
QT_MOC_LITERAL(6, 23, 27) // "on_actionAbout_us_triggered"

    },
    "BJ\0pl\0\0min\0betnew\0game\0"
    "on_actionAbout_us_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BJ[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BJ::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BJ *_t = static_cast<BJ *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pl(); break;
        case 1: _t->min(); break;
        case 2: _t->betnew(); break;
        case 3: _t->game(); break;
        case 4: _t->on_actionAbout_us_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject BJ::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BJ.data,
      qt_meta_data_BJ,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BJ::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BJ::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BJ.stringdata0))
        return static_cast<void*>(const_cast< BJ*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BJ::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
