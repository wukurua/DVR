/****************************************************************************
** Meta object code from reading C++ file 'player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../view/control/player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Player_t {
    QByteArrayData data[17];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Player_t qt_meta_stringdata_Player = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Player"
QT_MOC_LITERAL(1, 7, 12), // "breakFDecode"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 12), // "receiveImage"
QT_MOC_LITERAL(4, 34, 3), // "img"
QT_MOC_LITERAL(5, 38, 18), // "receiveImageAndNum"
QT_MOC_LITERAL(6, 57, 8), // "nowframe"
QT_MOC_LITERAL(7, 66, 12), // "changeIsPlay"
QT_MOC_LITERAL(8, 79, 7), // "checked"
QT_MOC_LITERAL(9, 87, 14), // "setVideoFinish"
QT_MOC_LITERAL(10, 102, 9), // "beginPlay"
QT_MOC_LITERAL(11, 112, 11), // "playLastOne"
QT_MOC_LITERAL(12, 124, 11), // "playNextOne"
QT_MOC_LITERAL(13, 136, 11), // "closeWindow"
QT_MOC_LITERAL(14, 148, 6), // "addPic"
QT_MOC_LITERAL(15, 155, 15), // "setFDecodeSpeed"
QT_MOC_LITERAL(16, 171, 4) // "text"

    },
    "Player\0breakFDecode\0\0receiveImage\0img\0"
    "receiveImageAndNum\0nowframe\0changeIsPlay\0"
    "checked\0setVideoFinish\0beginPlay\0"
    "playLastOne\0playNextOne\0closeWindow\0"
    "addPic\0setFDecodeSpeed\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Player[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   70,    2, 0x0a /* Public */,
       5,    2,   73,    2, 0x0a /* Public */,
       7,    1,   78,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,
      14,    0,   86,    2, 0x0a /* Public */,
      15,    1,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    4,
    QMetaType::Void, QMetaType::QImage, QMetaType::Int,    4,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void Player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Player *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->breakFDecode(); break;
        case 1: _t->receiveImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->receiveImageAndNum((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->changeIsPlay((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setVideoFinish(); break;
        case 5: _t->beginPlay(); break;
        case 6: _t->playLastOne(); break;
        case 7: _t->playNextOne(); break;
        case 8: _t->closeWindow(); break;
        case 9: _t->addPic(); break;
        case 10: _t->setFDecodeSpeed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player::breakFDecode)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Player::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_Player.data,
    qt_meta_data_Player,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Player::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Player.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Player::breakFDecode()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
