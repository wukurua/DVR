#include "piclabel.h"

PicLabel::~PicLabel()
{

}

PicLabel::PicLabel(QWidget *parent)
    : QLabel(parent)
{
    this->setScaledContents(true);
    this->resize(800,450);
    qs=this->size();
}

void PicLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!img.isNull())
    {
        painter.drawImage(QRect(0,0,this->img.width(),this->img.height()),this->img);
    }
}

void PicLabel::receiveImage(QImage img)
{
    this->img=img.scaled(qs);
    this->update();
}
