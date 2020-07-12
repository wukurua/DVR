#ifndef VIDEOBACKCHOOSEWINDOW_H
#define VIDEOBACKCHOOSEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QDateEdit>
#include <QLabel>
#include <QCalendarWidget>
#include <QScrollArea>
#include "control/showvideotable.h"
#include "../controller/videocontroller.h"
#include "videobackwindow.h"

class VideoBackChooseWindow : public QWidget
{
    Q_OBJECT
public:
    VideoBackChooseWindow(QWidget *parent = nullptr);
    ~VideoBackChooseWindow();
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
    ShowVideoTable *table;
    QScrollArea *scroll;
    VideoController *videoController;
    VideoBackWindow *videoBackWin;
signals:
    void resetVideoRecord();
    void setVideoBackWinName();
public slots:
    void searchVideoRecord();
    void playVideoChoosed(int row,int col);
};

#endif // VIDEOPLAYBACKWINDOW_H
