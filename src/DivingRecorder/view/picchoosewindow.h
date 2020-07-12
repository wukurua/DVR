#ifndef PICCHOOSEWINDOW_H
#define PICCHOOSEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QDateEdit>
#include <QLabel>
#include <QCalendarWidget>
#include <QScrollArea>
#include "control/showpicturetable.h"
#include "showpicwindow.h"

class PicChooseWindow : public QWidget
{
    Q_OBJECT
public:
    PicChooseWindow(QWidget *parent = nullptr);
    ~PicChooseWindow();
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
    ShowPictureTable *table;
    QScrollArea *scroll;
    PictureController *picController;
    ShowPicWindow *showPicWin;
signals:
    void resetPicRecord();
    void setShowPicWinImage();
public slots:
    void searchPicRecord();
    void playPicChoosed(int row,int col);
};

#endif // SHOWPICWINDOW_H
