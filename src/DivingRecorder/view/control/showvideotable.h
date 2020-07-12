#ifndef SHOWVIDEOTABLE_H
#define SHOWVIDEOTABLE_H

#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QLabel>
#include <QList>
#include <QPainter>
#include "shownamelabel.h"
#include "../../controller/videocontroller.h"

#define HORIZONTAL 1
#define VERTICAL 2

class ShowVideoTable : public QTableView
{
    Q_OBJECT
public:
    ShowVideoTable(int num,QWidget *parent = nullptr,int type = HORIZONTAL,int rowLimit=3);
    ~ShowVideoTable();
    int type;
    int rowLimit;
    int colNum;
    int rowNum;
    int recordNum;
    QStandardItemModel * item_model;
protected:
    void initWidgets();
    void initLayout();
    void initConnect();
    VideoController *videoController;
signals:
    void selectedChange(int,int);
public slots:
    void resetVideoList();
    void sendSelectedChange(const QModelIndex &);
};

#endif // SHOWVIDEOTABLE_H
