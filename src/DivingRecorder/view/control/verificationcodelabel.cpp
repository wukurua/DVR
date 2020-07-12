#include "verificationcodelabel.h"
#include <QPaintEvent>
#include <QPainter>
#include <QTime>

VerificationCodeLabel::VerificationCodeLabel(QWidget *parent)
    : QLabel(parent)
{
    //生成随机种子
    qsrand(QTime::currentTime().second() * 1000 + QTime::currentTime().msec());
    colorArray = new QColor[letter_number];
    verificationCode = new QChar[letter_number];
    noice_point_number = this->width();
}

//重写绘制事件,以此来生成验证码
void VerificationCodeLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPoint p;
    //背景设为白色
    painter.fillRect(this->rect(), Qt::white);
    //产生4个不同的字符
    produceVerificationCode();
    //产生4个不同的颜色
    produceRandomColor();
    //绘制验证码
    for (int i = 0; i < letter_number; ++i)
    {
        p.setX(i*(this->width() / letter_number)+this->width()/8);
        p.setY(this->height() / 2);
        painter.setPen(colorArray[i]);
        painter.drawText(p, QString(verificationCode[i]));
    }
    //绘制噪点
    for (int j = 0; j < noice_point_number; ++j)
    {
        p.setX(qrand() % this->width());
        p.setY(qrand() % this->height());
        painter.setPen(colorArray[j % 4]);
        painter.drawPoint(p);
    }
    return;
}

//这是一个用来生成验证码的函数
void VerificationCodeLabel::produceVerificationCode() const
{
    for (int i = 0; i < letter_number; ++i)
        verificationCode[i] = produceRandomLetter();
    return;
}

//产生一个随机的字符
QChar VerificationCodeLabel::produceRandomLetter() const
{
    QChar c;
    int flag = qrand() % letter_number;
    switch (flag)
    {
    case NUMBER_FLAG:c='0' + qrand() % 10; break;
    case UPLETTER_FLAG:c='A' + qrand() % 26; break;
    case LOWLETTER_FLAG:c='a' + qrand() % 26; break;
    default:c=qrand() % 2 ? 'W' : 'D';
    }
    return c;
}

//产生随机的颜色
void VerificationCodeLabel::produceRandomColor() const
{
    for (int i = 0; i < letter_number; ++i)
        colorArray[i] = QColor(qrand() % 255, qrand() % 255, qrand() % 255);
    return;
}

//返回一个字符串（字母一律都按照大写返回）
QString VerificationCodeLabel::getVerificationCode() const
{
    QString s;
    QChar cTemp;
    for (int i = 0; i < letter_number; ++i)
    {
        cTemp = verificationCode[i];
        s += cTemp>97?cTemp.toUpper():cTemp;
    }
    return s;
}

//刷新验证码，在用户不确定的时候进行相应刷新
void VerificationCodeLabel::slt_reflushVerification()
{
    repaint();
}

VerificationCodeLabel::~VerificationCodeLabel()
{

}
