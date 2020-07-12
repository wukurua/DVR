#ifndef PLAYER_H
#define PLAYER_H

#include <QLabel>
#include <QPaintEvent>
#include <QRect>
#include <QPainter>
#include <QPushButton>
#include <QProgressBar>
#include <QComboBox>
#include <QDebug>
#include "../../tool/fdecode.h"
#include "../../controller/videocontroller.h"
#include "../../controller/settingcontroller.h"
#include "../../controller/usercontroller.h"
#include "../../controller/picturecontroller.h"

class Player : public QLabel
{
    Q_OBJECT
public:
    Player(QWidget *parent = nullptr);
    ~Player();
    void paintEvent(QPaintEvent *event) override;
    bool isFinish;
    int videoSize;
protected:
    void initWidgets();
    void initLayout();
    void initConnect();
private:
    QImage img;
    QSize qs;
    QLabel *lblName;
    QLabel *lblbackground;
    QProgressBar *proBar;
    QPushButton *btnPlay;
    QPushButton *btnLastOne;
    QPushButton *btnNextOne;
    QComboBox *chkSpeed;
    QPushButton *btnSnap;
    QLabel *lblMsg;
    FDecode *fdecode;
    SettingController *settingController;
    VideoController *videoController;
    UserController *userController;
    PictureController *picController;
signals:
    void breakFDecode();
public slots:
    void receiveImage(QImage img);
    void receiveImageAndNum(QImage img,int nowframe);
    void changeIsPlay(bool checked);
    void setVideoFinish();
    void beginPlay();
    void playLastOne();
    void playNextOne();
    void closeWindow();
    void addPic();
    void setFDecodeSpeed(const QString &text);
};

#endif // PLAYER_H
