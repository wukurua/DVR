#include <QApplication>
#include <QFile>
#include "view/settingwindow.h"
#include "view/welcomewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //load qss file
    QFile qss(":/qss/style.qss");

    if(qss.open(QFile::ReadOnly))
    {
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }
    else
    {
        qDebug("Open qss file failed!");
    }
    //如果没有设置就进入设置界面,否则直接进入欢迎界面
    SettingController *settingController=new SettingController();
    bool res=settingController->isSettingEmpty();
    if(res==true)
    {
        SettingWindow *settingWin=new SettingWindow;
        settingWin->show();
    }
    else
    {
        WelcomeWindow *welcomeWin=new WelcomeWindow();
        welcomeWin->setObjectName("white");
        welcomeWin->show();
    }
    return a.exec();
}
