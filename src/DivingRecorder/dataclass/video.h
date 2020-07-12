#ifndef VIDEO_H
#define VIDEO_H

#include<QString>

class Video
{
public:
    Video();
    Video(QString name,QString date,QString path,QString size,QString cover,QString uid);
    ~Video();
    QString getName();
    QString getDate();
    QString getCover();
    QString getSize();
    QString getPath();
protected:
    QString name;
    QString date;
    QString path;
    QString size;
    QString cover;
    QString uid;
};

#endif // VIDEO_H
