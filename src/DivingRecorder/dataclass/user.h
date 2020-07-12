#ifndef USER_H
#define USER_H

#include<QString>

class User
{
public:
    User();
    User(QString uname,QByteArray upwd,QString isRememberPwd);
    ~User();
    QString getName();
    QByteArray getPwd();
    QString getIsRememberPwd();
    void setName(QString uname);
    void setIsRememberPwd(QString isRememberPwd);
    void setPwd(QByteArray pwd);
protected:
    QString name;//用户姓名
    QByteArray pwd;//用户密码
    QString isRememberPwd;
};

#endif // USER_H
