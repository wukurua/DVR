#include "settingcontroller.h"

SettingController::SettingController()
{
    sDBOptin=SingleDBOption::getGetInstance();
}

SettingController::~SettingController()
{
    delete sDBOptin;
}

bool SettingController::isSettingEmpty()
{
    int row,col;
    int res=SingleDBOption::getTable("SELECT * FROM t_setting;",SingleDBOption::pResult,row,col);
    if(res==0)
        return false;
    else
        return true;
}

void SettingController::changeSetting(QString videoPath, QString picPath, int duration, QString camera)
{
    int row,col;
    SingleDBOption::getTable("INSERT OR REPLACE INTO t_setting (sid,videoPath,picPath,duration,camera) "
                             "VALUES(1,'"+videoPath+"','"+picPath+"',"+duration+",'"+camera+"');",
                             SingleDBOption::pResult,row,col);
}

QString SettingController::getVideoPath()
{
    int col,row;
    char **pResult;
    SingleDBOption::getTable("SELECT videoPath FROM t_setting;",pResult,row,col);
    QString ret=pResult[col];
    return ret;
}

QString SettingController::getPicPath()
{
    int col,row;
    char **pResult;
    SingleDBOption::getTable("SELECT picPath FROM t_setting;",pResult,row,col);
    QString ret=pResult[col];
    return ret;
}

QString SettingController::getDuration()
{
    int col,row;
    char **pResult;
    SingleDBOption::getTable("SELECT duration FROM t_setting;",pResult,row,col);
    QString ret=pResult[col];
    return ret;
}

QString SettingController::getCamera()
{
    int col,row;
    char **pResult;
    SingleDBOption::getTable("SELECT camera FROM t_setting;",pResult,row,col);
    QString ret=pResult[col];
    return ret;
}
