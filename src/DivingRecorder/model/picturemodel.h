#ifndef PICTUREMODEL_H
#define PICTUREMODEL_H

#include "../tool/singledboption.h"
#include "../dataclass/picture.h"
#include <vector>
#include <QDateTime>

class PictureModel
{
public:
    void addPic(QString name,QString date,QString path,QString uid);
    void searchPicByDate(QString dateBegin,QString dateEnd);
    static PictureModel *getGetInstance();
    vector<Picture> *getPicVector();
    int findLastPic(QString name);
    int findNextPic(QString name);
    QString picPath;
    QString picName;
    int vectorIndex;
    ~PictureModel();
private:
    PictureModel();
    void InitPicVector();
    static PictureModel *instance;
    vector<Picture> *picVector;
};

#endif // PICTUREMODEL_H
