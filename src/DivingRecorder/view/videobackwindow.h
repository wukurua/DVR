#ifndef VIDEOBACKWINDOW_H
#define VIDEOBACKWINDOW_H

#include "control/player.h"
#include "widget.h"
#include "../tool/fdecode.h"

class VideoBackWindow : public Widget
{
    Q_OBJECT
public:
    explicit VideoBackWindow(Widget *parent = nullptr);
    ~VideoBackWindow();
protected:
    void initWidgets();
    void initLayout();
    void initConnect();
private:
    QPushButton *btnOutput;
    Player *player;
    QFileDialog *openvideo;
    VideoController *videoController;
    SettingController *settingController;
    FDecode *fdecode;
signals:
    void showChooseWin();
    void beginPlaySignal();
public slots:
    void setVideoBackWinName();
    void transcode();
};

#endif // VIDEOPLAYBACKWINDOW_H
