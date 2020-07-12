#include "picchoosewindow.h"

PicChooseWindow::PicChooseWindow(QWidget *parent)
    : QWidget(parent)
{
    picController=new PictureController();
    this->initWidgets();
    this->initLayout();
    this->initConnect();
}

PicChooseWindow::~PicChooseWindow()
{

}

void PicChooseWindow::initWidgets()
{
    lblTitle=new QLabel("照片列表",this);
    lblBegin=new QLabel("起始日期:",this);
    etDateBegin=new QDateEdit(this);
    lblEnd=new QLabel("结束日期:",this);
    etDateEnd=new QDateEdit(this);
    btnSearch=new QPushButton("查询",this);
    lblMsg=new QLabel("",this);
    scroll = new QScrollArea(this);
    table=new ShowPictureTable(3,scroll);
    showPicWin=new ShowPicWindow();
}

void PicChooseWindow::initLayout()
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

    lblMsg->setGeometry(100,130,300,35);
    lblMsg->setObjectName("lblMsg");
    lblMsg->setStyleSheet("QLabel{background:rgb(42,42,42);color:#e9d7df;font:bond;font-size:16px;font-family:'Tahoma';}");

    scroll->setGeometry(50, 180, 720, 390);
    table->setGeometry(50,180,720,table->rowNum*130);
    //设置滚动区域的窗体
    scroll->setWidget(this->table);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setStyleSheet("background:transparent");
    scroll->setFrameShape(QFrame::NoFrame);
}

void PicChooseWindow::initConnect()
{
    connect(btnSearch,SIGNAL(clicked()),this,SLOT(searchPicRecord()));
    connect(this,SIGNAL(resetPicRecord()),table,SLOT(resetPicList()));
    connect(table,SIGNAL(selectedChange(int,int)),this,SLOT(playPicChoosed(int,int)));
    connect(this,SIGNAL(setShowPicWinImage()),showPicWin,SLOT(setShowPicWinImage()));
}

void PicChooseWindow::searchPicRecord()
{
    if(etDateBegin->text()>etDateEnd->text())
    {
        lblMsg->setText("起始日期要比终止日期大");
    }
    else
    {
        lblMsg->setText("");
        picController->searchPicByDate(etDateBegin->text(),etDateEnd->text());
        emit resetPicRecord();
    }
}

void PicChooseWindow::playPicChoosed(int row,int col)
{
    int dst=row*table->colNum+col,count=0;
    int picnum=picController->getPicVector()->size();
    if(dst+1>picnum)
        return;
    vector<Picture>::iterator it=picController->getPicVector()->begin();
    while(count!=dst)
    {
        count++;
        ++it;
    }
    picController->setVectorIndex(dst);
    picController->setPicName(it->getName());
    picController->setPicPath(it->getPath());
    emit setShowPicWinImage();
    showPicWin->show();
}

