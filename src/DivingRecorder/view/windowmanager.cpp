#include "windowmanager.h"

WindowManager *WindowManager::instance=nullptr;

WindowManager *WindowManager::getInstance()
{
    if(instance==nullptr)
    {
        instance=new WindowManager();
    }
    return instance;
}

WindowManager::~WindowManager()
{
    delete settingWin;
    delete homeWin;
    delete welcomeWin;
    delete stackWin;
}

WindowManager::WindowManager()
{
    stackWin=new QStackedWidget;
    welcomeWin=new WelcomeWindow;
    welcomeWin->setObjectName("white");
    settingWin=new SettingWindow;
    homeWin=new HomeWindow;
    stackWin->addWidget(settingWin);
    stackWin->addWidget(welcomeWin);
    stackWin->addWidget(homeWin);
}
