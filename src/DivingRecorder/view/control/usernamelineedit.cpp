#include "usernamelineedit.h"

UserNameLineEdit::UserNameLineEdit(QWidget *parent):QComboBox(parent)
{
    userController=new UserController;
    this->initData();
    this->setView(new QListView());
}

UserNameLineEdit::~UserNameLineEdit()
{
    delete userController;
}

QString UserNameLineEdit::text()
{
    return this->currentText().trimmed();
}

void UserNameLineEdit::setText(QString text)
{
    this->lineEdit()->setText(text);
}

void UserNameLineEdit::initData()
{
    this->setEditable(true);
    this->lineEdit();
    list<User>::iterator it=userController->getUserList()->begin();
    for(;it!=userController->getUserList()->end();++it)
    {
        addItem(it->getName());
    }
}

