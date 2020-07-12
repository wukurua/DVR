#include "videomodel.h"

VideoModel *VideoModel::instance=nullptr;

VideoModel::VideoModel()
{
    videoVector=new vector<Video>;
    InitVideoVector();
}

void VideoModel::InitVideoVector()
{
    int col,row;
    char **pResult;
    QString datetime = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    int res=SingleDBOption::getTable("SELECT vName,date,path,size,cover,uid FROM t_video WHERE date='"+datetime+"';",pResult,row,col);
    if(res==0)
    {
        for(int i=col;i<=col*row;i=i+col)
        {
            videoVector->push_back(Video(pResult[i],pResult[i+1],pResult[i+2],pResult[i+3],pResult[i+4],pResult[i+5]));
        }
    }
}

void VideoModel::addVideo(QString name, QString date, QString path, QString size, QString cover, QString uid)
{
    int col,row;
    QString sql="INSERT INTO t_video (vName,date,path,size,cover,uid) VALUES('"+name+"','"+date+"','"+path+"',"+size+",'"+cover+"',"+uid+");";
    SingleDBOption::getTable(sql,SingleDBOption::pResult,row,col);
}

void VideoModel::searchVideoByDate(QString dateBegin, QString dateEnd)
{
    int col,row;
    char **pResult;
    QString sql="SELECT vName,date,path,size,cover,uid FROM t_video WHERE date BETWEEN '"+dateBegin+"' AND '"+dateEnd+"';";
    int res=SingleDBOption::getTable(sql,pResult,row,col);
    if(res==0)
    {
        videoVector->clear();
        for(int i=col;i<=col*row;i=i+col)
        {
            videoVector->push_back(Video(pResult[i],pResult[i+1],pResult[i+2],pResult[i+3],pResult[i+4],pResult[i+5]));
        }
    }
}

VideoModel *VideoModel::getGetInstance()
{
    if(instance==nullptr)
    {
        instance=new VideoModel();
    }
    return instance;
}

vector<Video> *VideoModel::getVideoVector()
{
    return this->videoVector;
}

int VideoModel::findLastVideo(QString name)
{
    int col,row;
    char **pResult;
    QString sql="SELECT vName,path,size FROM t_video WHERE vName<'"+name+"' ORDER BY vName DESC LIMIT 1 OFFSET 0;";
    int res=SingleDBOption::getTable(sql,pResult,row,col);
    if(res==0)
    {
        this->videoName=pResult[col];
        this->videoPath=pResult[col+1];
        this->videoSize=pResult[col+2];
        return 0;
    }
    else
        return 1;
}

int VideoModel::findNextVideo(QString name)
{
    int col,row;
    char **pResult;
    QString sql="SELECT vName,path,size FROM t_video WHERE vName>'"+name+"' ORDER BY vName ASC LIMIT 1 OFFSET 0;";
    int res=SingleDBOption::getTable(sql,pResult,row,col);
    if(res==0)
    {
        this->videoName=pResult[col];
        this->videoPath=pResult[col+1];
        this->videoSize=pResult[col+2];
        return 0;
    }
    else
        return 1;
}

VideoModel::~VideoModel()
{
    delete videoVector;
}
