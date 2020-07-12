#include "fdecode.h"

FDecode::FDecode()
{
    fev=new FEncode();
}

FDecode::~FDecode()
{
    delete fev;
}

void FDecode::registerFFMPEG()
{
    av_register_all();
    avdevice_register_all();
}

void FDecode::to_RGB()
{
    int numByte=avpicture_get_size(AV_PIX_FMT_RGB32,codecContext->width,codecContext->height);//YUVFrame size
    uint8_t *buffer=(uint8_t *)av_malloc(numByte*sizeof(uint8_t));
    avpicture_fill((AVPicture *)dstFrame,buffer,AV_PIX_FMT_RGB32,codecContext->width,codecContext->height);
    SwsContext *sws_context=sws_getContext(codecContext->width,codecContext->height,codecContext->pix_fmt,
                                        codecContext->width,codecContext->height,AV_PIX_FMT_RGB32,SWS_BICUBIC,NULL,NULL,NULL);
    isBreak=false;
    this->videoSize=0;
    this->playSpeed=100;
    while(av_read_frame(fmatC,acPkt)==0&&!isInterruptionRequested())
    {
        QMutexLocker lock(&m_lock);
        if(isBreak==true)
            break;
        if(acPkt->stream_index==videoIndex)
        {
            this->videoSize++;
            avcodec_decode_video2(codecContext,picture,&got_picture_ptr,acPkt);
            if(got_picture_ptr)
            {
                sws_scale(sws_context,picture->data,picture->linesize,0,picture->height,dstFrame->data,dstFrame->linesize);
                QImage img((uchar *)buffer,codecContext->width,codecContext->height,QImage::Format_RGB32);
                emit sendImageAndNum(img,this->videoSize);
                msleep(this->playSpeed);
            }
        }
        av_packet_unref(acPkt);
    }
    av_frame_unref(dstFrame);
    av_frame_unref(picture);
    avcodec_close(codecContext);
    avformat_close_input(&fmatC);
    av_free_packet(acPkt);
    emit setVideoFinish();
}

void FDecode::H264_to_Video()
{
    AVOutputFormat *avOfmat=av_guess_format(NULL,videoName.toStdString().c_str(),NULL);
    if(NULL==avOfmat)
    {
        qDebug()<<"guess failed!"<<endl;
        return;
    }

    AVFormatContext *outFmat=avformat_alloc_context();
    outFmat->oformat=avOfmat;

    int res=avio_open(&outFmat->pb,videoName.toStdString().c_str(),AVIO_FLAG_WRITE);
    if(res<0)
    {
        qDebug()<<"avio_open failed!"<<endl;
        return;
    }

    AVStream *inStream=fmatC->streams[videoIndex];
    AVStream *outStream=avformat_new_stream(outFmat,NULL);
    if(NULL==outStream)
    {
        qDebug()<<"new Stream failed!"<<endl;
        return;
    }

    outStream->codec=inStream->codec;
    outStream->codec->codec_tag=0;
    //outStream->codec->flags=inStream->codec->flags;
    outStream->codec->time_base.num=inStream->avg_frame_rate.den;
    outStream->codec->time_base.den=inStream->avg_frame_rate.num;

    res=avformat_write_header(outFmat,NULL);
    if(res<0)
    {
        qDebug()<<"write header failed!"<<endl;
        return;
    }

    AVPacket *pkt=av_packet_alloc();
    int frameConut=0;
    while(av_read_frame(fmatC,pkt)>=0)
    {
        if(pkt->stream_index==videoIndex)
        {
            emit sendNum(frameConut);
            frameConut++;
            if(AV_NOPTS_VALUE==pkt->pts)
            {
                AVRational timeBasel=inStream->time_base;
                int64_t calc_duration=(double)AV_TIME_BASE
                        /(double)av_q2d(inStream->r_frame_rate);
                pkt->pts=(double)(frameConut*calc_duration)/
                        (double)(av_q2d(timeBasel)*AV_TIME_BASE);
                pkt->dts=pkt->pts;
                pkt->duration=(double)calc_duration/
                        (double)(av_q2d(timeBasel)*AV_TIME_BASE);
            }
            pkt->pts=av_rescale_q_rnd(pkt->pts,
                                    inStream->time_base,
                                    outStream->time_base,
                                    (AVRounding)(AV_ROUND_INF|AV_ROUND_PASS_MINMAX));
            pkt->dts=av_rescale_q_rnd(pkt->dts,
                                    inStream->time_base,
                                    outStream->time_base,
                                    (AVRounding)(AV_ROUND_INF|AV_ROUND_PASS_MINMAX));
            pkt->duration=av_rescale_q(pkt->duration,
                                    inStream->time_base,
                                    outStream->time_base);
            pkt->pos=-1;
            pkt->flags|=AV_PKT_FLAG_KEY;
            pkt->stream_index=videoIndex;
            av_interleaved_write_frame(outFmat,pkt);
        }
        av_packet_unref(pkt);
    }
    av_write_trailer(outFmat);
    avcodec_close(outFmat->streams[videoIndex]->codec);
    avio_close(outFmat->pb);
    av_free(outFmat);
    avformat_close_input(&fmatC);
    av_free(fmatC);
    av_packet_free(&pkt);
    qDebug()<<"transcode suc!"<<endl;
    emit transcodeDone();
}

