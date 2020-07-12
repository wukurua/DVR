#include "picturemodel.h"

PictureModel *PictureModel::instance=nullptr;

PictureModel::PictureModel()
{
    picVector=new vector<Picture>;
    InitPicVector();
}

void PictureModel::InitPicVector()
{
    int col,row;
    char **pResult;
    QString datetime = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    int res=SingleDBOption::getTable("SELECT pName,date,path,uid FROM t_picture WHERE date='"+datetime+"';",pResult,row,col);
    if(res==0)
    {
        for(int i=col;i<=col*row;i=i+col)
        {
            picVector->push_back(Picture(pResult[i],pResult[i+1],pResult[i+2],pResult[i+3]));
        }
    }
}

void PictureModel::addPic(QString name, QString date, QString path, QString uid)
{
    int col,row;
    QString sql="INSERT INTO t_picture (pName,date,path,uid) VALUES('"+name+"','"+date+"','"+path+"',"+uid+");";
    SingleDBOption::getTable(sql,SingleDBOption::pResult,row,col);
}

void PictureModel::searchPicByDate(QString dateBegin, QString dateEnd)
{
    int col,row;
    char **pResult;
    QString sql="SELECT pName,date,path,uid FROM t_picture WHERE date BETWEEN '"+dateBegin+"' AND '"+dateEnd+"';";
    int res=SingleDBOption::getTable(sql,pResult,row,col);
    if(res==0)
    {
        picVector->clear();
        for(int i=col;i<=col*row;i=i+col)
        {
            picVector->push_back(Picture(pResult[i],pResult[i+1],pResult[i+2],pResult[i+3]));
        }
    }
}

PictureModel *PictureModel::getGetInstance()
{
    if(instance==nullptr)
    {
        instance=new PictureModel();
    }
    return instance;
}

vector<Picture> *PictureModel::getPicVector()
{
    return this->picVector;
}

int PictureModel::findLastPic(QString name)
{
    int col,row;
    char **pResult;
    QString sql="SELECT pName,path FROM t_picture WHERE pName<'"+name+"' ORDER BY pName DESC LIMIT 1 OFFSET 0;";
    int res=SingleDBOption::getTable(sql,pResult,row,col);
    if(res==0)
    {
        this->picName=pResult[col];
        this->picPath=pResult[col+1];
        return 0;
    }
    else
        return 1;
}

int PictureModel::findNextPic(QString name)
{
    int col,row;
    char **pResult;
    QString sql="SELECT pName,path FROM t_picture WHERE pName>'"+name+"' ORDER BY pName ASC LIMIT 1 OFFSET 0;";
    int res=SingleDBOption::getTable(sql,pResult,row,col);
    if(res==0)
    {
        this->picName=pResult[col];
        this->picPath=pResult[col+1];
        return 0;
    }
    else
        return 1;
}

PictureModel::~PictureModel()
{
    delete picVector;
}
