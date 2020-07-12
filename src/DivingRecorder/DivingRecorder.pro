QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/picturecontroller.cpp \
    controller/settingcontroller.cpp \
    controller/usercontroller.cpp \
    controller/videocontroller.cpp \
    dataclass/picture.cpp \
    dataclass/user.cpp \
    dataclass/video.cpp \
    main.cpp \
    model/picturemodel.cpp \
    model/usermodel.cpp \
    model/videomodel.cpp \
    tool/fdecode.cpp \
    tool/fencode.cpp \
    tool/singledboption.cpp \
    view/control/piclabel.cpp \
    view/control/player.cpp \
    view/control/shownamelabel.cpp \
    view/control/showpicturetable.cpp \
    view/control/showvideotable.cpp \
    view/control/usernamelineedit.cpp \
    view/control/verificationcodelabel.cpp \
    view/dialog.cpp \
    view/forgetpwdwindow.cpp \
    view/homewindow.cpp \
    view/loginwindow.cpp \
    view/picchoosewindow.cpp \
    view/registerwindow.cpp \
    view/settingwindow.cpp \
    view/showpicwindow.cpp \
    view/smallsettingwindow.cpp \
    view/videobackchoosewindow.cpp \
    view/videobackwindow.cpp \
    view/videoplayerwindow.cpp \
    view/videotranscodewindow.cpp \
    view/welcomeitem.cpp \
    view/welcomewindow.cpp \
    view/widget.cpp

HEADERS += \
    controller/picturecontroller.h \
    controller/settingcontroller.h \
    controller/usercontroller.h \
    controller/videocontroller.h \
    dataclass/picture.h \
    dataclass/user.h \
    dataclass/video.h \
    model/picturemodel.h \
    model/usermodel.h \
    model/videomodel.h \
    tool/fdecode.h \
    tool/fencode.h \
    tool/singledboption.h \
    view/control/piclabel.h \
    view/control/player.h \
    view/control/shownamelabel.h \
    view/control/showpicturetable.h \
    view/control/showvideotable.h \
    view/control/usernamelineedit.h \
    view/control/verificationcodelabel.h \
    view/dialog.h \
    view/forgetpwdwindow.h \
    view/homewindow.h \
    view/loginwindow.h \
    view/picchoosewindow.h \
    view/registerwindow.h \
    view/settingwindow.h \
    view/showpicwindow.h \
    view/smallsettingwindow.h \
    view/videobackchoosewindow.h \
    view/videobackwindow.h \
    view/videoplayerwindow.h \
    view/videotranscodewindow.h \
    view/welcomeitem.h \
    view/welcomewindow.h \
    view/widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/ffmpeg/include

LIBS += $$PWD/ffmpeg/lib/avcodec.lib \
        $$PWD/ffmpeg/lib/avdevice.lib \
        $$PWD/ffmpeg/lib/avfilter.lib \
        $$PWD/ffmpeg/lib/avformat.lib \
        $$PWD/ffmpeg/lib/avutil.lib \
        $$PWD/ffmpeg/lib/postproc.lib \
        $$PWD/ffmpeg/lib/swresample.lib \
        $$PWD/ffmpeg/lib/swscale.lib \
        $$PWD/sqlite3/sqlite3.lib

DESTDIR = bin

DISTFILES +=

RESOURCES += \
    img.qrc \
    qss.qrc
