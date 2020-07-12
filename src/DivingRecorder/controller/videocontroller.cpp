#include "videocontroller.h"

VideoController::VideoController()
{
    videoModel=VideoModel::getGetInstance();
}

VideoController::~VideoController()
{
    delete videoModel;
}

void VideoController::addVideo(QString name, QString date, QString path, int size, QString cover, int uid)
{
    QString s=QString::number(size);
    QString id=QString::number(uid);
    videoModel->addVideo(name,date,path,s,cover,id);
}

void VideoController::searchVideoByDate(QString dateBegin, QString dateEnd)
{
    videoModel->searchVideoByDate(dateBegin,dateEnd);
}

int VideoController::searchLastVideo()
{
    if(videoModel->vectorIndex==0)
    {
        int res=videoModel->findLastVideo(videoModel->videoName);
        if(res!=0)
            return 1;
    }
    else
    {
        videoModel->vectorIndex--;
        videoModel->videoName=videoModel->getVideoVector()->at(videoModel->vectorIndex).getName();
        videoModel->videoPath=videoModel->getVideoVector()->at(videoModel->vectorIndex).getPath();
        videoModel->videoSize=videoModel->getVideoVector()->at(videoModel->vectorIndex).getSize();
    }
    return 0;
}

int VideoController::searchNextVideo()
{
    if(videoModel->vectorIndex==(videoModel->getVideoVector()->size()-1))
    {
        int res=videoModel->findNextVideo(videoModel->videoName);
        if(res!=0)
            return 1;
    }
    else
    {
        videoModel->vectorIndex++;
        videoModel->videoName=videoModel->getVideoVector()->at(videoModel->vectorIndex).getName();
        videoModel->videoPath=videoModel->getVideoVector()->at(videoModel->vectorIndex).getPath();
        videoModel->videoSize=videoModel->getVideoVector()->at(videoModel->vectorIndex).getSize();
    }
    return 0;
}

vector<Video> *VideoController::getVideoVector()
{
    return videoModel->getVideoVector();
}

QString VideoController::getVideoPath()
{
    return videoModel->videoPath;
}

QString VideoController::getVideoSize()
{
    return videoModel->videoSize;
}

QString VideoController::getVideoName()
{
    return videoModel->videoName;
}

void VideoController::setVideoPath(QString path)
{
    videoModel->videoPath=path;
}

void VideoController::setVideoSize(QString size)
{
    videoModel->videoSize=size;
}

void VideoController::setVideoName(QString name)
{
    videoModel->videoName=name;
}

int VideoController::getVectorIndex()
{
    return videoModel->vectorIndex;
}

void VideoController::setVectorIndex(int index)
{
    videoModel->vectorIndex=index;
}

