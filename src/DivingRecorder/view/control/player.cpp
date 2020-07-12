#include "player.h"

Player::~Player()
{
    delete fdecode;
    delete settingController;
    delete videoController;
    delete userController;
    delete picController;
}

Player::Player(QWidget *parent)
    : QLabel(parent)
{
    fdecode=new FDecode();
    settingController=new SettingController();
    videoController=new VideoController();
    userController=new UserController();
    picController=new PictureController();
    this->initWidgets();
    this->initLayout();
    this->initConnect();
}

void Player::initWidgets()
{
    proBar=new QProgressBar(this);
    lblbackground=new QLabel("",this);
    lblName=new QLabel("",this);
    btnPlay=new QPushButton("",this);
    btnLastOne=new QPushButton("",this);
    btnNextOne=new QPushButton("",this);
    chkSpeed=new QComboBox(this);
    btnSnap=new QPushButton("",this);
    lblMsg=new QLabel("",this);
}
void Player::initLayout()
{
    this->isFinish=false;
    this->setScaledContents(true);
    this->resize(800,500);
    qs=QSize(800,450);

    proBar->setGeometry(0,450,800,6);
    proBar->setRange(0,100); //设置进度条最小值和最大值(取值范围)
    proBar->setOrientation(Qt::Horizontal);  //水平方向
    proBar->setAlignment(Qt::AlignVCenter);  // 对齐方式
    proBar->setTextVisible(false); //隐藏进度条文本
    proBar->setInvertedAppearance(false); //true:反方向  false:正方向
    proBar->setVisible(true);  //false:隐藏进度条  true:显示进度条
    proBar->setStyleSheet("QProgressBar{color: solid gray;border: 0;border-radius:5px;background: transparent;padding: 0px;text-align :center;}"
                           "QProgressBar::chunk{background: qlineargradient(spread:pad,x1:1,y1:0,x2:0,y2:0,stop:0 #2a5298,stop:1 #1e3c72);}");

    lblbackground->setGeometry(0,456,800,59);
    lblbackground->setObjectName("darkblack");
    lblName->setGeometry(10,470,200,30);
    lblName->setAlignment(Qt::AlignCenter);
    lblName->setStyleSheet("QLabel{background:rgb(18,18,18);color:white;font-size:14px;}");

    btnLastOne->setGeometry(325,470,30,30);
    btnLastOne->setObjectName("btnLastOne");
    btnPlay->setGeometry(385,470,30,30);
    btnPlay->setCheckable(true);
    btnPlay->setObjectName("btnPlay");
    btnNextOne->setGeometry(445,470,30,30);
    btnNextOne->setObjectName("btnNextOne");
    chkSpeed->setGeometry(600,470,80,30);
    QPixmap pixmap(1, 50);
    pixmap.fill(Qt::transparent);
    QIcon icon(pixmap);
    chkSpeed->setIconSize(QSize(1, 50));
    chkSpeed->addItem(icon,"0.5X");
    chkSpeed->addItem(icon,"1.0X");
    chkSpeed->addItem(icon,"1.5X");
    chkSpeed->addItem(icon,"2.0X");
    chkSpeed->setCurrentIndex(1);
    btnSnap->setGeometry(720,470,30,30);
    btnSnap->setObjectName("btnSnap");

    lblMsg->setGeometry(0,515,800,35);
    lblMsg->setAlignment(Qt::AlignCenter);
    lblMsg->setObjectName("lblMsg");
    lblMsg->setStyleSheet("QLabel{background:rgb(42,42,42);color:#e9d7df;font:bond;font-size:16px;font-family:'Tahoma';}");
}

