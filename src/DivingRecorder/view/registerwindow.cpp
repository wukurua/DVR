#include "registerwindow.h"

RegisterWindow::RegisterWindow(Dialog *parent) : Dialog(parent)
{
    userController=new UserController;
    this->initWidgets();
    this->initLayout();
    this->initConnect();
}

void RegisterWindow::Register()
{
    if(this->etName->text().isEmpty())
    {
        this->lblNameMsg->setText("账号不可为空");
    }
    else
    {
        if(this->etName->text().length()<6||this->etName->text().length()>12)
            this->lblNameMsg->setText("账号必须在6~12位之间");
    }

    if(this->etPwd->text().isEmpty())
        this->lblPwdMsg->setText("密码不可为空");
    else
    {
//        bool res=userController->isMatchRegX(this->etPwd->text());
//        if(res)
//            this->lblPwdMsg->setText("");
//        else
//            this->lblPwdMsg->setText("限制大小写数字，长度6~16位");
        if(this->etPwd->text().length()<6||this->etPwd->text().length()>16)
            this->lblPwdMsg->setText("密码长度必须为6~16位");
        else
            this->lblPwdMsg->setText("");
    }

    if(this->etRepeatPwd->text().isEmpty())
        this->lblRepeatPwdMsg->setText("密码不可为空");
    else
    {
        if(this->etRepeatPwd->text()!=this->etPwd->text())
            this->lblRepeatPwdMsg->setText("两次输入的密码不一致");
        else
            this->lblRepeatPwdMsg->setText("");
    }

    if(this->etTelePhone->text().isEmpty())
        this->lblTelephoneMsg->setText("电话不可为空");
    else
    {
        if(this->etTelePhone->text().length()!=11)
            this->lblTelephoneMsg->setText("电话必须是11位");
        else
            this->lblTelephoneMsg->setText("");
    }

    if(this->etCode->text().isEmpty())
        this->lblCodeMsg->setText("验证码不可为空");
    else
    {
        QString correctcode = this->lblVerficationCode->getVerificationCode();
        QString codeUpper;
        QString code = this->etCode->text();
        QChar cTemp;
        for(int i=0;i<lblVerficationCode->letter_number;++i)
        {
            cTemp = code[i];
            codeUpper += cTemp>97?cTemp.toUpper():cTemp;
        }
        if(codeUpper!=correctcode)
        {
            this->lblCodeMsg->setText("验证码错误");
        }
        else
            this->lblCodeMsg->setText("");
    }

    if(this->lblNameMsg->text().isEmpty()!=0&&this->lblPwdMsg->text().isEmpty()!=0&&this->lblRepeatPwdMsg->text().isEmpty()!=0
            &&this->lblTelephoneMsg->text().isEmpty()!=0&&this->lblCodeMsg->text().isEmpty()!=0)
    {
        userController->addUser(etName->text(),etPwd->text(),etTelePhone->text());
        emit showLoginWinSignal(etName->text(),etPwd->text());
        this->close();
    }
}

void RegisterWindow::jumpToLoginWin()
{
    emit showLoginWinSignal("","");
    this->hide();
}

void RegisterWindow::refreshCode()
{
    lblVerficationCode->slt_reflushVerification();
}

void RegisterWindow::initWidgets()
{
    lblWrap=new QLabel("",this);
    lblTitle=new QLabel("Register",this);
    lblNameImg=new QLabel("",this);
    etName=new QLineEdit("",this);
    lblNameMsg=new QLabel("",this);
    lblPwdImg=new QLabel("",this);
    etPwd=new QLineEdit("",this);
    lblPwdMsg=new QLabel("",this);
    lblRepeatPwdImg=new QLabel("",this);
    etRepeatPwd=new QLineEdit("",this);
    lblRepeatPwdMsg=new QLabel("",this);
    lblTelephoneImg=new QLabel("",this);
    etTelePhone=new QLineEdit("",this);
    lblTelephoneMsg=new QLabel("",this);
    lblVerficationCode=new VerificationCodeLabel(this);
    btnFreshCode=new QPushButton("",this);
    etCode=new QLineEdit("",this);
    lblCodeMsg=new QLabel("",this);
    btnOK=new QPushButton("Register",this);
    btnReturn=new QPushButton("Return",this);
}

