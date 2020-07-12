#ifndef SHOWPICWINDOW_H
#define SHOWPICWINDOW_H

#include "../controller/picturecontroller.h"
#include "../controller/settingcontroller.h"
#include "widget.h"

class ShowPicWindow : public Widget
{
    Q_OBJECT
public:
    explicit ShowPicWindow(Widget *parent = nullptr);
    ~ShowPicWindow();
protected:
    void initWidgets();
    void initLayout();
    void initConnect();
private:
    QLabel *player;
    QLabel *lblName;
    QLabel *lblbackground;
    QPushButton *btnLastOne;
    QPushButton *btnNextOne;
    QLabel *lblMsg;
    PictureController *picController;
signals:
    void showChooseWin();
    void beginPlaySignal();
    void resetImage();
public slots:
    void playLastOne();
    void playNextOne();
    void setShowPicWinImage();
};

#endif // SHOWPICWINDOW_H
