#ifndef FDECODE_H
#define FDECODE_H

#include <QImage>
#include <QThread>
#include <QMutex>
#include "fencode.h"

#define TO_RGB 1
#define H264_TO_MP4 2
#define H264_TO_AVI 3
#define H264_TO_MOV 4
#define CAMERA 5

class FDecode : public QThread
{
    Q_OBJECT
public:
    FDecode();
    ~FDecode();
    void run() override;
    void stop();
    void resume();

    QString cameraName;
    QString fileName;//the file that will deal with
    QString dstDir;//the destination folder of video
    int videoSize;//the size of video
    QString videoName;//generate while encoding

    QImage cover;//the cover of video
    QString coverPath;//the path of cover

    QString picdstDir;//the destination folder of picture
    QString date;
    QString path;
    QString datetime;
    int duration;
    int playSpeed;
    int choose;//process type

    bool isBreak;
private:
    void registerFFMPEG();
    void to_RGB();
    void H264_to_Video();
    void open_camera();

    FEncode *fev;
    AVFormatContext *fmatC;
    AVCodecContext *codecContext;
    AVCodec *codec;
    AVPacket *acPkt;
    AVFrame *picture,*dstFrame,*dstFrame1;
    int videoIndex;
    int got_picture_ptr;
    int size;

    QMutex m_lock;
signals:
    void sendImageAndNum(QImage,int);
    void sendNum(int);
    void sendImage(QImage);
    void addVideo();
    void setVideoFinish();
    void transcodeDone();
    void repeatCam();
public slots:
    void breakThread();
};

#endif // FDECODE_H
