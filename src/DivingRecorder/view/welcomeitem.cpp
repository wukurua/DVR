#include "welcomeitem.h"

WelcomeItem::WelcomeItem(QString imgPath, bool isMove, QGraphicsScene *scene, int type)
{
    this->img.load(imgPath);
    this->isMove=isMove;
    this->scene=scene;
    this->type=type;
}

QRectF WelcomeItem::boundingRect() const
{
    return QRect(0,-img.height()/2,img.width(),img.height());
}

void WelcomeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,-img.height()/2,img);//for center
}

void WelcomeItem::advance(int phase)
{
    if(isMove)
    {
        QPointF point=mapToScene(0,0);
        if(type==CAR)
        {
            if(collidingItems().count()>0)
            {
                isMove=false;
                afterColliding();
                delete this;
            }
            else
            {
                this->setPos(point.x()-15,point.y()+9);
            }
        }
        else if(type==PEOPLE)
        {
            if(collidingItems().count()>0)
            {
                isMove=false;
                //afterColliding();
                //delete this;
            }
            else
            {
                this->setPos(point.x()+5,point.y()+3);
            }
        }
    }
}

void WelcomeItem::afterColliding()
{
    WelcomeItem *boom=new WelcomeItem(":/img/cartoon/boom.png",false,nullptr,BOOM);
    scene->addItem(boom);
    boom->setPos(this->pos().x()-100,this->pos().y()-90);
}

