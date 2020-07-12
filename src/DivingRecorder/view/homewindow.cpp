#include "homewindow.h"

bool HomeWindow::isLogin=false;

HomeWindow::HomeWindow(Widget *parent) : Widget(parent)
{
    this->initWidgets();
    this->initLayout();
    this->initConnect();
    isSideBarHidden=false;
}

HomeWindow::~HomeWindow()
{

}

void HomeWindow::initWidgets()
{
    sideBar=new QListWidget(this);
    stackWin =new QStackedWidget(this);
    videoplayerwin=new VideoPlayerWindow;
    videoBackChooseWin=new VideoBackChooseWindow;
    picChooseWin=new PicChooseWindow;
    settingWin=new SmallSettingWindow;
    videoTranscodeWin=new VideoTranscodeWindow;
    loginWin=new LoginWindow;
}

void HomeWindow::initLayout()
{
    sideBar->setGeometry(QRect(0, 25, 180, 840));
    for (int i = 0; i < 6; i++)
    {
        QListWidgetItem * pItem = new QListWidgetItem;
        this->sideBar->addItem(pItem);
        switch(i)
        {
        case 0:
            pItem->setIcon(QIcon(":/img/shrink.png"));
            pItem->setText("行车记录仪");
            break;
        case 1:
            pItem->setIcon(QIcon(":/img/homewin/video.png"));
            pItem->setText("视频回放");
            break;
        case 2:
            pItem->setIcon(QIcon(":/img/homewin/picture.png"));
            pItem->setText("查看照片");
            break;
        case 3:
            pItem->setIcon(QIcon(":/img/homewin/video.png"));
            pItem->setText("视频转码");
            break;
        case 4:
            pItem->setIcon(QIcon(":/img/homewin/settings.png"));
            pItem->setText("设   置");
            break;
        case 5:
            pItem->setIcon(QIcon(":/img/homewin/getout.png"));
            pItem->setText("退   出");
            break;
        }
    }
    sideBar->setIconSize(QSize(30,30));

    stackWin->setGeometry(180,25,840,720);
    stackWin->setFixedSize(840,720);

    stackWin->addWidget(videoplayerwin);
    stackWin->addWidget(videoBackChooseWin);
    stackWin->addWidget(picChooseWin);
    stackWin->addWidget(videoTranscodeWin);
    stackWin->addWidget(settingWin);
}

void HomeWindow::initConnect()
{
    connect(sideBar,SIGNAL(currentRowChanged(int)),stackWin,SLOT(setCurrentIndex(int)));
    connect(sideBar,SIGNAL(itemClicked(QListWidgetItem *)),this,SLOT(changeSideBar(QListWidgetItem *)));
    connect(this,SIGNAL(resetVideoTable()),videoBackChooseWin,SLOT(searchVideoRecord()));
    connect(this,SIGNAL(resetPicTable()),picChooseWin,SLOT(searchPicRecord()));
    connect(this,SIGNAL(resetTranscodeTable()),videoTranscodeWin,SLOT(searchVideoRecord()));
    connect(videoplayerwin->btnSnap,SIGNAL(clicked()),this,SLOT(checkLogin()));
    connect(this,SIGNAL(addPicSignal()),videoplayerwin,SLOT(addPic()));
    connect(loginWin,SIGNAL(sendIsLogin(bool)),this,SLOT(setIsLogin(bool)));
    connect(this,SIGNAL(startFdecodeSignal()),videoplayerwin,SLOT(repeatCamera()));
}

void HomeWindow::changeSideBar(QListWidgetItem *item)
{
    if(sideBar->item(0)==item)
    {
        if(false==this->isSideBarHidden)
        {
            sideBar->item(1)->setHidden(true);
            sideBar->item(2)->setHidden(true);
            sideBar->item(3)->setHidden(true);
            sideBar->item(4)->setHidden(true);
            sideBar->item(5)->setHidden(true);
            this->isSideBarHidden=true;
            sideBar->item(0)->setIcon(QIcon(":/img/shrink.png"));
        }
        else
        {
            sideBar->item(1)->setHidden(false);
            sideBar->item(2)->setHidden(false);
            sideBar->item(3)->setHidden(false);
            sideBar->item(4)->setHidden(false);
            sideBar->item(5)->setHidden(false);
            this->isSideBarHidden=false;
            sideBar->item(0)->setIcon(QIcon(":/img/strench.png"));
        }
        this->update();
    }
    else if(sideBar->item(1)==item)
    {
        if(this->isLogin==false)
        {
            this->currentIndex=stackWin->currentIndex();
            stackWin->setCurrentIndex(0);
            loginWin->exec();
            if(this->isLogin==true)
            {
                stackWin->setCurrentIndex(this->currentIndex);
            }
        }
        emit resetVideoTable();
    }
    else if(sideBar->item(2)==item)
    {
        if(this->isLogin==false)
        {
            this->currentIndex=stackWin->currentIndex();
            stackWin->setCurrentIndex(0);
            loginWin->exec();
            if(this->isLogin==true)
            {
                stackWin->setCurrentIndex(this->currentIndex);
            }
        }
        emit resetPicTable();
    }
    else if(sideBar->item(3)==item)
    {
        if(this->isLogin==false)
        {
            this->currentIndex=stackWin->currentIndex();
            stackWin->setCurrentIndex(0);
            loginWin->exec();
            if(this->isLogin==true)
            {
                stackWin->setCurrentIndex(this->currentIndex);
            }
        }
        emit resetTranscodeTable();
    }
    else if(sideBar->item(5)==item)
    {
        int res=QMessageBox::question(NULL, "DVR", "是否确定退出?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(res==QMessageBox::Yes)
            this->close();
    }
}

void HomeWindow::checkLogin()
{
    if(this->isLogin==false)
    {
        loginWin->exec();
        if(this->isLogin==true)
        {
            emit addPicSignal();
        }
    }
    else
    {
        emit addPicSignal();
    }
}

void HomeWindow::setIsLogin(bool isLogin)
{
    this->isLogin=isLogin;
}

void HomeWindow::startFdecode()
{
    emit startFdecodeSignal();
}
