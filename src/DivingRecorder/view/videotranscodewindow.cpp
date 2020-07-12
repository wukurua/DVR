#include "videotranscodewindow.h"

VideoTranscodeWindow::VideoTranscodeWindow(QWidget *parent)
    : QWidget(parent)
{
    videoController=new VideoController();
    settingController=new SettingController();
    fdecode=new FDecode();
    isChoosed=false;
    this->initWidgets();
    this->initLayout();
    this->initConnect();
}

VideoTranscodeWindow::~VideoTranscodeWindow()
{
    delete videoController;
    delete settingController;
    delete fdecode;
}

void VideoTranscodeWindow::initWidgets()
{
    lblTitle=new QLabel("视频转码",this);
    lblBegin=new QLabel("起始日期:",this);
    etDateBegin=new QDateEdit(this);
    lblEnd=new QLabel("结束日期:",this);
    etDateEnd=new QDateEdit(this);
    btnSearch=new QPushButton("查询",this);
    lblMsg=new QLabel("",this);
    lblWrap=new QLabel("",this);
    lblWrap1=new QLabel("",this);
    lblVideo=new QLabel("选择要转码的视频:",this);
    scroll = new QScrollArea(this);
    table=new ShowVideoTable(1,scroll,HORIZONTAL,4);
    lblForm=new QLabel("选择转码格式:",this);
    chkForm=new QComboBox(this);
    lblPath=new QLabel("选择保存路径:",this);
    etFilePath=new QLineEdit("",this);
    btnOpen=new QPushButton("",this);
    lblPathMsg=new QLabel("",this);
    lblChooseFileMsg=new QLabel("",this);
    openvideo=new QFileDialog(this);
    btnStart=new QPushButton("点击转码",this);
    proBar=new QProgressBar(this);
    lblDone=new QLabel("",this);
}

void VideoTranscodeWindow::initLayout()
{
    lblTitle->setGeometry(360,30,100,30);
    lblTitle->setObjectName("black");
    lblTitle->setStyleSheet("font-size:20px;");

    lblBegin->setGeometry(50,80,80,30);
    lblBegin->setObjectName("black");

    QIcon left(":/img/arrow_left.png");
    QIcon right(":/img/arrow_right.png");
    etDateBegin->setGeometry(150,80,150,30);
    etDateBegin->setCalendarPopup(true);
    etDateBegin->setDateTime(QDateTime::currentDateTime());
    etDateBegin->setDisplayFormat("yyyy-MM-dd");
    QToolButton *prevBtn = etDateBegin->calendarWidget()->findChild<QToolButton*>(QLatin1String("qt_calendar_prevmonth"));
    QToolButton *bextBtn = etDateBegin->calendarWidget()->findChild<QToolButton*>(QLatin1String("qt_calendar_nextmonth"));
    prevBtn->setIcon(left);
    bextBtn->setIcon(right);
    etDateBegin->calendarWidget()->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);

    lblEnd->setGeometry(350,80,80,30);
    lblEnd->setObjectName("black");

    etDateEnd->setGeometry(450,80,150,30);
    etDateEnd->setCalendarPopup(true);
    etDateEnd->setDateTime(QDateTime::currentDateTime());
    etDateEnd->setDisplayFormat("yyyy-MM-dd");
    QToolButton *prevBtn1 = etDateEnd->calendarWidget()->findChild<QToolButton*>(QLatin1String("qt_calendar_prevmonth"));
    QToolButton *bextBtn1 = etDateEnd->calendarWidget()->findChild<QToolButton*>(QLatin1String("qt_calendar_nextmonth"));
    prevBtn1->setIcon(left);
    bextBtn1->setIcon(right);
    etDateEnd->calendarWidget()->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);

    btnSearch->setGeometry(670,75,100,40);
    btnSearch->setObjectName("yellow");

    lblMsg->setGeometry(610,130,250,35);
    lblMsg->setObjectName("lblMsg");
    lblMsg->setStyleSheet("QLabel{background:rgb(42,42,42);color:#e9d7df;font:bond;font-size:16px;font-family:'Tahoma';}");

    lblWrap->setGeometry(30,130,290,580);
    lblWrap->setObjectName("lblWrap");
    lblWrap->setStyleSheet("QLabel{background:rgb(18,18,18);}");
    lblVideo->setGeometry(60,140,180,30);
    lblVideo->setObjectName("black");
    lblVideo->setStyleSheet("QLabel{background:rgb(18,18,18);}");
    scroll->setGeometry(55,175,240,520);
    table->setGeometry(55,175,240,table->rowNum*130);
    //设置滚动区域的窗体
    scroll->setWidget(this->table);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setStyleSheet("background:transparent");
    scroll->setFrameShape(QFrame::NoFrame);

    lblWrap1->setGeometry(350,180,460,500);
    lblWrap1->setObjectName("lblWrap");
    lblWrap1->setStyleSheet("QLabel{background:rgb(18,18,18);}");
    lblForm->setGeometry(380,200,130,30);
    lblForm->setObjectName("black");
    lblForm->setStyleSheet("QLabel{background:rgb(18,18,18);}");
    chkForm->setGeometry(520,200,100,30);
    chkForm->setStyleSheet("QComBoBox{border:0;}");
    QPixmap pixmap(1, 50);
    pixmap.fill(Qt::transparent);
    QIcon icon(pixmap);
    chkForm->setIconSize(QSize(1, 50));
    chkForm->addItem(icon,"mp4");
    chkForm->addItem(icon,"avi");
    chkForm->addItem(icon,"mov");
    lblPath->setGeometry(380,270,130,30);
    lblPath->setObjectName("black");
    lblPath->setStyleSheet("QLabel{background:rgb(18,18,18);}");
    etFilePath->setGeometry(380,340,400,40);
    etFilePath->setObjectName("etFilePath");
    etFilePath->setStyleSheet("QLineEdit{border:0;}");
    etFilePath->setText(settingController->getVideoPath());
    btnOpen->setGeometry(740,340,40,40);
    btnOpen->setObjectName("btnCheckMore");
    lblPathMsg->setGeometry(380,400,400,30);
    lblPathMsg->setStyleSheet("QLabel{background:rgb(18,18,18);color:#e9d7df;font:bond;font-size:16px;font-family:'Tahoma';}");
    lblPathMsg->setAlignment(Qt::AlignCenter);
    lblChooseFileMsg->setGeometry(380,450,400,30);
    lblChooseFileMsg->setStyleSheet("QLabel{background:rgb(18,18,18);color:#e9d7df;font:bond;font-size:16px;font-family:'Tahoma';}");
    lblChooseFileMsg->setAlignment(Qt::AlignCenter);

    btnStart->setGeometry(380,500,400,40);
    btnStart->setObjectName("yellow");
    proBar->setGeometry(380,560,400,30);
    proBar->setRange(0,100); //设置进度条最小值和最大值(取值范围)
    proBar->setOrientation(Qt::Horizontal);  //水平方向
    proBar->setAlignment(Qt::AlignVCenter);  // 对齐方式
    proBar->setInvertedAppearance(false); //true:反方向  false:正方向
    proBar->setVisible(false);  //false:隐藏进度条  true:显示进度条
    proBar->setFormat(tr("当前进度 : %p%"));
    proBar->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);  // 对齐方式
    lblDone->setGeometry(380,610,400,30);
    lblDone->setStyleSheet("QLabel{background:rgb(18,18,18);color:#e9d7df;font:bond;font-size:16px;font-family:'Tahoma';}");
    lblDone->setAlignment(Qt::AlignCenter);
}

