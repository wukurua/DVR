#include "videoplayerwindow.h"

VideoPlayerWindow::VideoPlayerWindow(QWidget *parent)
    : QWidget(parent)
{
    fdecode=new FDecode();
    settingController=new SettingController();
    videoController=new VideoController();
    userController=new UserController();
    picController=new PictureController();
    this->initWidgets();
    this->initLayout();
    this->initConnect();

//    fdecode->cameraName=settingController->getCamera();
//    fdecode->dstDir=settingController->getVideoPath();
//    fdecode->duration=settingController->getDuration().toInt();
//    fdecode->choose=CAMERA;
//    fdecode->start();
}

VideoPlayerWindow::~VideoPlayerWindow()
{
    delete fdecode;
    delete settingController;
    delete videoController;
    delete userController;
    delete picController;
}

void VideoPlayerWindow::initWidgets()
{
    lblTime=new QLabel("",this);
    player=new PicLabel(this);
    btnSnap=new QPushButton("拍照",this);
}

void VideoPlayerWindow::initLayout()
{
    lblTime->setGeometry(20,20,300,40);
    lblTime->setStyleSheet("QLabel{background:rgb(42,42,42);color:white;}");
    QString dt = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    lblTime->setText(dt);
    player->setGeometry(20,80,800,450);

    btnSnap->setGeometry(600,600,200,40);
    btnSnap->setObjectName("yellow");
}

void VideoPlayerWindow::initConnect()
{
    //connect(btnSnap,SIGNAL(clicked()),this,SLOT(addPic()));
    connect(fdecode,SIGNAL(sendImage(QImage)),this->player,SLOT(receiveImage(QImage)));
    connect(fdecode,SIGNAL(addVideo()),this,SLOT(addVideo()));
    connect(fdecode,SIGNAL(repeatCam()),this,SLOT(repeatCamera()));
}

void VideoPlayerWindow::paintEvent(QPaintEvent *event)
{
    lblTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    this->update();
}

void VideoPlayerWindow::repeatCamera()
{
    fdecode->cameraName=settingController->getCamera();
    fdecode->dstDir=settingController->getVideoPath();
    fdecode->duration=settingController->getDuration().toInt();
    fdecode->choose=CAMERA;
    fdecode->start();
}

void VideoPlayerWindow::addVideo()
{
    videoController->addVideo(fdecode->videoName,fdecode->date,fdecode->path,fdecode->videoSize,fdecode->coverPath,userController->getLoginUid().toInt());
    qDebug()<<"add a video!"<<endl;
}

void VideoPlayerWindow::addPic()
{
    QString datetime = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
    QString date = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    QString picName=datetime+".png";
    QString picPath=settingController->getPicPath()+"/"+picName;
    if(!player->img.isNull())
    {
        player->img.save(picPath);
        picController->addPic(picName,date,picPath,userController->getLoginUid().toInt());
        qDebug()<<"add a picture!"<<endl;
    }
    else
        qDebug()<<"img is empty!"<<endl;
}
