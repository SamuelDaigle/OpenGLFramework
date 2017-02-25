/****************************************************************************
** Meta object code from reading C++ file 'uiqt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../uiqt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UIQT_t {
    QByteArrayData data[17];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UIQT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UIQT_t qt_meta_stringdata_UIQT = {
    {
QT_MOC_LITERAL(0, 0, 4), // "UIQT"
QT_MOC_LITERAL(1, 5, 9), // "newRColor"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 9), // "newGColor"
QT_MOC_LITERAL(4, 26, 9), // "newBColor"
QT_MOC_LITERAL(5, 36, 12), // "newXPosition"
QT_MOC_LITERAL(6, 49, 12), // "newYPosition"
QT_MOC_LITERAL(7, 62, 12), // "newZPosition"
QT_MOC_LITERAL(8, 75, 13), // "newXRotationn"
QT_MOC_LITERAL(9, 89, 13), // "newYRotationn"
QT_MOC_LITERAL(10, 103, 13), // "newZRotationn"
QT_MOC_LITERAL(11, 117, 8), // "newScale"
QT_MOC_LITERAL(12, 126, 8), // "newPitch"
QT_MOC_LITERAL(13, 135, 6), // "newYaw"
QT_MOC_LITERAL(14, 142, 7), // "newZoom"
QT_MOC_LITERAL(15, 150, 7), // "newNear"
QT_MOC_LITERAL(16, 158, 6) // "newFar"

    },
    "UIQT\0newRColor\0\0newGColor\0newBColor\0"
    "newXPosition\0newYPosition\0newZPosition\0"
    "newXRotationn\0newYRotationn\0newZRotationn\0"
    "newScale\0newPitch\0newYaw\0newZoom\0"
    "newNear\0newFar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UIQT[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UIQT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UIQT *_t = static_cast<UIQT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newRColor(); break;
        case 1: _t->newGColor(); break;
        case 2: _t->newBColor(); break;
        case 3: _t->newXPosition(); break;
        case 4: _t->newYPosition(); break;
        case 5: _t->newZPosition(); break;
        case 6: _t->newXRotationn(); break;
        case 7: _t->newYRotationn(); break;
        case 8: _t->newZRotationn(); break;
        case 9: _t->newScale(); break;
        case 10: _t->newPitch(); break;
        case 11: _t->newYaw(); break;
        case 12: _t->newZoom(); break;
        case 13: _t->newNear(); break;
        case 14: _t->newFar(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UIQT::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UIQT.data,
      qt_meta_data_UIQT,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UIQT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UIQT::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UIQT.stringdata0))
        return static_cast<void*>(const_cast< UIQT*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UIQT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
