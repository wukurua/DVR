#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QTimer>
#include "welcomeitem.h"

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView();
    void initItem();
    void initConnect();
private:
    QGraphicsScene *scene;
    GraphicsItem *car;
    GraphicsItem *railing;
    QTimer *timer;
};

#endif // GRAPHICSVIEW_H
