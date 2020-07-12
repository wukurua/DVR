#include "picture.h"

Picture::Picture()
{
    this->name="";
    this->date="";
    this->path="";
    this->uid="";
}

Picture::Picture(QString name, QString date, QString path, QString uid)
{
    this->name=name;
    this->date=date;
    this->path=path;
    this->uid=uid;
}

Picture::~Picture()
{

}

QString Picture::getName()
{
    return this->name;
}

QString Picture::getDate()
{
    return this->date;
}

QString Picture::getPath()
{
    return this->path;
}
