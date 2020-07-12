#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QStackedWidget>
#include <QListWidget>
#include "videoplayerwindow.h"
#include "videobackchoosewindow.h"
#include "picchoosewindow.h"
#include "smallsettingwindow.h"
#include "loginwindow.h"
#include "videotranscodewindow.h"

class HomeWindow : public Widget
{
    Q_OBJECT
public:
    explicit HomeWindow(Widget *parent = nullptr);
    ~HomeWindow();
    static bool isLogin;
protected:
    void initWidgets();
    void initLayout();
    void initConnect();
private:
    QListWidget *sideBar;
    QStackedWidget *stackWin;
    VideoPlayerWindow *videoplayerwin;
    VideoBackChooseWindow *videoBackChooseWin;
    PicChooseWindow *picChooseWin;
    SmallSettingWindow *settingWin;
    VideoTranscodeWindow *videoTranscodeWin;
    LoginWindow *loginWin;
    bool isSideBarHidden;
    int currentIndex;
signals:
    void resetVideoTable();
    void resetPicTable();
    void resetTranscodeTable();
    void addPicSignal();
    void startFdecodeSignal();
public slots:
    void changeSideBar(QListWidgetItem *item);
    void checkLogin();
    void setIsLogin(bool isLogin);
    void startFdecode();
};
#endif // HOMEWINDOW_H
