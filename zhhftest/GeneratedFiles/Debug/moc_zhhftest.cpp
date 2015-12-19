/****************************************************************************
** Meta object code from reading C++ file 'zhhftest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../zhhftest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zhhftest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_zhhftest_t {
    QByteArrayData data[5];
    char stringdata[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_zhhftest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_zhhftest_t qt_meta_stringdata_zhhftest = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 13),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 15),
QT_MOC_LITERAL(4, 40, 17)
    },
    "zhhftest\0slotStartAnim\0\0slotShowDiallog\0"
    "continueStartAnim\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_zhhftest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a,
       3,    0,   30,    2, 0x0a,
       4,    0,   31,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void zhhftest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        zhhftest *_t = static_cast<zhhftest *>(_o);
        switch (_id) {
        case 0: _t->slotStartAnim(); break;
        case 1: _t->slotShowDiallog(); break;
        case 2: _t->continueStartAnim(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject zhhftest::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_zhhftest.data,
      qt_meta_data_zhhftest,  qt_static_metacall, 0, 0}
};


const QMetaObject *zhhftest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *zhhftest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_zhhftest.stringdata))
        return static_cast<void*>(const_cast< zhhftest*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int zhhftest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
