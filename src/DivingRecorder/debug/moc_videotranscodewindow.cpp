/****************************************************************************
** Meta object code from reading C++ file 'videotranscodewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../view/videotranscodewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videotranscodewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoTranscodeWindow_t {
    QByteArrayData data[12];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoTranscodeWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoTranscodeWindow_t qt_meta_stringdata_VideoTranscodeWindow = {
    {
QT_MOC_LITERAL(0, 0, 20), // "VideoTranscodeWindow"
QT_MOC_LITERAL(1, 21, 16), // "resetVideoRecord"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 17), // "searchVideoRecord"
QT_MOC_LITERAL(4, 57, 16), // "playVideoChoosed"
QT_MOC_LITERAL(5, 74, 3), // "row"
QT_MOC_LITERAL(6, 78, 3), // "col"
QT_MOC_LITERAL(7, 82, 14), // "chooseSavePath"
QT_MOC_LITERAL(8, 97, 9), // "transcode"
QT_MOC_LITERAL(9, 107, 14), // "setProBarValue"
QT_MOC_LITERAL(10, 122, 8), // "nowframe"
QT_MOC_LITERAL(11, 131, 16) // "setTranscodeDone"

    },
    "VideoTranscodeWindow\0resetVideoRecord\0"
    "\0searchVideoRecord\0playVideoChoosed\0"
    "row\0col\0chooseSavePath\0transcode\0"
    "setProBarValue\0nowframe\0setTranscodeDone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoTranscodeWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x0a /* Public */,
       4,    2,   51,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,
       9,    1,   58,    2, 0x0a /* Public */,
      11,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

       0        // eod
};

void VideoTranscodeWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoTranscodeWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resetVideoRecord(); break;
        case 1: _t->searchVideoRecord(); break;
        case 2: _t->playVideoChoosed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->chooseSavePath(); break;
        case 4: _t->transcode(); break;
        case 5: _t->setProBarValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setTranscodeDone(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoTranscodeWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoTranscodeWindow::resetVideoRecord)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VideoTranscodeWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_VideoTranscodeWindow.data,
    qt_meta_data_VideoTranscodeWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VideoTranscodeWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoTranscodeWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoTranscodeWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VideoTranscodeWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void VideoTranscodeWindow::resetVideoRecord()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
