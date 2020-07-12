#include "picturecontroller.h"

PictureController::PictureController()
{
    picModel=PictureModel::getGetInstance();
}

PictureController::~PictureController()
{
    delete picModel;
}

void PictureController::addPic(QString name, QString date, QString path, int uid)
{
    QString id=QString::number(uid);
    picModel->addPic(name,date,path,id);
}

void PictureController::searchPicByDate(QString dateBegin, QString dateEnd)
{
    picModel->searchPicByDate(dateBegin,dateEnd);
}

int PictureController::searchLastPic()
{
    if(picModel->vectorIndex==0)
    {
        int res=picModel->findLastPic(picModel->picName);
        if(res!=0)
            return 1;
    }
    else
    {
        picModel->vectorIndex--;
        picModel->picName=picModel->getPicVector()->at(picModel->vectorIndex).getName();
        picModel->picPath=picModel->getPicVector()->at(picModel->vectorIndex).getPath();

    }
    return 0;
}

int PictureController::searchNextPic()
{
    if(picModel->vectorIndex==(picModel->getPicVector()->size()-1))
    {
        int res=picModel->findNextPic(picModel->picName);
        if(res!=0)
            return 1;
    }
    else
    {
        picModel->vectorIndex++;
        picModel->picName=picModel->getPicVector()->at(picModel->vectorIndex).getName();
        picModel->picPath=picModel->getPicVector()->at(picModel->vectorIndex).getPath();

    }
    return 0;
}

vector<Picture> *PictureController::getPicVector()
{
    return picModel->getPicVector();
}

QString PictureController::getPicPath()
{
    return picModel->picPath;
}

QString PictureController::getPicName()
{
    return picModel->picName;
}

void PictureController::setPicPath(QString path)
{
    picModel->picPath=path;
}

void PictureController::setPicName(QString name)
{
    picModel->picName=name;
}

int PictureController::getVectorIndex()
{
    return picModel->vectorIndex;
}

void PictureController::setVectorIndex(int index)
{
    picModel->vectorIndex=index;
}

