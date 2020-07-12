#ifndef SHOWPICTURETABLE_H
#define SHOWPICTURETABLE_H

#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QLabel>
#include <QList>
#include <QPainter>
#include "shownamelabel.h"
#include "../../controller/picturecontroller.h"

class ShowPictureTable : public QTableView
{
    Q_OBJECT
public:
    ShowPictureTable(int col=3,QWidget *parent = nullptr);
    ~ShowPictureTable();
    int colNum;
    int rowNum;
    int recordNum;
    QStandardItemModel * item_model;
protected:
    void initWidgets();
    void initLayout();
    void initConnect();
    PictureController *picController;
signals:
    void selectedChange(int,int);
public slots:
    void resetPicList();
    void sendSelectedChange(const QModelIndex &);
};

#endif // TABLESHOWPICTURE_H
