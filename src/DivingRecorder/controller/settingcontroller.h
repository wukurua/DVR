#ifndef SETTINGCONTROLLER_H
#define SETTINGCONTROLLER_H

#include <QString>
#include "../tool/singledboption.h"

class SettingController
{
public:
    SettingController();
    ~SettingController();
    bool isSettingEmpty();
    void changeSetting(QString videoPath,QString picPath,int duration, QString camera);
    QString getVideoPath();
    QString getPicPath();
    QString getDuration();
    QString getCamera();
private:
    SingleDBOption *sDBOptin;
};

#endif // SETTINGCONTROLLER_H
