#ifndef SINGLEDATA_H
#define SINGLEDATA_H

#include "../tool/singledboption.h"
#include "../dataclass/user.h"
#include <list>

class UserModel
{
public:
    static UserModel *getGetInstance();
    list<User> *getUserList();
    QString loginUid;
    QString loginUName;
    int findUserByNameAndPwd(QString name,QByteArray pwd);
    int findUserByNameAndPwdInLoginHistoryTable(QString name,QByteArray pwd);
    int findIdByNameAndPwd(QString name,QString pwd);
    void addUserToUserTable(QString name,QByteArray pwd,QString tel);
    void addUserToLoginHistoryTable(QString name,QByteArray pwd,QString isRememberPwd);
    void deleteLastUserInLoginHistoryTable();
    int getCountLoginHistoryTable();
    void setIsRememberPwdByName(QString name,QString isRememberPwd);
    QString getUserNameLoggedRecently();
    QString getUserPwdLoggedRecently(QString name);
    int isNameExist(QString name);
    int isTelRight(QString name,QString tel);
    void changePwdByNameAndTel(QString name,QByteArray pwd,QString tel);
    ~UserModel();
private:
    UserModel();
    void InitUserList();
    static UserModel *instance;
    list<User> *userList;
};

#endif // SINGLEDATA_H
