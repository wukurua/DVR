#ifndef USERNAMELINEEDIT_H
#define USERNAMELINEEDIT_H

#include <QComboBox>
#include <QLineEdit>
#include <QListView>
#include "../../controller/usercontroller.h"

#define NameMaxLen 20 //限制用户名的最大输入长度

class UserNameLineEdit : public QComboBox
{
    Q_OBJECT
public:
    UserNameLineEdit(QWidget *parent = nullptr);
    ~UserNameLineEdit();
    QString text();
    void setText(QString text);
private:
    UserController *userController;
    void initData();
    void initConnect();
};

#endif // USERNAMELINEEDIT_H
