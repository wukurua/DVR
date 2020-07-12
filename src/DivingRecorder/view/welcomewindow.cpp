#include "welcomewindow.h"

WelcomeWindow::WelcomeWindow()
{
    QIcon icon(":/img/icon.png");
    this->setWindowIcon(icon);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->resize(610,610);
    this->setBackgroundBrush(QBrush(QPixmap(":/img/cartoon/road.png")));

    scene=new QGraphicsScene();
    this->setScene(scene);
    this->setSceneRect(0,0,this->width()-2,this->height()-2);//the border take up 2 pixel

    //timer
    timer=new QTimer();
    timer->start(100);
    this->count=0;

    homeWin=new HomeWindow();
    initItem();
    initConnect();
}

void WelcomeWindow::initItem()
{
    car=new WelcomeItem(":/img/cartoon/car.png",true,scene,CAR);
    scene->addItem(car);
    car->setPos(width()-20,80);//same starting position as that in "setSceneRect"

    people=new WelcomeItem(":/img/cartoon/people.png",true,nullptr,PEOPLE);
    scene->addItem(people);
    people->setPos(120,240);

    title=new WelcomeItem(":/img/cartoon/title.png",false,nullptr,TITLE);
    scene->addItem(title);
    title->setPos(130,550);
}

void WelcomeWindow::initConnect()
{
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),this,SLOT(countToEnd()));
    connect(this,SIGNAL(close()),this,SLOT(closeWin()));
    connect(this,SIGNAL(startFdecode()),homeWin,SLOT(startFdecode()));
}

void WelcomeWindow::closeWin()
{
    this->hide();
    emit startFdecode();
    homeWin->show();
}

void WelcomeWindow::countToEnd()
{
    count++;
    if(count==24)
    {
        timer->stop();
        emit close();
    }
}

