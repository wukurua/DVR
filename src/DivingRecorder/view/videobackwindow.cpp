#include "videobackwindow.h"

VideoBackWindow::VideoBackWindow(Widget *parent) : Widget(parent)
{
    videoController=new VideoController();
    settingController=new SettingController();
    fdecode=new FDecode();
    this->initWidgets();
    this->initLayout();
    this->initConnect();
}

VideoBackWindow::~VideoBackWindow()
{
    delete videoController;
    delete fdecode;
}

void VideoBackWindow::initWidgets()
{
    btnOutput=new QPushButton("导出",this);
    player=new Player(this);
}

void VideoBackWindow::initLayout()
{
    player->setGeometry(112,120,800,550);
    openvideo=new QFileDialog(this);
    btnOutput->setGeometry(820,60,100,40);
    btnOutput->setObjectName("yellow");
}

void VideoBackWindow::initConnect()
{
    connect(this,SIGNAL(beginPlaySignal()),player,SLOT(beginPlay()));
    connect(btnClose,SIGNAL(clicked()),player,SLOT(closeWindow()));
    connect(btnOutput,SIGNAL(clicked()),this,SLOT(transcode()));
}

void VideoBackWindow::setVideoBackWinName()
{
    emit beginPlaySignal();
}

void VideoBackWindow::transcode()
{
    QString filepath=QFileDialog::getExistingDirectory (this,"选择要保存的文件夹",settingController->getVideoPath());
    if(filepath=="")
        return;
    fdecode->dstDir=filepath;
    fdecode->fileName=videoController->getVideoPath();
    fdecode->choose=H264_TO_MP4;
    fdecode->start();
}


