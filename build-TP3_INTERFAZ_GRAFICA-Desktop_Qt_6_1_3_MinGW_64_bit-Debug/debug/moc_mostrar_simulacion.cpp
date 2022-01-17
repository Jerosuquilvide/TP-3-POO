/****************************************************************************
** Meta object code from reading C++ file 'mostrar_simulacion.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../TP3_INTERFAZ_GRAFICA/mostrar_simulacion.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mostrar_simulacion.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mostrar_Simulacion_t {
    const uint offsetsAndSize[16];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Mostrar_Simulacion_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Mostrar_Simulacion_t qt_meta_stringdata_Mostrar_Simulacion = {
    {
QT_MOC_LITERAL(0, 18), // "Mostrar_Simulacion"
QT_MOC_LITERAL(19, 26), // "on_SalirSimulacion_clicked"
QT_MOC_LITERAL(46, 0), // ""
QT_MOC_LITERAL(47, 28), // "on_GuardarSimulacion_clicked"
QT_MOC_LITERAL(76, 29), // "on_EjecutarSimulacion_clicked"
QT_MOC_LITERAL(106, 27), // "on_PausarSimulacion_clicked"
QT_MOC_LITERAL(134, 5), // "MTime"
QT_MOC_LITERAL(140, 11) // "incrementar"

    },
    "Mostrar_Simulacion\0on_SalirSimulacion_clicked\0"
    "\0on_GuardarSimulacion_clicked\0"
    "on_EjecutarSimulacion_clicked\0"
    "on_PausarSimulacion_clicked\0MTime\0"
    "incrementar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mostrar_Simulacion[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    0 /* Private */,
       3,    0,   51,    2, 0x08,    1 /* Private */,
       4,    0,   52,    2, 0x08,    2 /* Private */,
       5,    0,   53,    2, 0x08,    3 /* Private */,
       6,    0,   54,    2, 0x08,    4 /* Private */,
       7,    0,   55,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Mostrar_Simulacion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mostrar_Simulacion *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_SalirSimulacion_clicked(); break;
        case 1: _t->on_GuardarSimulacion_clicked(); break;
        case 2: _t->on_EjecutarSimulacion_clicked(); break;
        case 3: _t->on_PausarSimulacion_clicked(); break;
        case 4: _t->MTime(); break;
        case 5: _t->incrementar(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject Mostrar_Simulacion::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Mostrar_Simulacion.offsetsAndSize,
    qt_meta_data_Mostrar_Simulacion,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Mostrar_Simulacion_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Mostrar_Simulacion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mostrar_Simulacion::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mostrar_Simulacion.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Mostrar_Simulacion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
