#include "fencode.h"

FEncode::FEncode()
{

}

FEncode::~FEncode()
{
    avformat_free_context(fmatc);
    avcodec_close(codec);
    avformat_close_input(&fmatc);
    av_free_packet(avpkt);
}

void FEncode::run()
{
    while(!frameQueue.empty())
    {
        AVFrame *fm=frameQueue.head();
        this->encodeFrame(fm);
        frameQueue.dequeue();
    }
}

void FEncode::initEncode(int width,int height)
{
    datetime = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
    date=QDateTime::currentDateTime().toString("yyyy-MM-dd");
    videoName=datetime+".h264";
    path=dstDir+"/"+videoName;
    AVOutputFormat *avOfmat=av_guess_format(NULL,path.toStdString().c_str(),NULL);
    if(NULL==avOfmat)
    {
        qDebug()<<"guess failed!"<<endl;
        return;
    }

    fmatc=avformat_alloc_context();
    fmatc->oformat=avOfmat;
    int res=-1;
    res=avio_open(&fmatc->pb,path.toStdString().c_str(),AVIO_FLAG_WRITE);
    if(res<0)
    {
        qDebug()<<"avio_open failed!"<<endl;
        return;
    }

    AVStream *outStream=avformat_new_stream(fmatc,NULL);
    if(NULL==outStream)
    {
        qDebug()<<"new Stream failed!"<<endl;
        return;
    }

    //init data
    codec=outStream->codec;
    codec->width=width;
    codec->height=height;
    codec->bit_rate=4000000;//the number of bit per sec
    codec->time_base={1,25};// - encoding: MUST be set by user.
    codec->framerate={25,1};
    codec->gop_size=10;//the number of pic in per group
    codec->qmax=51;
    codec->qmin=10;
    codec->max_b_frames=0;
    codec->pix_fmt=AV_PIX_FMT_YUV420P;
    codec->codec_type=AVMEDIA_TYPE_VIDEO;
    codec->codec_id=avOfmat->video_codec;

    AVCodec *code=avcodec_find_encoder(codec->codec_id);
    if(NULL==code)
    {
        qDebug()<<"find encoder failed!"<<endl;
        return;
    }

    res=avcodec_open2(codec,code,NULL);
    if(res!=0)
    {
        qDebug()<<"open encoder failed!"<<endl;
        return;
    }

    res=avformat_write_header(fmatc,NULL);
    if(res<0)
    {
        qDebug()<<"write header failed!"<<endl;
        return;
    }

    avpkt=av_packet_alloc();
    this->frameNum=0;
}

void FEncode::encodeFrame(AVFrame *frame)
{
    int res=-1;
    frame->pts++;
    this->frameNum++;
    res=avcodec_send_frame(codec,frame);
    if(res<0)
    {
        qDebug()<<"send frame failed!"<<endl;
        return;
    }
    while(res>=0)
    {
        res=avcodec_receive_packet(codec,avpkt);
        //qDebug()<<"encode!"<<endl;
        if(res==AVERROR(EAGAIN)||res==AVERROR_EOF)
        {
            return;
        }
        else if(res<0)
        {
            qDebug()<<"receive acpkt failed!"<<endl;
            return;
        }
        avpkt->stream_index=0;
        av_interleaved_write_frame(fmatc,avpkt);
        av_packet_unref(avpkt);
    }
}

void FEncode::write_tailer()
{
    av_write_trailer(fmatc);
    avio_close(fmatc->pb);
}
