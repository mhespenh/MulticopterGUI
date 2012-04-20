/****************************************************************************
** Meta object code from reading C++ file 'avionicstelemetry.h'
**
** Created: Fri Apr 20 16:15:21 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "avionicstelemetry.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'avionicstelemetry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AvionicsTelemetry[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   19,   18,   18, 0x05,
      58,   46,   18,   18, 0x05,
      91,   19,   18,   18, 0x05,
     119,   18,   18,   18, 0x05,
     141,  137,   18,   18, 0x05,
     187,  165,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
     220,   18,   18,   18, 0x0a,
     238,  137,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AvionicsTelemetry[] = {
    "AvionicsTelemetry\0\0value\0updateAltimeter(int)\0"
    "e1,e2,e3,e4\0updateThrustBar(int,int,int,int)\0"
    "updateHeadingIndicator(int)\0"
    "closeAllWidgets()\0x,y\0updatePosition(int,int)\0"
    "sizeX,sizeY,corX,corY\0"
    "updateObstacles(int,int,int,int)\0"
    "readWriteMemory()\0updateDestination(int,int)\0"
};

const QMetaObject AvionicsTelemetry::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AvionicsTelemetry,
      qt_meta_data_AvionicsTelemetry, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AvionicsTelemetry::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AvionicsTelemetry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AvionicsTelemetry::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AvionicsTelemetry))
        return static_cast<void*>(const_cast< AvionicsTelemetry*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AvionicsTelemetry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateAltimeter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: updateThrustBar((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: updateHeadingIndicator((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: closeAllWidgets(); break;
        case 4: updatePosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: updateObstacles((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: readWriteMemory(); break;
        case 7: updateDestination((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AvionicsTelemetry::updateAltimeter(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AvionicsTelemetry::updateThrustBar(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AvionicsTelemetry::updateHeadingIndicator(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AvionicsTelemetry::closeAllWidgets()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void AvionicsTelemetry::updatePosition(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AvionicsTelemetry::updateObstacles(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
