#ifndef VIDEOCONTROLLER_H
#define VIDEOCONTROLLER_H

#include "../model/videomodel.h"
#include <QString>

class VideoController
{
public:
    VideoController();
    ~VideoController();
    void addVideo(QString name,QString date,QString path,int size,QString cover,int uid);
    void searchVideoByDate(QString dateBegin,QString dateEnd);
    int searchLastVideo();
    int searchNextVideo();
    vector<Video> *getVideoVector();
    QString getVideoPath();
    QString getVideoSize();
    QString getVideoName();
    void setVideoPath(QString path);
    void setVideoSize(QString size);
    void setVideoName(QString name);
    int getVectorIndex();
    void setVectorIndex(int index);
private:
    VideoModel *videoModel;
};

#endif // VIDEOCONTROLLER_H
