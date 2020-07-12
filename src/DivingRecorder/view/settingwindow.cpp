#include "settingwindow.h"

SettingWindow::SettingWindow(Widget *parent) : Widget(parent)
{
    settingController=new SettingController;
    this->initWidgets();
    this->initLayout();
    this->initConnect();
}

SettingWindow::~SettingWindow()
{
    delete settingController;
}

void SettingWindow::initWidgets()
{
    lblWrap=new QLabel("",this);
    lblTitle=new QLabel("Setting",this);
    lblCameraImg=new QLabel("",this); 
    lblPicturePathImg=new QLabel("",this);
    lblVideoPathImg=new QLabel("",this);
    lblDurationImg=new QLabel("",this);

    btnCheckMore=new QPushButton("",this);
    btnCheckMore1=new QPushButton("",this);
    lblCameraChooseMag=new QLabel("慎重修改",this);

    etVideoPath=new QLineEdit("",this);
    etPicturePath=new QLineEdit("",this);
    etDuration=new QLineEdit("",this);
    chkCamera=new QComboBox(this);

    lblCameraMsg=new QLabel("",this);
    lblVideoPathMsg=new QLabel("",this);
    lblPicturePathMsg=new QLabel("",this);
    lblDurationMsg=new QLabel("",this);

    btnOK=new QPushButton("Commit",this);
}

void SettingWindow::initLayout()
{
    this->setWindowTitle("Setting Menu");

    lblWrap->setGeometry(112,80,800,610);
    lblWrap->setObjectName("lblWrap");

    lblTitle->setGeometry(437,120,150,60);
    lblTitle->setAlignment(Qt::AlignHCenter);
    lblTitle->setObjectName("lblTitle");

    lblCameraImg->setGeometry(265,202,40,40);
    QPixmap namepix(":/img/camera.png");
    lblCameraImg->setPixmap(namepix.scaled(QSize(32,32),Qt::KeepAspectRatio));
    chkCamera->setGeometry(322,200,430,40);
    chkCamera->installEventFilter(this);
    chkCamera->setEditable(true);
    QPixmap pixmap(1, 50);
    pixmap.fill(Qt::transparent);
    QIcon icon(pixmap);
    chkCamera->setIconSize(QSize(1, 50));
    foreach (const QCameraInfo &cameraInfo, QCameraInfo::availableCameras())
    {
        chkCamera->addItem(icon,cameraInfo.description());
    }
    QString str = chkCamera->currentText();
    chkCamera->lineEdit()->setText(str);

    lblCameraChooseMag->setGeometry(760,200,140,40);
    lblCameraChooseMag->setStyleSheet("font-size:14px;background:white;color:rgb(222,163,9);");
    lblCameraMsg->setGeometry(322,242,430,40);
    lblCameraMsg->setObjectName("lblMsg");

    lblVideoPathImg->setGeometry(265,282,40,40);
    QPixmap pwdpix(":/img/download.png");
    lblVideoPathImg->setPixmap(pwdpix.scaled(QSize(32,32),Qt::KeepAspectRatio));
    etVideoPath->setGeometry(322,280,430,40);
    etVideoPath->setPlaceholderText("视频存储路径");
    etVideoPath->setClearButtonEnabled(true);
    etVideoPath->setTextMargins(10,5,5,5);
    etVideoPath->installEventFilter(this);
    btnCheckMore->setGeometry(760,282,40,40);
    btnCheckMore->setObjectName("btnCheckMore");
    lblVideoPathMsg->setGeometry(322,320,430,40);
    lblVideoPathMsg->setObjectName("lblMsg");

    lblPicturePathImg->setGeometry(265,362,40,40);
    QPixmap picpic(":/img/image.png");
    lblPicturePathImg->setPixmap(picpic.scaled(QSize(32,32),Qt::KeepAspectRatio));
    etPicturePath->setGeometry(322,360,430,40);
    etPicturePath->setPlaceholderText("图片存储路径");
    etPicturePath->setClearButtonEnabled(true);
    etPicturePath->setTextMargins(10,5,5,5);
    etPicturePath->installEventFilter(this);
    btnCheckMore1->setGeometry(760,362,40,40);
    btnCheckMore1->setObjectName("btnCheckMore");
    lblPicturePathMsg->setGeometry(322,400,430,40);
    lblPicturePathMsg->setObjectName("lblMsg");

    lblDurationImg->setGeometry(265,442,40,40);
    QPixmap durationpix(":/img/frequency.png");
    lblDurationImg->setPixmap(durationpix.scaled(QSize(32,32),Qt::KeepAspectRatio));
    etDuration->setGeometry(322,440,430,40);
    etDuration->setPlaceholderText("每个视频的帧数时长");
    etDuration->setClearButtonEnabled(true);
    etDuration->setTextMargins(10,5,5,5);
    etDuration->installEventFilter(this);
    lblDurationMsg->setGeometry(322,480,430,40);
    lblDurationMsg->setObjectName("lblMsg");

    bool res=settingController->isSettingEmpty();
    if(res==false)
    {
        etVideoPath->setText(settingController->getVideoPath());
        etPicturePath->setText(settingController->getPicPath());
        etDuration->setText(settingController->getDuration());
        chkCamera->setCurrentText(settingController->getCamera());
    }

    btnOK->setGeometry(270,530,510,40);
    btnOK->installEventFilter(this);
}