void RegisterWindow::initLayout()
{
    lblWrap->setGeometry(312,70,400,610);
    lblWrap->setObjectName("lblWrap");
    lblTitle->setGeometry(437,130,150,60);
    lblTitle->setAlignment(Qt::AlignHCenter);
    lblTitle->setObjectName("lblTitle");

    lblNameImg->setGeometry(362,232,40,40);
    QPixmap namepix(":/img/user.png");
    lblNameImg->setPixmap(namepix.scaled(QSize(32,32),Qt::KeepAspectRatio));

    etName->setGeometry(422,230,230,40);
    etName->setPlaceholderText("USERNAME");   //占位提示符
    etName->setClearButtonEnabled(true);  //设置清空按钮开启
    etName->setMaxLength(20);   //长度限制设定
    etName->setTextMargins(10,5,5,5);  //改变文本的边距
    etName->installEventFilter(this);
    etName->installEventFilter(this);

    lblNameMsg->setGeometry(422,270,230,30);
    lblNameMsg->setObjectName("lblMsg");

    lblPwdImg->setGeometry(362,302,40,40);
    QPixmap pwdpix(":/img/lock.png");
    lblPwdImg->setPixmap(pwdpix.scaled(QSize(32,32),Qt::KeepAspectRatio));

    etPwd->setGeometry(422,300,230,40);
    etPwd->setPlaceholderText("PASSWORD");
    etPwd->setEchoMode(QLineEdit::Password);  //输出模式
    etPwd->setClearButtonEnabled(true);
    etPwd->setMaxLength(20);
    etPwd->setTextMargins(10,5,5,5); //改变文本的边距
    etPwd->installEventFilter(this);

    lblPwdMsg->setGeometry(422,340,230,30);
    lblPwdMsg->setObjectName("lblMsg");

    lblRepeatPwdImg->setGeometry(362,372,40,40);
    QPixmap repeatpwdpix(":/img/lock.png");
    lblRepeatPwdImg->setPixmap(repeatpwdpix.scaled(QSize(32,32),Qt::KeepAspectRatio));

    etRepeatPwd->setGeometry(422,370,230,40);
    etRepeatPwd->setPlaceholderText("CONFIRM PASSWORD");
    etRepeatPwd->setEchoMode(QLineEdit::Password);  //输出模式
    etRepeatPwd->setClearButtonEnabled(true);
    etRepeatPwd->setMaxLength(20);
    etRepeatPwd->setTextMargins(10,5,5,5);
    etRepeatPwd->installEventFilter(this);

    lblRepeatPwdMsg->setGeometry(422,410,230,30);
    lblRepeatPwdMsg->setObjectName("lblMsg");

    lblTelephoneImg->setGeometry(362,452,230,40);
    QPixmap telpix(":/img/phonecall.png");
    lblTelephoneImg->setPixmap(telpix.scaled(QSize(32,32),Qt::KeepAspectRatio));

    etTelePhone->setGeometry(422,440,230,40);
    etTelePhone->setPlaceholderText("TELEPHONE");
    etTelePhone->setClearButtonEnabled(true);
    etTelePhone->setMaxLength(11);
    etTelePhone->setTextMargins(10,5,5,5);
    etTelePhone->installEventFilter(this);

    lblTelephoneMsg->setGeometry(422,480,230,30);
    lblTelephoneMsg->setObjectName("lblMsg");

    lblVerficationCode->setGeometry(362,520,100,40);

    btnFreshCode->setGeometry(475,522,32,32);
    btnFreshCode->setObjectName("btnFreshCode");

    etCode->setGeometry(522,520,140,40);
    etCode->setPlaceholderText("CAPTCHA");
    etCode->setClearButtonEnabled(true);
    etCode->setMaxLength(4);
    etCode->setTextMargins(10,5,5,5);
    etCode->setObjectName("etCode");
    etCode->installEventFilter(this);

    lblCodeMsg->setGeometry(530,560,160,30);
    lblCodeMsg->setObjectName("lblMsg");

    btnReturn->setGeometry(355,600,150,40);
    btnReturn->setObjectName("btnReturn");

    btnOK->setGeometry(510,600,150,40);
    btnOK->installEventFilter(this);
}

void RegisterWindow::initConnect()
{
    connect(btnOK,SIGNAL(clicked(bool)),this,SLOT(Register()));
    connect(btnReturn,SIGNAL(clicked(bool)),this,SLOT(jumpToLoginWin()));
    connect(btnFreshCode,SIGNAL(clicked(bool)),this,SLOT(refreshCode()));
}

bool RegisterWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==etName||obj==etPwd||obj==etRepeatPwd||obj==etTelePhone||obj==etCode||obj==btnOK)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if(keyEvent->key()==Qt::Key_Enter||keyEvent->key()==Qt::Key_Return)
            {
                Register();
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
                if(res==0)
                {
                    this->lblNameMsg->setText("此账号已存在");
                    this->etName->clear();
                    this->etName->setFocus();
                    return true;
                }
                else
                    this->lblNameMsg->setText("");
            }
        }
    }
    return false;
}

RegisterWindow::~RegisterWindow()
{
    delete userController;
}
