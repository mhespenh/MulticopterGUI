/****************************************************************************
** Meta object code from reading C++ file 'thrustbar.h'
**
** Created: Fri Apr 20 16:15:19 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "thrustbar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'thrustbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThrustBar[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      40,   28,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ThrustBar[] = {
    "ThrustBar\0\0updateBarGraph()\0e1,e2,e3,e4\0"
    "updateThrust(int,int,int,int)\0"
};

const QMetaObject ThrustBar::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ThrustBar,
      qt_meta_data_ThrustBar, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThrustBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThrustBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThrustBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThrustBar))
        return static_cast<void*>(const_cast< ThrustBar*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ThrustBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateBarGraph(); break;
        case 1: updateThrust((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
