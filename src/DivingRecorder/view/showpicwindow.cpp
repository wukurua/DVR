#include "showpicwindow.h"

ShowPicWindow::ShowPicWindow(Widget *parent) : Widget(parent)
{
    picController=new PictureController();
    this->initWidgets();
    this->initLayout();
    this->initConnect();
}

ShowPicWindow::~ShowPicWindow()
{
    delete picController;
}

void ShowPicWindow::initWidgets()
{
    player=new QLabel("",this);
    lblbackground=new QLabel("",this);
    lblName=new QLabel("",this);
    btnLastOne=new QPushButton("",this);
    btnNextOne=new QPushButton("",this);
    lblMsg=new QLabel("",this);
}

void ShowPicWindow::initLayout()
{
    player->setGeometry(112,100,800,450);
    player->setScaledContents(true);
    player->resize(800,500);

    lblbackground->setGeometry(108,550,808,70);
    lblbackground->setObjectName("darkblack");
    lblName->setGeometry(120,570,200,30);
    lblName->setAlignment(Qt::AlignCenter);
    lblName->setStyleSheet("QLabel{background:rgb(18,18,18);color:white;font-size:14px;}");

    btnLastOne->setGeometry(441,570,30,30);
    btnLastOne->setObjectName("btnLastOne");
    btnNextOne->setGeometry(561,570,30,30);
    btnNextOne->setObjectName("btnNextOne");

    lblMsg->setGeometry(108,620,808,40);
    lblMsg->setAlignment(Qt::AlignCenter);
    lblMsg->setObjectName("lblMsg");
    lblMsg->setStyleSheet("QLabel{background:rgb(42,42,42);color:#e9d7df;font:bond;font-size:16px;font-family:'Tahoma';}");
}

void ShowPicWindow::initConnect()
{
    connect(btnLastOne,SIGNAL(clicked()),this,SLOT(playLastOne()));
    connect(btnNextOne,SIGNAL(clicked()),this,SLOT(playNextOne()));
    connect(this,SIGNAL(resetImage()),this,SLOT(setShowPicWinImage()));
}

void ShowPicWindow::playLastOne()
{
    int res=picController->searchLastPic();
    if(res==0)
    {
        lblMsg->setText("");
        lblName->setText(picController->getPicName());
        emit resetImage();
    }
    else
    {
        lblMsg->setText("没有上一个照片");
    }
}

void ShowPicWindow::playNextOne()
{
    int res=picController->searchNextPic();
    if(res==0)
    {
        lblMsg->setText("");
        lblName->setText(picController->getPicName());
        emit resetImage();
    }
    else
    {
        lblMsg->setText("没有下一个照片");
    }
}

void ShowPicWindow::setShowPicWinImage()
{
    QImage img(picController->getPicPath());
    QPainter pp(&img);
    QPixmap pix=QPixmap::fromImage(img);
    player->setPixmap(pix);
    lblName->setText(picController->getPicName());
}


