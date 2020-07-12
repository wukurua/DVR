#ifndef VIDEOPLAYERWINDOW_H
#define VIDEOPLAYERWINDOW_H

#include <QWidget>
#include <QDateTime>
#include "../tool/fdecode.h"
#include "control/piclabel.h"
#include "../controller/settingcontroller.h"
#include "../controller/videocontroller.h"
#include "../controller/usercontroller.h"
#include "../controller/picturecontroller.h"

class VideoPlayerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit VideoPlayerWindow(QWidget *parent = nullptr);
    ~VideoPlayerWindow();
    QPushButton *btnSnap;
    FDecode *fdecode;
protected:
    void initWidgets();
    void initLayout();
    void initConnect();
    void paintEvent(QPaintEvent *event) override;
private:
    QLabel *lblTime;
    PicLabel *player;
    SettingController *settingController;
    VideoController *videoController;
    UserController *userController;
    PictureController *picController;
signals:
    void breakLoop();
public slots:
    void repeatCamera();
    void addVideo();
    void addPic();
};

#endif // VIDEOPLAYERWIN_H
