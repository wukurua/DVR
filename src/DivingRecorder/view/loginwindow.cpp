#include "loginwindow.h"

LoginWindow::LoginWindow(Dialog *parent) : Dialog(parent)
{
    userController=new UserController;
    this->initWidgets();
    this->initLayout();
    this->initConnect();
}

LoginWindow::~LoginWindow()
{
    delete registerWin;
    delete userController;
}

void LoginWindow::login()
{
    if(this->etName->text().isEmpty())
    {
        this->lblNameMsg->setText("此账号为空或不存在");
    }

    if(this->etPwd->text().isEmpty())
        this->lblPwdMsg->setText("密码不能为空");
    else
        this->lblPwdMsg->setText("");

    if(this->lblNameMsg->text().isEmpty()!=0&&this->lblPwdMsg->text().isEmpty()!=0)
    {
        QString ischecked=QString::number(chkisRememberPwd->isChecked());
        int flag=userController->searchUserByNameAndPwd(etName->text(),etPwd->text(),ischecked);
        if(flag==0)
        {
            userController->setIsRememberPwdByName(etName->text(),ischecked);
            sendIsLogin(true);
            this->close();
        }
        else
        {
            this->lblPwdMsg->setText("账号或密码不正确!");
        }
    }
}

void LoginWindow::returnHomeWin()
{
    this->close();
}

void LoginWindow::jumpToRegisterWin()
{
    this->hide();
    registerWin->show();
}

void LoginWindow::jumpToForgetPwdWin()
{
    this->hide();
    emit setNameSignal(etName->text());
    forgetPwdWin->show();
}

void LoginWindow::changePwdEchoMode(bool checked)
{
    if(checked)
    {
        etPwd->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        etPwd->setEchoMode(QLineEdit::Password);
    }
}

void LoginWindow::showLoginWin(QString name,QString pwd)
{
    this->show();
    if(name!=""&&pwd!="")
    {
        etName->setText(name);
        etPwd->setText(pwd);
    }
}

void LoginWindow::initWidgets()
{
    lblWrap=new QLabel("",this);
    lblTitle=new QLabel("Login",this);
    lblNameImg=new QLabel("",this);
    etName=new UserNameLineEdit(this);
    lblNameMsg=new QLabel("",this);
    lblPwdImg=new QLabel("",this);
    etPwd=new QLineEdit("",this);
    btnPwdShow=new QPushButton("",this);
    lblPwdMsg=new QLabel("",this);
    chkisRememberPwd=new QCheckBox("Remember the password",this);
    btnOK=new QPushButton("Login",this);
    lblRegisterMsg=new QLabel("Don't have account?",this);
    btnRegister=new QPushButton("Sign up",this);
    registerWin=new RegisterWindow();
    lblForgetPwdMsg=new QLabel("Forget your password?",this);
    btnForgetPwd=new QPushButton("Reset",this);
    forgetPwdWin=new ForgetPwdWindow();
}

void LoginWindow::initLayout()
{
    lblWrap->setGeometry(312,70,400,610);
    lblWrap->setObjectName("lblWrap");

    lblTitle->setGeometry(437,130,150,60);
    lblTitle->setAlignment(Qt::AlignHCenter);
    lblTitle->setObjectName("lblTitle");

    lblNameImg->setGeometry(365,232,40,40);
    QPixmap namepix(":/img/user.png");
    lblNameImg->setPixmap(namepix.scaled(QSize(32,32),Qt::KeepAspectRatio));

    etName->setGeometry(422,230,230,40);
    etName->lineEdit()->setPlaceholderText("USERNAME");   //占位提示符
    etName->lineEdit()->setClearButtonEnabled(true);  //设置清空按钮开启
    etName->lineEdit()->setMaxLength(20);   //长度限制设定
    etName->lineEdit()->setTextMargins(10,5,5,5);  //改变文本的边距
    etName->installEventFilter(this);

    QString namelogged=userController->getUserNameLoggedRecently();
    if(namelogged!=NULL)
        etName->setText(namelogged);

    lblNameMsg->setGeometry(422,270,230,40);
    lblNameMsg->setObjectName("lblMsg");

    lblPwdImg->setGeometry(365,312,40,40);
    QPixmap pwdpix(":/img/lock.png");
    lblPwdImg->setPixmap(pwdpix.scaled(QSize(32,32),Qt::KeepAspectRatio));

    etPwd->setGeometry(422,310,190,40);
    etPwd->setPlaceholderText("PASSWORD");
    etPwd->setEchoMode(QLineEdit::Password);  //输出模式
    etPwd->setClearButtonEnabled(true);
    etPwd->setMaxLength(40);
    etPwd->setTextMargins(10,5,5,5);
    etPwd->installEventFilter(this);

    btnPwdShow->setGeometry(625,314,28,28);
    btnPwdShow->setObjectName("btnPwdShow");
    btnPwdShow->setCheckable(true);

    lblPwdMsg->setGeometry(422,350,230,40);
    lblPwdMsg->setObjectName("lblMsg");

    chkisRememberPwd->setGeometry(422,380,200,40);

    QString pwdlogged=userController->getUserPwdLoggedRecently(etName->text());
    if(pwdlogged!=NULL)
    {
        etPwd->setText(pwdlogged);
        chkisRememberPwd->setChecked(true);
    }

    btnOK->setGeometry(362,470,300,40);
    btnOK->installEventFilter(this);

    lblRegisterMsg->setGeometry(370,540,300,40);

    btnRegister->setGeometry(576,540,80,40);
    btnRegister->setObjectName("btnNotBorder");

    lblForgetPwdMsg->setGeometry(385,570,300,40);
    lblForgetPwdMsg->setStyleSheet("QLabel{font-size:14px;}");

    btnForgetPwd->setGeometry(576,570,80,40);
    btnForgetPwd->setObjectName("btnNotBorder");
    btnForgetPwd->setStyleSheet("QPushButton{font-size:16px;}");
}

void LoginWindow::initConnect()
{
    connect(btnOK,SIGNAL(clicked()),this,SLOT(login()));
    connect(btnRegister,SIGNAL(clicked()),this,SLOT(jumpToRegisterWin()));
    connect(btnForgetPwd,SIGNAL(clicked()),this,SLOT(jumpToForgetPwdWin()));
    connect(registerWin,SIGNAL(showLoginWinSignal(QString,QString)),this,SLOT(showLoginWin(QString,QString)));
    connect(forgetPwdWin,SIGNAL(showLoginWinSignal(QString,QString)),this,SLOT(showLoginWin(QString,QString)));
    connect(btnPwdShow,SIGNAL(toggled(bool)),this,SLOT(changePwdEchoMode(bool)));
    connect(this,SIGNAL(setNameSignal(QString)),this->forgetPwdWin,SLOT(setNameSlot(QString)));
}

bool LoginWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==etName||obj==etPwd||obj==btnOK)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if(keyEvent->key()==Qt::Key_Enter||keyEvent->key()==Qt::Key_Return)
            {
                login();
                return true;
            }
        }
    }
    if(obj==etName)
    {
        if (event->type() == QEvent::FocusOut)
        {
            if(!this->etName->text().isEmpty())
            {
                int res=userController->isNameExist(etName->text());
                if(res!=0)
                {
                    this->lblNameMsg->setText("此账号不存在");
                    this->etName->clear();
                    this->etName->setFocus();
                    return true;
                }
                else
                {
                    this->lblNameMsg->setText("");
                }
            }
        }
    }
    return false;
}
