/****************************************************************************
** Meta object code from reading C++ file 'picchoosewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../view/picchoosewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'picchoosewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PicChooseWindow_t {
    QByteArrayData data[8];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PicChooseWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PicChooseWindow_t qt_meta_stringdata_PicChooseWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PicChooseWindow"
QT_MOC_LITERAL(1, 16, 14), // "resetPicRecord"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "setShowPicWinImage"
QT_MOC_LITERAL(4, 51, 15), // "searchPicRecord"
QT_MOC_LITERAL(5, 67, 14), // "playPicChoosed"
QT_MOC_LITERAL(6, 82, 3), // "row"
QT_MOC_LITERAL(7, 86, 3) // "col"

    },
    "PicChooseWindow\0resetPicRecord\0\0"
    "setShowPicWinImage\0searchPicRecord\0"
    "playPicChoosed\0row\0col"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PicChooseWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x0a /* Public */,
       5,    2,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,

       0        // eod
};

void PicChooseWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PicChooseWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resetPicRecord(); break;
        case 1: _t->setShowPicWinImage(); break;
        case 2: _t->searchPicRecord(); break;
        case 3: _t->playPicChoosed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PicChooseWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PicChooseWindow::resetPicRecord)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PicChooseWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PicChooseWindow::setShowPicWinImage)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PicChooseWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PicChooseWindow.data,
    qt_meta_data_PicChooseWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PicChooseWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PicChooseWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PicChooseWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PicChooseWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PicChooseWindow::resetPicRecord()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PicChooseWindow::setShowPicWinImage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
