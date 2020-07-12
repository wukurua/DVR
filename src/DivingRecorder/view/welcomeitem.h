#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

#define CAR 1
#define PEOPLE 2
#define BOOM 3
#define TITLE 4

class WelcomeItem : public QGraphicsItem
{
public:
    explicit WelcomeItem(QString imgPath,bool isMove,QGraphicsScene *scene,int type);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void afterColliding();
private:
    QGraphicsScene *scene;
    QPixmap img;
    bool isMove;
    int type;
};

#endif // GRAPHICSITEM_H