void SettingWindow::initConnect()
{
    connect(btnOK,SIGNAL(clicked()),this,SLOT(commit()));
    connect(this,SIGNAL(showWelcomeWinSignal()),this,SLOT(jumpToWelcomeWin()));
    connect(btnCheckMore,SIGNAL(clicked()),this,SLOT(chooseVideoPath()));
    connect(btnCheckMore1,SIGNAL(clicked()),this,SLOT(choosePicturePath()));
}

bool SettingWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==chkCamera||obj==etVideoPath||obj==etPicturePath||obj==etDuration||obj==btnOK)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if(keyEvent->key()==Qt::Key_Enter||keyEvent->key()==Qt::Key_Return)
            {
                commit();
                return true;
            }
        }
    }
    return false;
}

void SettingWindow::commit()
{
    string name = this->chkCamera->currentText().toStdString();
    string videopath = this->etVideoPath->text().toStdString();
    string picpath = this->etVideoPath->text().toStdString();
    string duration = this->etDuration->text().toStdString();
    int flag=1;
    if(name=="")
    {
        flag=0;
        this->lblCameraMsg->setText("摄像头名称不能为空");
    }
    else
    {
        this->lblCameraMsg->setText("");
    }
    if(picpath=="")
    {
        flag=0;
        this->lblPicturePathMsg->setText("视频存储位置不能为空");
    }
    else
    {
        this->lblPicturePathMsg->setText("");
    }
    if(videopath=="")
    {
        flag=0;
        this->lblVideoPathMsg->setText("图片存储位置不能为空");
    }
    else
    {
        this->lblVideoPathMsg->setText("");
    }
    if(duration=="")
    {
        flag=0;
        this->lblVideoPathMsg->setText("采集时间间隔不能为空");
    }
    else
    {
        this->lblVideoPathMsg->setText("");
    }
    if(flag!=0)
    {
        int row,col;
        SingleDBOption::getTable("INSERT OR REPLACE INTO t_setting (sid,videoPath,picPath,duration,camera) "
                                 "VALUES(1,'"+etVideoPath->text()+"','"+etPicturePath->text()+"',"+etDuration->text()+",'"+chkCamera->currentText()+"');",
                                 SingleDBOption::pResult,row,col);
        this->lblDurationMsg->setText("更改成功");
    }
    emit showWelcomeWinSignal();
}


void SettingWindow::chooseVideoPath()
{
    fileName = QFileDialog::getExistingDirectory (this,"选择视频的保存路径",".");
    etVideoPath->setText(fileName);
}

void SettingWindow::choosePicturePath()
{
    fileName = QFileDialog::getExistingDirectory (this,"选择图片的保存路径",".");
    etPicturePath->setText(fileName);
}

void SettingWindow::jumpToWelcomeWin()
{
    this->hide();
    welcomeWin=new WelcomeWindow();
    welcomeWin->setObjectName("white");
    welcomeWin->show();
}
