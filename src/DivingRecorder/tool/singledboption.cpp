#include "singledboption.h"

SingleDBOption *SingleDBOption::instance=nullptr;
sqlite3 *SingleDBOption::db=nullptr;
int SingleDBOption::res=0;
char **SingleDBOption::pResult=nullptr;

SingleDBOption *SingleDBOption::getGetInstance()
{
    if(instance==nullptr)
    {
        instance=new SingleDBOption();
    }
    return instance;
}

int SingleDBOption::getTable(QString sql, char **&pResult, int &row, int &col)
{
    res=sqlite3_get_table(db,sql.toStdString().c_str(),&pResult,&row,&col,nullptr);
    res=judgeRes(res);
    if(row!=0&&col!=0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

SingleDBOption::SingleDBOption()
{
    openDataBase("../bin/database/DVR.db");
}

SingleDBOption::~SingleDBOption()
{
    sqlite3_free_table(pResult);
    closeDataBase();
    delete instance;
}

void SingleDBOption::openDataBase(QString dbPath)
{
    res=sqlite3_open(dbPath.toStdString().c_str(),&db);
    if(judgeRes(res)==0)
        cout<<"Open success"<<endl;
    else
        cout<<"Open failed"<<endl;
}

void SingleDBOption::closeDataBase()
{
    res=sqlite3_close(db);
    if(judgeRes(res)==0)
        cout<<"Close success"<<endl;
    else
        cout<<"Close failed"<<endl;
}

int SingleDBOption::judgeRes(int res)
{
    if(res==SQLITE_OK)
    {
        return 0;
    }
    else
    {
        char *errMsg=(char *)sqlite3_errmsg(db);
        cout<<"error msg:"<<errMsg<<endl;
        return 1;
    }
}
