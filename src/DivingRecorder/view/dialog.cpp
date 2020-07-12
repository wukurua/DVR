#include "dialog.h"

Dialog::Dialog(QDialog *parent) : QDialog(parent)
{
    QIcon icon(":/img/icon.png");
    this->setWindowIcon(icon);

    //window appears in middle automatically
    //QDesktopWidget *desk=QApplication::desktop();
    //move((desk->width()-width())/2,(desk->height()-height())/2);

    this->setFixedSize(1024,750);//1300,830
    //window without own title bar
    this->setWindowFlags(Qt::FramelessWindowHint);

    //the border-radius of window
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),10,10);
    setMask(bmp);

    //show window after clicking task bar
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    //customed title bar
    lblBar=new QLabel("",this);
    lblBar->setGeometry(0,0,1024,25);
    lblBar->setStyleSheet("background:rgb(18,18,18);");
    btnClose=new QPushButton(this);
    btnClose->setGeometry(998,5,15,15);
    btnClose->setObjectName("btnClose");

    btnMinimize=new QPushButton(this);
    btnMinimize->setGeometry(980,5,15,15);
    btnMinimize->setObjectName("btnMinimize");

    connect(btnMinimize,SIGNAL(clicked()),this,SLOT(minisizeWindow()));
    connect(btnClose,SIGNAL(clicked()),this,SLOT(closeWindow()));
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        this->isMousePress=true;
        this->mouseStartPoint=event->globalPos();
        this->windowTopLeftPoint=this->frameGeometry().topLeft();
    }
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if(this->isMousePress)
    {
        QPoint distance=event->globalPos()-mouseStartPoint;
        this->move(windowTopLeftPoint+distance);
    }
}

void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        this->isMousePress=false;
    }
}

void Dialog::minisizeWindow()
{
    this->showMinimized();
}

void Dialog::closeWindow()
{
    this->close();
}
