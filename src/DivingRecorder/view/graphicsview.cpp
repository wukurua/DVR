#include "graphicsview.h"

GraphicsView::GraphicsView()
{
    this->resize(1024,768);
    this->setBackgroundBrush(QBrush(QPixmap(":/img/chedao.png")));

    scene=new QGraphicsScene();
    this->setScene(scene);
    this->setSceneRect(0,0,this->width()-2,this->height()-2);//the border take up 2 pixel

    //timer
    timer=new QTimer();
    timer->start(100);

    initItem();
    initConnect();
}

void GraphicsView::initItem()
{
    car=new GraphicsItem(":/img/car.png",true,scene);
    scene->addItem(car);
    car->setPos(0,height()/2);//same starting position as that in "setSceneRect"

    railing=new GraphicsItem(":/img/weilan.png",false,nullptr);
    scene->addItem(railing);
    railing->setPos(width()-150,height()/2);
}

void GraphicsView::initConnect()
{
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
}

