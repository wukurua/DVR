/****************************************************************************
** Meta object code from reading C++ file 'forgetpwdwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../view/forgetpwdwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'forgetpwdwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ForgetPwdWindow_t {
    QByteArrayData data[9];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ForgetPwdWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ForgetPwdWindow_t qt_meta_stringdata_ForgetPwdWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ForgetPwdWindow"
QT_MOC_LITERAL(1, 16, 18), // "showLoginWinSignal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "name"
QT_MOC_LITERAL(4, 41, 3), // "pwd"
QT_MOC_LITERAL(5, 45, 6), // "commit"
QT_MOC_LITERAL(6, 52, 14), // "jumpToLoginWin"
QT_MOC_LITERAL(7, 67, 11), // "refreshCode"
QT_MOC_LITERAL(8, 79, 11) // "setNameSlot"

    },
    "ForgetPwdWindow\0showLoginWinSignal\0\0"
    "name\0pwd\0commit\0jumpToLoginWin\0"
    "refreshCode\0setNameSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ForgetPwdWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   44,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void ForgetPwdWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ForgetPwdWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showLoginWinSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->commit(); break;
        case 2: _t->jumpToLoginWin(); break;
        case 3: _t->refreshCode(); break;
        case 4: _t->setNameSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ForgetPwdWindow::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ForgetPwdWindow::showLoginWinSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ForgetPwdWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<Dialog::staticMetaObject>(),
    qt_meta_stringdata_ForgetPwdWindow.data,
    qt_meta_data_ForgetPwdWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ForgetPwdWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ForgetPwdWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ForgetPwdWindow.stringdata0))
        return static_cast<void*>(this);
    return Dialog::qt_metacast(_clname);
}

int ForgetPwdWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Dialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ForgetPwdWindow::showLoginWinSignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
