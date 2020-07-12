#include "video.h"

Video::Video()
{
    this->name="";
    this->date="";
    this->path="";
    this->size="";
    this->cover="";
    this->uid="";
}

Video::Video(QString name, QString date, QString path, QString size, QString cover, QString uid)
{
    this->name=name;
    this->date=date;
    this->path=path;
    this->size=size;
    this->cover=cover;
    this->uid=uid;
}

Video::~Video()
{

}

QString Video::getName()
{
    return this->name;
}

QString Video::getDate()
{
    return this->date;
}

QString Video::getSize()
{
    return this->size;
}

QString Video::getPath()
{
    return this->path;
}

QString Video::getCover()
{
    return this->cover;
}
