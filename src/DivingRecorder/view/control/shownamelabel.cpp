#include "shownamelabel.h"


ShowNameLabel::ShowNameLabel(QString text, QString imgPath)
{
    this->resize(423,130);
    lblName=new QLabel(text,this);
    lblName->setGeometry(2,2,235,20);
    lblName->setAlignment(Qt::AlignCenter);
    lblName->setStyleSheet("QLabel{background:white;color:black;font-size: 13px;font-family: 'Tahoma';}");
    QImage img(imgPath);
    QPixmap pix=QPixmap::fromImage(img);
    this->setPixmap(pix);
    this->setScaledContents(true);//设置图片适应label
}

ShowNameLabel::~ShowNameLabel()
{
    delete lblName;
}
