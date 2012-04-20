/****************************************************************************
** Meta object code from reading C++ file 'map.h'
**
** Created: Fri Apr 20 16:15:20 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "map.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MulticopterMap[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   16,   15,   15, 0x0a,
     101,   71,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MulticopterMap[] = {
    "MulticopterMap\0\0x,y\0updateDestination(int,int)\0"
    "updatePosition(int,int)\0"
    "obSizeX,obSizeY,obCorX,obCorY\0"
    "updateObstacles(int,int,int,int)\0"
};

const QMetaObject MulticopterMap::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MulticopterMap,
      qt_meta_data_MulticopterMap, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MulticopterMap::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MulticopterMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MulticopterMap::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MulticopterMap))
        return static_cast<void*>(const_cast< MulticopterMap*>(this));
    return QWidget::qt_metacast(_clname);
}

int MulticopterMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateDestination((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: updatePosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: updateObstacles((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MulticopterMap::updateDestination(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
