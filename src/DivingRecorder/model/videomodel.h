#ifndef VIDEOMODEL_H
#define VIDEOMODEL_H

#include "../tool/singledboption.h"
#include "../dataclass/video.h"
#include <vector>
#include <QDateTime>

class VideoModel
{
public:
    void addVideo(QString name,QString date,QString path,QString size,QString cover,QString uid);
    void searchVideoByDate(QString dateBegin,QString dateEnd);
    static VideoModel *getGetInstance();
    vector<Video> *getVideoVector();
    int findLastVideo(QString name);
    int findNextVideo(QString name);
    QString videoPath;
    QString videoName;
    QString videoSize;
    int vectorIndex;
    ~VideoModel();
private:
    VideoModel();
    void InitVideoVector();
    static VideoModel *instance;
    vector<Video> *videoVector;
};
#endif // VIDEOMODEL_H
