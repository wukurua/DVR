#ifndef PICTURECONTROLLER_H
#define PICTURECONTROLLER_H

#include "../model/picturemodel.h"
#include <QString>

class PictureController
{
public:
    PictureController();
    ~PictureController();
    void addPic(QString name,QString date,QString path,int uid);
    void searchPicByDate(QString dateBegin,QString dateEnd);
    int searchLastPic();
    int searchNextPic();
    vector<Picture> *getPicVector();
    QString getPicPath();
    QString getPicName();
    void setPicPath(QString path);
    void setPicSize(QString size);
    void setPicName(QString name);
    int getVectorIndex();
    void setVectorIndex(int index);
private:
    PictureModel *picModel;
};

#endif // PICTURECONTROLLER_H
