#ifndef USERCONTROLLRT_H
#define USERCONTROLLRT_H

#include <QString>
#include <QCryptographicHash>
#include <QRegExp>
#include <QDebug>
#include "../model/usermodel.h"

class UserController
{
public:
    UserController();
    ~UserController();
    void addUser(QString name,QString pwd,QString tel);
    void addUserLoginRecord(QString name,QString pwd,QString isRememberPwd);
    int searchUserByNameAndPwd(QString name,QString pwd,QString isRememberPwd);
    int searchUserByNameAndPwdInLoginHistoryTable(QString name,QString pwd);
    int searchIdByNameAndPwd(QString name,QString pwd);
    int isNameExist(QString name);
    int isTelRight(QString name,QString tel);
    void setIsRememberPwdByName(QString name, QString isRememberPwd);
    list<User> *getUserList();
    QString getUserNameLoggedRecently();
    QByteArray getUserPwdLoggedRecently(QString name);
    int changePwdByNameAndTel(QString name,QString pwd,QString tel);
    QString getLoginUid();
    QString getLoginUName();
    bool isMatchRegX(QString str);
private:
    UserModel *usermodel;
};

#endif // USERCONTROLLRT_H
