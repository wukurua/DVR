#ifndef VerificationCodeLabel_H
#define VerificationCodeLabel_H
//这是一个继承QLabel从而用来实现验证码功能的标签
#include <QLabel>

class VerificationCodeLabel : public QLabel
{
    Q_OBJECT
public:
    VerificationCodeLabel(QWidget *parent = nullptr);
    ~VerificationCodeLabel();
    //返回一个字符串（字母一律都按照大写返回）
    QString getVerificationCode() const;
    int noice_point_number ;//噪点的数量
    const int letter_number = 4;//产生字符的数量
public slots:
    //公共槽函数
    //刷新验证码，在用户不确定的时候进行相应刷新
    void slt_reflushVerification();
protected:
    //重写绘制事件,以此来生成验证码
    void paintEvent(QPaintEvent *event);
private:
    enum {
        NUMBER_FLAG,
        UPLETTER_FLAG,
        LOWLETTER_FLAG
    };
    //这是一个用来生成验证码的函数
    void produceVerificationCode() const;
    //产生一个随机的字符
    QChar produceRandomLetter() const;
    //产生随机的颜色
    void produceRandomColor() const;

    QChar *verificationCode;
    QColor *colorArray;
};

#endif // VerificationCodeLabel_H

