#include "smallsettingwindow.h"

SmallSettingWindow::SmallSettingWindow(QWidget *parent) : QWidget(parent)
{
    settingController=new SettingController;
    this->initWidgets();
    this->initLayout();
    this->initConnect();
}

SmallSettingWindow::~SmallSettingWindow()
{
    delete settingController;
}

void SmallSettingWindow::initWidgets()
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

    settingController=new SettingController;
}

void SmallSettingWindow::initLayout()
{
    lblWrap->setGeometry(40,50,760,610);
    lblWrap->setObjectName("lblWrap");

    lblTitle->setGeometry(345,90,150,60);
    lblTitle->setAlignment(Qt::AlignHCenter);
    lblTitle->setObjectName("lblTitle");

    lblCameraImg->setGeometry(160,172,40,40);
    QPixmap namepix(":/img/camera.png");
    lblCameraImg->setPixmap(namepix.scaled(QSize(32,32),Qt::KeepAspectRatio));
    chkCamera->setGeometry(220,170,430,40);
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

    lblCameraChooseMag->setGeometry(660,170,80,40);
    lblCameraChooseMag->setStyleSheet("font-size:14px;background:white;color:rgb(222,163,9);");
    lblCameraMsg->setGeometry(220,210,430,40);
    lblCameraMsg->setObjectName("lblMsg");

    lblVideoPathImg->setGeometry(160,252,40,40);
    QPixmap pwdpix(":/img/download.png");
    lblVideoPathImg->setPixmap(pwdpix.scaled(QSize(32,32),Qt::KeepAspectRatio));
    etVideoPath->setGeometry(220,250,430,40);
    etVideoPath->setPlaceholderText("视频存储路径");
    etVideoPath->setClearButtonEnabled(true);
    etVideoPath->setTextMargins(10,5,5,5);
    etVideoPath->installEventFilter(this);
    btnCheckMore->setGeometry(660,252,40,40);
    btnCheckMore->setObjectName("btnCheckMore");
    lblVideoPathMsg->setGeometry(220,290,430,40);
    lblVideoPathMsg->setObjectName("lblMsg");


    lblPicturePathImg->setGeometry(160,332,40,40);
    QPixmap picpic(":/img/image.png");
    lblPicturePathImg->setPixmap(picpic.scaled(QSize(32,32),Qt::KeepAspectRatio));
    etPicturePath->setGeometry(220,330,430,40);
    etPicturePath->setPlaceholderText("图片存储路径");
    etPicturePath->setClearButtonEnabled(true);
    etPicturePath->setTextMargins(10,5,5,5);
    etPicturePath->installEventFilter(this);
    btnCheckMore1->setGeometry(660,332,40,40);
    btnCheckMore1->setObjectName("btnCheckMore");
    lblPicturePathMsg->setGeometry(220,370,430,40);
    lblPicturePathMsg->setObjectName("lblMsg");

    lblDurationImg->setGeometry(160,412,40,40);
    QPixmap durationpix(":/img/frequency.png");
    lblDurationImg->setPixmap(durationpix.scaled(QSize(32,32),Qt::KeepAspectRatio));
    etDuration->setGeometry(220,410,430,40);
    etDuration->setPlaceholderText("每个视频的帧数时长");
    etDuration->setClearButtonEnabled(true);
    etDuration->setTextMargins(10,5,5,5);
    etDuration->installEventFilter(this);
    lblDurationMsg->setGeometry(220,450,430,40);
    lblDurationMsg->setObjectName("lblMsg");


    etVideoPath->setText(settingController->getVideoPath());
    etPicturePath->setText(settingController->getPicPath());
    etDuration->setText(settingController->getDuration());
    chkCamera->setCurrentText(settingController->getCamera());

    btnOK->setGeometry(160,520,530,40);
    btnOK->installEventFilter(this);
}

void SmallSettingWindow::initConnect()
{
    connect(btnOK,SIGNAL(clicked()),this,SLOT(commit()));
    connect(btnCheckMore,SIGNAL(clicked()),this,SLOT(chooseVideoPath()));
    connect(btnCheckMore1,SIGNAL(clicked()),this,SLOT(choosePicturePath()));
}

bool SmallSettingWindow::eventFilter(QObject *obj, QEvent *event)
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

void SmallSettingWindow::commit()
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
        this->lblDurationMsg->setText("采集时间间隔不能为空");
    }
    else
    {
        this->lblDurationMsg->setText("");
    }
    if(flag!=0)
    {
        int row,col;
        SingleDBOption::getTable("INSERT OR REPLACE INTO t_setting (sid,videoPath,picPath,duration,camera) "
                                 "VALUES(1,'"+etVideoPath->text()+"','"+etPicturePath->text()+"',"+etDuration->text()+",'"+chkCamera->currentText()+"');",
                                 SingleDBOption::pResult,row,col);
        this->lblDurationMsg->setText("更改成功");
    }
}

void SmallSettingWindow::chooseVideoPath()
{
    fileName = QFileDialog::getExistingDirectory (this,"Choose Directory",".");
    etVideoPath->setText(fileName);
}

void SmallSettingWindow::choosePicturePath()
{
    fileName = QFileDialog::getExistingDirectory (this,"Choose Directory",".");
    etPicturePath->setText(fileName);
}