void Player::initConnect()
{
    connect(btnPlay,SIGNAL(toggled(bool)),this,SLOT(changeIsPlay(bool)));
    connect(btnLastOne,SIGNAL(clicked()),this,SLOT(playLastOne()));
    connect(btnNextOne,SIGNAL(clicked()),this,SLOT(playNextOne()));
    connect(btnSnap,SIGNAL(clicked()),this,SLOT(addPic()));
    connect(fdecode,SIGNAL(sendImageAndNum(QImage,int)),this,SLOT(receiveImageAndNum(QImage,int)));
    connect(fdecode,SIGNAL(sendImage(QImage)),this,SLOT(receiveImage(QImage)));
    connect(fdecode,SIGNAL(setVideoFinish()),this,SLOT(setVideoFinish()));
    connect(this,SIGNAL(breakFDecode()),fdecode,SLOT(breakThread()));
    connect(chkSpeed,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(setFDecodeSpeed(const QString &)));
}

void Player::receiveImageAndNum(QImage img, int nowframe)
{
    this->img=img.scaled(qs);
    proBar->setValue(nowframe*100/this->videoSize);  //设置当前的运行值
    this->update();
}

void Player::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!img.isNull()&&(btnPlay->isChecked()==false))
    {
        painter.drawImage(QRect(0,0,this->img.width(),this->img.height()),this->img);
    }
}

void Player::receiveImage(QImage img)
{
    this->img=img.scaled(qs);
    this->update();
}

void Player::changeIsPlay(bool checked)
{
    if(checked)
    {
        fdecode->stop();
    }
    else
    {
        if(isFinish==true)
        {
            isFinish=false;
            fdecode->start();
        }
        else
        {
            fdecode->resume();
        }
    }
}

void Player::setVideoFinish()
{
    this->isFinish=true;
    btnPlay->setChecked(true);
    fdecode->resume();//解锁
}

void Player::beginPlay()
{
    lblMsg->setText("");
    proBar->setValue(0);
    lblName->setText(videoController->getVideoName());
    this->videoSize=videoController->getVideoSize().toInt()-11;
    fdecode->fileName=videoController->getVideoPath();
    fdecode->choose=TO_RGB;
    btnPlay->setChecked(false);
    fdecode->start();
}

void Player::playLastOne()
{
    int res=videoController->searchLastVideo();
    if(res==0)
    {
        lblMsg->setText("");
        lblName->setText(videoController->getVideoName());
        proBar->setValue(0);
        this->videoSize=videoController->getVideoSize().toInt()-11;
        fdecode->fileName=videoController->getVideoPath();
        if(isFinish==false)
            emit breakFDecode();
        btnPlay->setChecked(false);
    }
    else
    {
        lblMsg->setText("没有上一个视频");
    }
}

void Player::playNextOne()
{
    int res=videoController->searchNextVideo();
    if(res==0)
    {
        lblMsg->setText("");
        lblName->setText(videoController->getVideoName());
        proBar->setValue(0);
        this->videoSize=videoController->getVideoSize().toInt()-11;
        fdecode->fileName=videoController->getVideoPath();
        if(isFinish==false)
            emit breakFDecode();
        btnPlay->setChecked(false);
    }
    else
    {
        lblMsg->setText("没有下一个视频");
    }
}

void Player::closeWindow()
{
    emit breakFDecode();
}

void Player::addPic()
{
    QString datetime = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
    QString date = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    QString picName=datetime+".png";
    QString picPath=settingController->getPicPath()+"/"+picName;
    this->img.save(picPath);
    picController->addPic(picName,date,picPath,userController->getLoginUid().toInt());
    qDebug()<<"add a picture!"<<endl;
}

void Player::setFDecodeSpeed(const QString &text)
{
    if(chkSpeed->currentText()=="0.5X")
        this->fdecode->playSpeed*=2.0;
    if(chkSpeed->currentText()=="1.0X")
        this->fdecode->playSpeed*=1.0;
    else if(chkSpeed->currentText()=="1.5X")
        this->fdecode->playSpeed/=1.5;
    else if(chkSpeed->currentText()=="2.0X")
        this->fdecode->playSpeed/=2.0;
}
