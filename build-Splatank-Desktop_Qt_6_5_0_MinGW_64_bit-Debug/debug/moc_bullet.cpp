/****************************************************************************
** Meta object code from reading C++ file 'bullet.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Splatank/bullet.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bullet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSBulletENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSBulletENDCLASS = QtMocHelpers::stringData(
    "Bullet",
    "moveBy",
    ""
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSBulletENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[7];
    char stringdata1[7];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSBulletENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSBulletENDCLASS_t qt_meta_stringdata_CLASSBulletENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Bullet"
        QT_MOC_LITERAL(7, 6),  // "moveBy"
        QT_MOC_LITERAL(14, 0)   // ""
    },
    "Bullet",
    "moveBy",
    ""
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBulletENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Bullet::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSBulletENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBulletENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBulletENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Bullet, std::true_type>,
        // method 'moveBy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Bullet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Bullet *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->moveBy(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Bullet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Bullet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBulletENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Bullet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
