#ifndef SMALLSETTINGWINDOW_H
#define SMALLSETTINGWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QBitmap>
#include <QPainter>
#include <QAction>
#include <QComboBox>
#include <QFileDialog>
#include "../controller/settingcontroller.h"
#include <QCamera>
#include <QCameraInfo>

class SmallSettingWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SmallSettingWindow(QWidget *parent = nullptr);
    ~SmallSettingWindow();
protected:
    void initWidgets();
    void initLayout();
    void initConnect();
    bool eventFilter(QObject *obj, QEvent *ev);
private:
    QLabel *lblWrap;
    QLabel *lblTitle;
    QLabel *lblCameraImg;
    QLabel *lblVideoPathImg;
    QLabel *lblPicturePathImg;
    QLabel *lblDurationImg;
    QPushButton *btnCheckMore;
    QPushButton *btnCheckMore1;
    QLabel *lblCameraChooseMag;
    QComboBox *chkCamera;
    QLineEdit *etVideoPath;
    QLineEdit *etPicturePath;
    QLineEdit *etDuration;
    QLabel *lblCameraMsg;
    QLabel *lblVideoPathMsg;
    QLabel *lblPicturePathMsg;
    QLabel *lblDurationMsg;
    QPushButton *btnOK;
    QFileDialog *openvideo;
    QString fileName;
    SettingController *settingController;
signals:
    void showHomeWinSignal();
public slots:
    void commit();
    void chooseVideoPath();
    void choosePicturePath();
};

#endif // SMALLSETTINGWINDOW_H
