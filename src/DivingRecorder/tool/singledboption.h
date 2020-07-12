#ifndef SINGLEDBOPTION_H
#define SINGLEDBOPTION_H

#include <QString>
#include "../sqlite3/sqlite3.h"
#include <iostream>
using namespace std;

#define SELECT 1
#define INSERT 2
#define UPDATE 3
#define DELETE 4

class SingleDBOption
{
public:
    static SingleDBOption *getGetInstance();
    static int getTable(QString sql,char **&pResult,int &row,int &col);
    static char **pResult;
    static int res;
    ~SingleDBOption();
private:
    SingleDBOption();
    static SingleDBOption *instance;
    void openDataBase(QString dbPath);
    void closeDataBase();
    static int judgeRes(int res);
    static sqlite3 *db;
};

#endif // SINGLEDBOPTION_H
