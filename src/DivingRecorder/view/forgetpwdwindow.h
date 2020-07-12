#ifndef FORGETPWDWINDOW_H
#define FORGETPWDWINDOW_H

#include "dialog.h"
#include "control/verificationcodelabel.h"
#include "../controller/usercontroller.h"

class ForgetPwdWindow : public Dialog
{
    Q_OBJECT
public:
    explicit ForgetPwdWindow(Dialog *parent = nullptr);
    ~ForgetPwdWindow();
    void initWidgets();
    void initLayout();
    void initConnect();
protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;
private:
    QLabel *lblWrap;
    QLabel *lblTitle;
    QLabel *lblNameImg;
    QLabel *lblPwdImg;
    QLabel *lblRepeatPwdImg;
    QLabel *lblNameMsg;
    QLabel *lblPwdMsg;
    QLabel *lblRepeatPwdMsg;
    QLineEdit *etName;
    QLineEdit *etPwd;
    QLineEdit *etRepeatPwd;
    QLabel *lblTelephoneImg;
    QLineEdit *etTelePhone;
    QLabel *lblTelephoneMsg;
    VerificationCodeLabel *lblVerficationCode;
    QLineEdit *etCode;
    QPushButton *btnFreshCode;
    QLabel *lblCodeMsg;
    QPushButton *btnOK;
    QPushButton *btnReturn;
    Dialog *loginWin;
    UserController *userController;
signals:
    void showLoginWinSignal(QString name,QString pwd);
public slots:
    void commit();
    void jumpToLoginWin();
    void refreshCode();
    void setNameSlot(QString name);
};

#endif // FORGETPWDWINDOW_H
