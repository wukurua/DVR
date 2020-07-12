#ifndef PICLABEL_H
#define PICLABEL_H

#include <QLabel>
#include <QPaintEvent>
#include <QRect>
#include <QPainter>
#include <QPushButton>

class PicLabel : public QLabel
{
    Q_OBJECT
public:
    PicLabel(QWidget *parent = nullptr);
    ~PicLabel();
    void paintEvent(QPaintEvent *event);
    QImage img;
private:
    QSize qs;
public slots:
    void receiveImage(QImage img);
};

#endif // PLAYER_H
