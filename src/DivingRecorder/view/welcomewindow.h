#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "welcomeitem.h"
#include "view/homewindow.h"

class WelcomeWindow : public QGraphicsView
{
    Q_OBJECT
public:
    WelcomeWindow();
    void initItem();
    void initConnect();
private:
    QGraphicsScene *scene;
    WelcomeItem *car;
    WelcomeItem *people;
    WelcomeItem *title;
    QTimer *timer;
    HomeWindow *homeWin;
    int count;
signals:
    void close();
    void startFdecode();
public slots:
    void closeWin();
    void countToEnd();
};

#endif // GRAPHICSVIEW_H
