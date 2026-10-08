/****************************************************************************
** Meta object code from reading C++ file 'integration.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../integration.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'integration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
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
struct qt_meta_stringdata_CLASSintegrationENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSintegrationENDCLASS = QtMocHelpers::stringData(
    "integration",
    "allerPage",
    "",
    "index",
    "goLogin",
    "goSalles",
    "onConnexion",
    "onCGU",
    "onPolitique",
    "onAPropos",
    "onNotifications",
    "onProfil",
    "onDeconnexion",
    "onSuggererSalle",
    "onValiderQR"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSintegrationENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x08,    1 /* Private */,
       4,    0,   89,    2, 0x08,    3 /* Private */,
       5,    0,   90,    2, 0x08,    4 /* Private */,
       6,    0,   91,    2, 0x08,    5 /* Private */,
       7,    0,   92,    2, 0x08,    6 /* Private */,
       8,    0,   93,    2, 0x08,    7 /* Private */,
       9,    0,   94,    2, 0x08,    8 /* Private */,
      10,    0,   95,    2, 0x08,    9 /* Private */,
      11,    0,   96,    2, 0x08,   10 /* Private */,
      12,    0,   97,    2, 0x08,   11 /* Private */,
      13,    0,   98,    2, 0x08,   12 /* Private */,
      14,    0,   99,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
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

Q_CONSTINIT const QMetaObject integration::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSintegrationENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSintegrationENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSintegrationENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<integration, std::true_type>,
        // method 'allerPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'goLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'goSalles'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onConnexion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCGU'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPolitique'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAPropos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onNotifications'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onProfil'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeconnexion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSuggererSalle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onValiderQR'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void integration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<integration *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->allerPage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->goLogin(); break;
        case 2: _t->goSalles(); break;
        case 3: _t->onConnexion(); break;
        case 4: _t->onCGU(); break;
        case 5: _t->onPolitique(); break;
        case 6: _t->onAPropos(); break;
        case 7: _t->onNotifications(); break;
        case 8: _t->onProfil(); break;
        case 9: _t->onDeconnexion(); break;
        case 10: _t->onSuggererSalle(); break;
        case 11: _t->onValiderQR(); break;
        default: ;
        }
    }
}

const QMetaObject *integration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *integration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSintegrationENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int integration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
