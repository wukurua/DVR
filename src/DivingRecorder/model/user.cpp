#include "user.h"

User::User()
{
    this->name="";
    this->pwd="";
    this->isRememberPwd="";
}

User::User(QString uname, QString upwd, QString isRememberPwd)
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

QString User::getPwd()
{
    return this->pwd;
}

QString User::getIsRememberPwd()
{
    return this->isRememberPwd;
}

void User::setIsRememberPwd(QString isRememberPwd)
{
    this->isRememberPwd=isRememberPwd;
}

void User::setPwd(QString pwd)
{
    this->pwd=pwd;
}
