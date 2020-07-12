#ifndef VIDEOTRANSCODEWINDOW_H
#define VIDEOTRANSCODEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QDateEdit>
#include <QLabel>
#include <QCalendarWidget>
#include <QScrollArea>
#include <QComboBox>
#include <QFileDialog>
#include <QProgressBar>
#include <QLineEdit>
#include "control/showvideotable.h"
#include "../controller/videocontroller.h"
#include "../controller/settingcontroller.h"
#include "../tool/fdecode.h"

class VideoTranscodeWindow : public QWidget
{
    Q_OBJECT
public:
    explicit VideoTranscodeWindow(QWidget *parent = nullptr);
    ~VideoTranscodeWindow();
protected:
    void initWidgets();
    void initLayout();
    void initConnect();
private:
    QLabel *lblTitle;
    QLabel *lblBegin;
    QDateEdit *etDateBegin;
    QLabel *lblEnd;
    QDateEdit *etDateEnd;
    QPushButton *btnSearch;
    QLabel *lblMsg;
    QLabel *lblWrap;
    QLabel *lblWrap1;
    QLabel *lblVideo;
    ShowVideoTable *table;
    QScrollArea *scroll;
    QLabel *lblForm;
    QComboBox *chkForm;
    QLabel *lblPath;
    QLineEdit *etFilePath;
    QPushButton *btnOpen;
    QFileDialog *openvideo;
    QLabel *lblPathMsg;
    QLabel *lblChooseFileMsg;
    QPushButton *btnStart;
    QProgressBar *proBar;
    QLabel *lblDone;
    VideoController *videoController;
    SettingController *settingController;
    FDecode *fdecode;
    bool isChoosed;
    int videoSize;
signals:
    void resetVideoRecord();
public slots:
    void searchVideoRecord();
    void playVideoChoosed(int row,int col);
    void chooseSavePath();
    void transcode();
    void setProBarValue(int nowframe);
    void setTranscodeDone();
};

#endif // VIDEOTRANSCODEWINDOW_H
