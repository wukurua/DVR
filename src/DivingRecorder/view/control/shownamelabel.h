#ifndef SHOWNAMELABEL_H
#define SHOWNAMELABEL_H

#include <QLabel>

class ShowNameLabel : public QLabel
{
public:
    ShowNameLabel(QString text,QString imgPath);
    ~ShowNameLabel();
private:
    QLabel *lblName;
};

#endif // SHOWNAMELABEL_H
