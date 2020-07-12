#ifndef FENCODE_H
#define FENCODE_H

extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libavutil/pixfmt.h>
    #include <libavdevice/avdevice.h>
}

#include <QDateTime>
#include <QString>
#include <QDebug>
#include <QThread>
#include <QQueue>

class FEncode : public QThread
{
public:
    FEncode();
    ~FEncode();
    void run() override;
    void initEncode(int width,int height);
    void encodeFrame(AVFrame *frame);
    void write_tailer();
    QString fileName;//the file that will deal with
    QString dstDir;//destination folder
    QString videoName;
    QString date;
    QString path;
    QString datetime;
    QQueue<AVFrame*> frameQueue;
    int frameNum;
private:
    AVCodecContext *codec;
    AVPacket *avpkt;
    AVFormatContext *fmatc;
};

#endif // FENCODE_H
