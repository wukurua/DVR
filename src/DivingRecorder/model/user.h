#ifndef USER_H
#define USER_H

#include<QString>

class User
{
public:
    User();
    User(QString uname,QString upwd,QString isRememberPwd);
    ~User();
    QString getName();
    QString getPwd();
    QString getIsRememberPwd();
    void setIsRememberPwd(QString isRememberPwd);
    void setPwd(QString pwd);
protected:
    QString name;//用户姓名
    QString pwd;//用户密码
    QString isRememberPwd;
};

#endif // USER_H
