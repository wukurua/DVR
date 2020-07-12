#include "usercontroller.h"

UserController::UserController()
{
    usermodel=UserModel::getGetInstance();
}

UserController::~UserController()
{
    delete usermodel;
}

void UserController::addUser(QString name, QString pwd,QString tel)
{
    QByteArray str=QCryptographicHash::hash(pwd.toLatin1(),QCryptographicHash::Md5);
    QByteArray pwdmd5=str.toHex();
    usermodel->addUserToUserTable(name,pwdmd5,tel);
}

void UserController::addUserLoginRecord(QString name, QString pwd, QString isRememberPwd)
{
    QByteArray str=QCryptographicHash::hash(pwd.toLatin1(),QCryptographicHash::Md5);
    QByteArray pwdmd5=str.toHex();
    usermodel->addUserToLoginHistoryTable(name,pwdmd5,isRememberPwd);
}

int UserController::searchUserByNameAndPwd(QString name, QString pwd,QString isRememberPwd)
{
    QByteArray pwdmd5;
    if(isRememberPwd=="0")
    {
        pwdmd5=pwd.toLatin1();
    }
    else
    {
        QByteArray str=QCryptographicHash::hash(pwd.toLatin1(),QCryptographicHash::Md5);
        pwdmd5=str.toHex();
    }

    list<User>::iterator it=usermodel->getUserList()->begin();
    for(;it!=usermodel->getUserList()->end();++it)
    {
        if(it->getName()==name&&it->getPwd()==pwd)//find this user in cache
        {
            return 0;
        }
    }
    if(it==usermodel->getUserList()->end())//not find in cache
    {
        int res=usermodel->findUserByNameAndPwd(name,pwdmd5);
        if(res==0)//find in table t_user
        {
            //add user to cache
            usermodel->getUserList()->push_back(User(name,pwdmd5,isRememberPwd));
            int row=usermodel->getCountLoginHistoryTable();
            if(row<=6)//5 row + 1 title
            {
                usermodel->addUserToLoginHistoryTable(name,pwdmd5,isRememberPwd);
            }
            else
            {
                //excess the upper limit 5 row
                usermodel->deleteLastUserInLoginHistoryTable();
            }
        }
        else
        {
            return 1;//login failed
        }
    }
    return 0;
}

int UserController::searchUserByNameAndPwdInLoginHistoryTable(QString name, QString pwd)
{
    QByteArray str=QCryptographicHash::hash(pwd.toLatin1(),QCryptographicHash::Md5);
    QByteArray pwdmd5=str.toHex();
    usermodel->findUserByNameAndPwdInLoginHistoryTable(name,pwdmd5);
}

int UserController::searchIdByNameAndPwd(QString name, QString pwd)
{
    return usermodel->findIdByNameAndPwd(name,pwd);
}

int UserController::isNameExist(QString name)
{
    int res=usermodel->isNameExist(name);
    if(res==0)
        return 0;
    else
        return 1;
}

int UserController::isTelRight(QString name, QString tel)
{
    int res=usermodel->isTelRight(name,tel);
    if(res==0)
        return 0;
    else
        return 1;
}

void UserController::setIsRememberPwdByName(QString name, QString isRememberPwd)
{
    usermodel->setIsRememberPwdByName(name,isRememberPwd);
    list<User>::iterator it=usermodel->getUserList()->begin();
    for(;it!=usermodel->getUserList()->end();++it)
    {
        if(it->getName()==name)
        {
            it->setIsRememberPwd(isRememberPwd);
        }
    }
}

list<User> *UserController::getUserList()
{
    return usermodel->getUserList();
}

QString UserController::getUserNameLoggedRecently()
{
    return usermodel->getUserNameLoggedRecently();
}

QByteArray UserController::getUserPwdLoggedRecently(QString name)
{
    QByteArray res=usermodel->getUserPwdLoggedRecently(name).toLatin1();
    return res;
}

int UserController::changePwdByNameAndTel(QString name, QString pwd, QString tel)
{
    QByteArray str=QCryptographicHash::hash(pwd.toLatin1(),QCryptographicHash::Md5);
    QByteArray pwdmd5=str.toHex();
    int res=usermodel->isTelRight(name,tel);
    if(res==0)
    {
        usermodel->changePwdByNameAndTel(name,pwdmd5,tel);
        return 0;
    }
    else
        return 1;
}

QString UserController::getLoginUid()
{
    return usermodel->loginUid;
}

QString UserController::getLoginUName()
{
    return usermodel->loginUName;
}

bool UserController::isMatchRegX(QString str)
{
    QString reg = "^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{6,16}$";
    QRegExp rx(reg);
    bool res=rx.exactMatch(str);
    qDebug()<<reg<<endl;
    qDebug()<<str<<endl;
    qDebug()<<res<<endl;
    return res;
}
