#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "registerwindow.h"
#include "forgetpwdwindow.h"
#include "../controller/usercontroller.h"
#include "control/usernamelineedit.h"
#include <QDebug>

class LoginWindow : public Dialog

{
    Q_OBJECT
public:
    explicit LoginWindow(Dialog *parent = nullptr);
    ~LoginWindow();
protected:
    void initWidgets();
    void initLayout();
    void initConnect();
    bool eventFilter(QObject *obj, QEvent *ev) override;
private:
    QLabel *lblWrap;
    QLabel *lblTitle;
    QLabel *lblNameImg;
    QLabel *lblPwdImg;
    UserNameLineEdit *etName;
    QLineEdit *etPwd;
    QPushButton *btnPwdShow;
    QLabel *lblNameMsg;
    QLabel *lblPwdMsg;
    QLabel *lblRegisterMsg;
    QCheckBox *chkisRememberPwd;
    QPushButton *btnOK;
    QPushButton *btnRegister;
    RegisterWindow *registerWin;
    QLabel *lblForgetPwdMsg;
    QPushButton *btnForgetPwd;
    ForgetPwdWindow *forgetPwdWin;
    UserController *userController;
signals:
    void showLoginWinSignal(QString name,QString pwd);
    void setNameSignal(QString name);
    void sendIsLogin(bool);
public slots:
    void login();
    void returnHomeWin();
    void jumpToRegisterWin();
    void jumpToForgetPwdWin();
    void changePwdEchoMode(bool checked);
    void showLoginWin(QString name,QString pwd);
};

#endif // LOGINWINDOW_H
