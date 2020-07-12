#include "usermodel.h"

UserModel *UserModel::instance=nullptr;

UserModel *UserModel::getGetInstance()
{
    if(instance==nullptr)
    {
        instance=new UserModel();
    }
    return instance;
}

UserModel::~UserModel()
{
    delete instance;
    delete userList;
}

UserModel::UserModel()
{
    userList=new list<User>;
    InitUserList();
}

list<User> *UserModel::getUserList()
{
    return userList;
}

int UserModel::findUserByNameAndPwd(QString name, QByteArray pwd)
{
    QString sql="SELECT uid,uName FROM t_user WHERE uName='"+name+"' AND pwd='"+pwd+"';";
    int col,row;
    char **pResult;
    int res=SingleDBOption::getTable(sql,pResult,row,col);
    if(res==0)
    {
        this->loginUid=pResult[col];
        this->loginUName=pResult[col+1];
        return 0;
    }
    else
        return 1;
}

int UserModel::findUserByNameAndPwdInLoginHistoryTable(QString name, QByteArray pwd)
{
    QString sql="SELECT uName FROM t_loginHistory WHERE uName='"+name+"' AND pwd='"+pwd+"';";
    int col,row;
    char **pResult;
    int res=SingleDBOption::getTable(sql,pResult,row,col);
    if(res==0)
        return 0;
    else
        return 1;
}

int UserModel::findIdByNameAndPwd(QString name, QString pwd)
{
    QString sql="SELECT uid FROM t_user WHERE uName='"+name+"' AND pwd='"+pwd+"';";
    int col,row;
    char **pResult;
    int res=SingleDBOption::getTable(sql,pResult,row,col);
    QString ret=pResult[col];
    if(res==0)
        return ret.toInt();
    else
        return 0;
}

void UserModel::addUserToUserTable(QString name, QByteArray pwd,QString tel)
{
    int col,row;
    SingleDBOption::getTable("INSERT INTO t_user (uName,pwd,telephone) VALUES('"+name+"','"+pwd+"','"+tel+"')",SingleDBOption::pResult,row,col);
}

void UserModel::addUserToLoginHistoryTable(QString name, QByteArray pwd,QString isRememberPwd)
{
    int col,row;
    char **pResult;
    SingleDBOption::getTable("INSERT INTO t_loginHistory (uName,pwd,isRememberPwd) VALUES('"+name+"','"+pwd+"','"+isRememberPwd+"');",pResult,row,col);
}

void UserModel::deleteLastUserInLoginHistoryTable()
{
    int col,row;
    char **pResult;
    SingleDBOption::getTable("DELETE FROM t_loginHistory WHERE rid=(SELECT rid FROM t_loginHistory LIMIT 1 OFFSET 0);",pResult,row,col);
}

int UserModel::getCountLoginHistoryTable()
{
    int col,row;
    char **pResult;
    SingleDBOption::getTable("SELECT count(rid) FROM t_loginHistory;",pResult,row,col);
    QString str=pResult[col];
    return str.toInt();
}

void UserModel::setIsRememberPwdByName(QString name, QString isRememberPwd)
{
    int col,row;
    char **pResult;
    SingleDBOption::getTable("UPDATE t_loginHistory SET isRememberPwd="+isRememberPwd+" WHERE uName='"+name+"';",pResult,row,col);
}

QString UserModel::getUserNameLoggedRecently()
{
    char **pResult;
    int row,col;
    int res=SingleDBOption::getTable("SELECT uName FROM t_loginHistory ORDER BY rid DESC;",pResult,row,col);
    if(res==0)
    {
        QString str=pResult[col];
        return str;
    }
    else
        return NULL;
}

QString UserModel::getUserPwdLoggedRecently(QString name)
{
    char **pResult;
    int row,col;
    int res=SingleDBOption::getTable("SELECT pwd FROM t_loginHistory WHERE uName='"+name+"' AND isRememberPwd=1;",pResult,row,col);
    if(res==0)
    {
        QString str=pResult[col];
        return str;
    }
    else
        return NULL;
}

int UserModel::isNameExist(QString name)
{
    int row,col;
    int res=SingleDBOption::getTable("SELECT * FROM t_user WHERE uName='"+name+"';",SingleDBOption::pResult,row,col);
    if(res==0)
        return 0;
    else
        return 1;
}

int UserModel::isTelRight(QString name, QString tel)
{
    int row,col;
    int res=SingleDBOption::getTable("SELECT telephone FROM t_user WHERE uName='"+name+"' AND telephone='"+tel+"';",SingleDBOption::pResult,row,col);
    if(res==0)
        return 0;
    else
        return 1;
}

void UserModel::changePwdByNameAndTel(QString name, QByteArray pwd, QString tel)
{
    int row,col;
    QString sql="UPDATE t_user SET pwd='"+pwd+"' WHERE uName='"+name+"' AND telephone='"+tel+"';";
    SingleDBOption::getTable(sql,SingleDBOption::pResult,row,col);
}

void UserModel::InitUserList()
{
    int col,row;
    char **pResult;
    int res=SingleDBOption::getTable("SELECT uName,pwd,isRememberPwd FROM t_loginHistory;",pResult,row,col);
    if(res==0)
    {
        for(int i=col;i<=col*row;i=i+col)
        {
            userList->push_back(User(pResult[i],pResult[i+1],pResult[i+2]));
        }
    }
}


