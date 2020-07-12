#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include "welcomewindow.h"
#include "../controller/settingcontroller.h"
#include <QCamera>
#include <QCameraInfo>

class SettingWindow : public Widget
{
    Q_OBJECT
public:
    explicit SettingWindow(Widget *parent = nullptr);
    ~SettingWindow();
protected:
    void initWidgets();
    void initLayout();
    void initConnect();
    bool eventFilter(QObject *obj, QEvent *ev) override;
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
    WelcomeWindow *welcomeWin;
signals:
    void showWelcomeWinSignal();
public slots:
    void commit();
    void chooseVideoPath();
    void choosePicturePath();
    void jumpToWelcomeWin();
};

#endif // SETTINGWINDOW_H
