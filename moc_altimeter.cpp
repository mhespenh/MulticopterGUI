/****************************************************************************
** Meta object code from reading C++ file 'altimeter.h'
**
** Created: Fri Apr 20 16:15:21 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "altimeter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'altimeter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Altimeter[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Altimeter[] = {
    "Altimeter\0\0value\0updateAltitude(int)\0"
};

const QMetaObject Altimeter::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Altimeter,
      qt_meta_data_Altimeter, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Altimeter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Altimeter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Altimeter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Altimeter))
        return static_cast<void*>(const_cast< Altimeter*>(this));
    return QWidget::qt_metacast(_clname);
}

int Altimeter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateAltitude((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