void FDecode::open_camera()
{
    fev->initEncode(codecContext->width,codecContext->height);//init
    this->date=fev->date;
    this->path=fev->path;
    this->datetime=fev->datetime;
    this->videoName=fev->videoName;

    dstFrame1=av_frame_alloc();

    dstFrame->width=codecContext->width;
    dstFrame->height=codecContext->height;
    dstFrame->format=codecContext->pix_fmt;
    dstFrame->pts=0;

    //yuv
    int numByte=avpicture_get_size(AV_PIX_FMT_YUV420P,codecContext->width,codecContext->height);//YUVFrame size
    uint8_t *buffer=(uint8_t *)av_malloc(numByte*sizeof(uint8_t));
    avpicture_fill((AVPicture *)dstFrame,buffer,AV_PIX_FMT_YUV420P,codecContext->width,codecContext->height);
    SwsContext *sws_context_yuv=sws_getContext(codecContext->width,codecContext->height,codecContext->pix_fmt,
                                        codecContext->width,codecContext->height,AV_PIX_FMT_YUV420P,SWS_BICUBIC,NULL,NULL,NULL);

    //rgb
    int numByte1=avpicture_get_size(AV_PIX_FMT_RGB32,codecContext->width,codecContext->height);//YUVFrame size
    uint8_t *buffer1=(uint8_t *)av_malloc(numByte1*sizeof(uint8_t));
    avpicture_fill((AVPicture *)dstFrame1,buffer1,AV_PIX_FMT_RGB32,codecContext->width,codecContext->height);
    SwsContext *sws_context_rgb=sws_getContext(codecContext->width,codecContext->height,codecContext->pix_fmt,
                                        codecContext->width,codecContext->height,AV_PIX_FMT_RGB32,SWS_BICUBIC,NULL,NULL,NULL);

    this->videoSize=0;
    fev->frameQueue.clear();
    while(av_read_frame(fmatC,acPkt)==0)
    {
        if(acPkt->stream_index==videoIndex)
        {
            if(this->duration==fev->frameNum)
                break;
            avcodec_decode_video2(codecContext,picture,&got_picture_ptr,acPkt);
            if(got_picture_ptr)
            {
                sws_scale(sws_context_yuv,picture->data,picture->linesize,0,picture->height,dstFrame->data,dstFrame->linesize);
                //encode
                fev->frameQueue.enqueue(dstFrame);//把要编码的AVFrame加入队列
                msleep(5);
                fev->start();//开启线程,开始编码

                //show
                sws_scale(sws_context_rgb,picture->data,picture->linesize,0,picture->height,dstFrame1->data,dstFrame1->linesize);
                QImage img((uchar *)buffer1,codecContext->width,codecContext->height,QImage::Format_RGB32);
                if(fev->frameNum==1)
                {
                    this->cover=img.scaled(1270, 720).scaled(318, 180, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                    this->coverPath=dstDir+"/"+this->datetime+".png";
                    this->cover.save(coverPath);
                }
                emit sendImage(img);
            }
        }
        av_packet_unref(acPkt);
    }

    while(!fev->frameQueue.empty())
    {
        fev->start();//编码队列不为空就继续处理
    }

    this->videoSize=fev->frameNum;
    this->fev->write_tailer();
    emit addVideo();
    av_free(buffer);
    av_frame_unref(dstFrame);
    av_frame_unref(picture);
    avcodec_close(codecContext);
    avformat_close_input(&fmatC);
    av_free_packet(acPkt);
    qDebug()<<"save as h264 suc!"<<endl;
    emit repeatCam();
}

void FDecode::breakThread()
{
    this->isBreak=true;
}

void FDecode::run()
{
    this->fev->dstDir=this->dstDir;
    this->registerFFMPEG();

    fmatC=avformat_alloc_context();
    int res=-1;
    if(CAMERA==choose)
    {
        AVDictionary *options=NULL;
        av_dict_set_int(&options,"rtbufsize",3041280*100,0);//the default buf size of windows is 3041280

        //window
        AVInputFormat *IfmatC=av_find_input_format("dshow");
        QString camera="video="+this->cameraName;
        res=avformat_open_input(&fmatC,camera.toStdString().c_str(),IfmatC,&options);

        //linux
        //AVInputFormat *IfmatC=av_find_input_format("video4linux2");
        //res=avformat_open_input(&fmatC,"/dev/video0",IfmatC,&options);
    }

    else
    {
        res=avformat_open_input(&fmatC,fileName.toStdString().c_str(),NULL,NULL);
    }
    if(res<0)
    {
        qDebug()<<"can't open input!";
        return;
    }

    res=avformat_find_stream_info(fmatC,NULL);
    if(res<0)
    {
        qDebug()<<"Not find stream info!";
        return;
    }

    videoIndex=-1;
    for(int i=0;i<fmatC->nb_streams;i++)//2 streams info:picture and video
    {
        if(fmatC->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO)
        {
            videoIndex=i;
            break;
        }
    }
    if(-1==videoIndex)
    {
        qDebug()<<"Not find video info!";
        return;
    }

    if(choose==TO_RGB||choose==CAMERA)
    {
        codecContext=fmatC->streams[videoIndex]->codec;
        codec=avcodec_find_decoder(codecContext->codec_id);
        if(NULL==codec)
        {
            qDebug()<<"Not find decode info!";
            return;
        }

        res=avcodec_open2(codecContext,codec,NULL);
        if(res!=0)
        {
            qDebug()<<"Open code failed!";
            return;
        }

        acPkt=av_packet_alloc();
        size=codecContext->width*codecContext->height;
        av_new_packet(acPkt,size);
        got_picture_ptr=-1;

        picture=av_frame_alloc();
        dstFrame=av_frame_alloc();
    }

    if(choose==TO_RGB)
    {
        this->to_RGB();
    }
    else if(choose==H264_TO_MP4)
    {
        QString current_date = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
        this->videoName=dstDir+"/"+current_date+".mp4";
        this->H264_to_Video();
    }
    else if(choose==H264_TO_AVI)
    {
        QString current_date = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
        this->videoName=dstDir+"/"+current_date+".avi";
        this->H264_to_Video();
    }
    else if(choose==H264_TO_MOV)
    {
        QString current_date = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
        this->videoName=dstDir+"/"+current_date+".mov";
        this->H264_to_Video();
    }
    else if(choose==CAMERA)
    {
        this->open_camera();
    }
}

void FDecode::stop()
{
    m_lock.lock();
}

void FDecode::resume()
{
    m_lock.unlock();
}
