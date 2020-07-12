#include "user.h"

User::User()
{
    this->name="";
    this->pwd="";
    this->isRememberPwd="";
}

User::User(QString uname,QByteArray upwd,QString isRememberPwd)
{
    this->name=uname;
    this->pwd=upwd;
    this->isRememberPwd=isRememberPwd;
}

User::~User()
{

}

QString User::getName()
{
    return this->name;
}

QByteArray User::getPwd()
{
    return this->pwd;
}

QString User::getIsRememberPwd()
{
    return this->isRememberPwd;
}

void User::setName(QString uname)
{
    this->name=uname;
}

void User::setIsRememberPwd(QString isRememberPwd)
{
    this->isRememberPwd=isRememberPwd;
}

void User::setPwd(QByteArray pwd)
{
    this->pwd=pwd;
}
