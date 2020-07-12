/****************************************************************************
** Meta object code from reading C++ file 'homewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../view/homewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'homewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HomeWindow_t {
    QByteArrayData data[14];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HomeWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HomeWindow_t qt_meta_stringdata_HomeWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HomeWindow"
QT_MOC_LITERAL(1, 11, 15), // "resetVideoTable"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "resetPicTable"
QT_MOC_LITERAL(4, 42, 19), // "resetTranscodeTable"
QT_MOC_LITERAL(5, 62, 12), // "addPicSignal"
QT_MOC_LITERAL(6, 75, 18), // "startFdecodeSignal"
QT_MOC_LITERAL(7, 94, 13), // "changeSideBar"
QT_MOC_LITERAL(8, 108, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 125, 4), // "item"
QT_MOC_LITERAL(10, 130, 10), // "checkLogin"
QT_MOC_LITERAL(11, 141, 10), // "setIsLogin"
QT_MOC_LITERAL(12, 152, 7), // "isLogin"
QT_MOC_LITERAL(13, 160, 12) // "startFdecode"

    },
    "HomeWindow\0resetVideoTable\0\0resetPicTable\0"
    "resetTranscodeTable\0addPicSignal\0"
    "startFdecodeSignal\0changeSideBar\0"
    "QListWidgetItem*\0item\0checkLogin\0"
    "setIsLogin\0isLogin\0startFdecode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HomeWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   64,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,
      11,    1,   68,    2, 0x0a /* Public */,
      13,    0,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,

       0        // eod
};

void HomeWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HomeWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resetVideoTable(); break;
        case 1: _t->resetPicTable(); break;
        case 2: _t->resetTranscodeTable(); break;
        case 3: _t->addPicSignal(); break;
        case 4: _t->startFdecodeSignal(); break;
        case 5: _t->changeSideBar((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->checkLogin(); break;
        case 7: _t->setIsLogin((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->startFdecode(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HomeWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomeWindow::resetVideoTable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HomeWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomeWindow::resetPicTable)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HomeWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomeWindow::resetTranscodeTable)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HomeWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomeWindow::addPicSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (HomeWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomeWindow::startFdecodeSignal)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HomeWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<Widget::staticMetaObject>(),
    qt_meta_stringdata_HomeWindow.data,
    qt_meta_data_HomeWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HomeWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HomeWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HomeWindow.stringdata0))
        return static_cast<void*>(this);
    return Widget::qt_metacast(_clname);
}

int HomeWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void HomeWindow::resetVideoTable()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HomeWindow::resetPicTable()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HomeWindow::resetTranscodeTable()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void HomeWindow::addPicSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void HomeWindow::startFdecodeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