void VideoTranscodeWindow::initConnect()
{
    connect(btnSearch,SIGNAL(clicked()),this,SLOT(searchVideoRecord()));
    connect(this,SIGNAL(resetVideoRecord()),table,SLOT(resetVideoList()));
    connect(table,SIGNAL(selectedChange(int,int)),this,SLOT(playVideoChoosed(int,int)));
    connect(btnOpen,SIGNAL(clicked()),this,SLOT(chooseSavePath()));
    connect(btnStart,SIGNAL(clicked()),this,SLOT(transcode()));
    connect(fdecode,SIGNAL(sendNum(int)),this,SLOT(setProBarValue(int)));
    connect(fdecode,SIGNAL(transcodeDone()),this,SLOT(setTranscodeDone()));
}

void VideoTranscodeWindow::searchVideoRecord()
{
    if(etDateBegin->text()>etDateEnd->text())
    {
        lblMsg->setText("起始日期要比终止日期大");
    }
    else
    {
        lblMsg->setText("");
        videoController->searchVideoByDate(etDateBegin->text(),etDateEnd->text());
        emit resetVideoRecord();
    }
}

void VideoTranscodeWindow::playVideoChoosed(int row,int col)
{
    int dst=row*table->colNum+col,count=0;
    int videonum=videoController->getVideoVector()->size();
    if(dst+1>videonum)
        return;
    vector<Video>::iterator it=videoController->getVideoVector()->begin();
    while(count!=dst)
    {
        count++;
        ++it;
    }
    videoController->setVectorIndex(dst);
    videoController->setVideoName(it->getName());
    videoController->setVideoSize(it->getSize());
    videoController->setVideoPath(it->getPath());
    this->isChoosed=true;
}

void VideoTranscodeWindow::chooseSavePath()
{
    etFilePath->setText(QFileDialog::getExistingDirectory (this,"选择文件夹",settingController->getVideoPath()));
}

void VideoTranscodeWindow::transcode()
{
    lblDone->setText("");
    if(etFilePath->text()=="")
        lblPathMsg->setText("保存路径不可为空");
    else
    {
        lblPathMsg->setText("");
        if(this->isChoosed==false)
            lblChooseFileMsg->setText("未选择要转码的视频");
        else
        {
            proBar->setVisible(true);
            lblChooseFileMsg->setText("");
            fdecode->dstDir=etFilePath->text();
            fdecode->fileName=videoController->getVideoPath();
            videoSize=videoController->getVideoSize().toInt();
            if(chkForm->currentText()=="mp4")
            {
                fdecode->choose=H264_TO_MP4;
            }
            else if(chkForm->currentText()=="avi")
            {
                fdecode->choose=H264_TO_AVI;
            }
            else if(chkForm->currentText()=="mov")
            {
                fdecode->choose=H264_TO_MOV;
            }
            fdecode->start();
        }
    }
}

void VideoTranscodeWindow::setProBarValue(int nowframe)
{
    proBar->setValue(nowframe*100/this->videoSize);  //设置当前的运行值
}

void VideoTranscodeWindow::setTranscodeDone()
{
    lblDone->setText("转码完成!");
    proBar->setValue(100);
    this->update();
}

