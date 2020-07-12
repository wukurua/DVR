#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "homewindow.h"
#include "settingwindow.h"
#include "welcomewindow.h"
#include <QStackedWidget>
using namespace std;

#define SETTINGWIN 0
#define WELCOMEWIN 1
#define HOMEWIN 2

class WindowManager : public QStackedWidget
{
public:
    QStackedWidget *stackWin;
    static WindowManager *getInstance();
    ~WindowManager();
private:
    WindowManager();
    static WindowManager *instance;
    WelcomeWindow *welcomeWin;
    SettingWindow *settingWin;
    HomeWindow *homeWin;
};

#endif // WINDOWMANAGER_H
