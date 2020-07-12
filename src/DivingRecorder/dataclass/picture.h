#ifndef PICTURE_H
#define PICTURE_H

#include<QString>

class Picture
{
public:
    Picture();
    Picture(QString name,QString date,QString path,QString uid);
    ~Picture();
    QString getName();
    QString getDate();
    QString getPath();
protected:
    QString name;
    QString date;
    QString path;
    QString uid;
};


#endif // PICTURE_H
