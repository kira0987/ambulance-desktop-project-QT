/****************************************************************************
** Meta object code from reading C++ file 'hospital_view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/hospital_view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hospital_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hospital_view_t {
    QByteArrayData data[19];
    char stringdata0[348];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hospital_view_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hospital_view_t qt_meta_stringdata_hospital_view = {
    {
QT_MOC_LITERAL(0, 0, 13), // "hospital_view"
QT_MOC_LITERAL(1, 14, 14), // "on_ADD_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "on_SHOW_clicked"
QT_MOC_LITERAL(4, 46, 18), // "on_reset_2_clicked"
QT_MOC_LITERAL(5, 65, 22), // "on_suppression_clicked"
QT_MOC_LITERAL(6, 88, 17), // "on_MODIFY_clicked"
QT_MOC_LITERAL(7, 106, 17), // "on_tri_id_clicked"
QT_MOC_LITERAL(8, 124, 18), // "on_tri_nom_clicked"
QT_MOC_LITERAL(9, 143, 20), // "on_tri_phone_clicked"
QT_MOC_LITERAL(10, 164, 22), // "on_tri_adresse_clicked"
QT_MOC_LITERAL(11, 187, 23), // "on_tri_capacity_clicked"
QT_MOC_LITERAL(12, 211, 25), // "on_tri_speciality_clicked"
QT_MOC_LITERAL(13, 237, 18), // "on_tri_nbr_clicked"
QT_MOC_LITERAL(14, 256, 19), // "on_tri_date_clicked"
QT_MOC_LITERAL(15, 276, 14), // "on_PDF_clicked"
QT_MOC_LITERAL(16, 291, 19), // "on_calendar_clicked"
QT_MOC_LITERAL(17, 311, 16), // "on_EXCEL_clicked"
QT_MOC_LITERAL(18, 328, 19) // "on_SEARCH_2_clicked"

    },
    "hospital_view\0on_ADD_clicked\0\0"
    "on_SHOW_clicked\0on_reset_2_clicked\0"
    "on_suppression_clicked\0on_MODIFY_clicked\0"
    "on_tri_id_clicked\0on_tri_nom_clicked\0"
    "on_tri_phone_clicked\0on_tri_adresse_clicked\0"
    "on_tri_capacity_clicked\0"
    "on_tri_speciality_clicked\0on_tri_nbr_clicked\0"
    "on_tri_date_clicked\0on_PDF_clicked\0"
    "on_calendar_clicked\0on_EXCEL_clicked\0"
    "on_SEARCH_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hospital_view[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void hospital_view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<hospital_view *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ADD_clicked(); break;
        case 1: _t->on_SHOW_clicked(); break;
        case 2: _t->on_reset_2_clicked(); break;
        case 3: _t->on_suppression_clicked(); break;
        case 4: _t->on_MODIFY_clicked(); break;
        case 5: _t->on_tri_id_clicked(); break;
        case 6: _t->on_tri_nom_clicked(); break;
        case 7: _t->on_tri_phone_clicked(); break;
        case 8: _t->on_tri_adresse_clicked(); break;
        case 9: _t->on_tri_capacity_clicked(); break;
        case 10: _t->on_tri_speciality_clicked(); break;
        case 11: _t->on_tri_nbr_clicked(); break;
        case 12: _t->on_tri_date_clicked(); break;
        case 13: _t->on_PDF_clicked(); break;
        case 14: _t->on_calendar_clicked(); break;
        case 15: _t->on_EXCEL_clicked(); break;
        case 16: _t->on_SEARCH_2_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject hospital_view::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_hospital_view.data,
    qt_meta_data_hospital_view,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *hospital_view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hospital_view::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hospital_view.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int hospital_view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
