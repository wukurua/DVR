#include "showpicturetable.h"

ShowPictureTable::ShowPictureTable(int col, QWidget *parent) : QTableView(parent)
{
    picController=new PictureController();
    recordNum=picController->getPicVector()->size();
    colNum=col;
    if(recordNum/colNum<3)
        rowNum=3;
    else
    {
        if(recordNum%colNum==0)
            rowNum=recordNum/colNum;
        else
            rowNum=recordNum/colNum+1;

    }
    this->initWidgets();
    this->initLayout();
    this->initConnect();
}

ShowPictureTable::~ShowPictureTable()
{
    delete picController;
}

void ShowPictureTable::initWidgets()
{
    item_model = new QStandardItemModel(this->rowNum,this->colNum);
}

void ShowPictureTable::initLayout()
{
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//所有列都扩展自适应宽度，填充充满整个屏幕宽度
    this->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//所有列都扩展自适应宽度，填充充满整个屏幕宽度
    this->verticalHeader()->setVisible(false); //隐藏列表头
    this->horizontalHeader()->setVisible(false); //隐藏行表头
    this->setFocusPolicy(Qt::NoFocus);
    this->setModel(item_model);//关联view与model

    //填充内容
    QPen pen = QPen(Qt::black,50);
    QBrush brush = QBrush(Qt::black);
    vector<Picture>::iterator it=picController->getPicVector()->begin();
    for (int i = 0; i < rowNum; ++i)
    {
        for (int j = 0; j < colNum; ++j)
        {
            if(it!=picController->getPicVector()->end())
            {
                ShowNameLabel *lbl=new ShowNameLabel(it->getName(),it->getPath());
                this->setIndexWidget(item_model->index(i,j),lbl);
                ++it;
            }
            else
            {
                QLabel *lbl=new QLabel("");
                lbl->setScaledContents(true);//设置图片适应label
                QPixmap pix(100,80);
                pix.fill(Qt::black);
                lbl->setPixmap(pix);
                this->setIndexWidget(item_model->index(i,j),lbl);
            }
        }
    }
}

void ShowPictureTable::initConnect()
{
    connect(this,SIGNAL(clicked(const QModelIndex &)),this,SLOT(sendSelectedChange(const QModelIndex &)));
}

void ShowPictureTable::resetPicList()
{
    recordNum=picController->getPicVector()->size();
    if(recordNum/colNum<3)
        rowNum=3;
    else
    {
        if(recordNum%colNum==0)
            rowNum=recordNum/colNum;
        else
            rowNum=recordNum/colNum+1;

    }
    delete item_model;
    item_model = new QStandardItemModel(this->rowNum,this->colNum);
    this->setModel(item_model);//关联view与model

    //填充内容
    QPen pen = QPen(Qt::black,50);
    QBrush brush = QBrush(Qt::black);
    vector<Picture>::iterator it=picController->getPicVector()->begin();
    for (int i = 0; i < rowNum; ++i)
    {
        for (int j = 0; j < colNum; ++j)
        {
            if(it!=picController->getPicVector()->end())
            {
                ShowNameLabel *lbl=new ShowNameLabel(it->getName(),it->getPath());
                this->setIndexWidget(item_model->index(i,j),lbl);
                ++it;
            }
            else
            {
                QLabel *lbl=new QLabel("");
                lbl->setScaledContents(true);//设置图片适应label
                QPixmap pix(100,80);
                pix.fill(Qt::black);
                lbl->setPixmap(pix);
                this->setIndexWidget(item_model->index(i,j),lbl);
            }
        }
    }
    connect(this,SIGNAL(clicked(const QModelIndex &)),this,SLOT(sendSelectedChange(const QModelIndex &)));
    this->setGeometry(0,0,720,this->rowNum*130);
}

void ShowPictureTable::sendSelectedChange(const QModelIndex &current)
{
    emit selectedChange(current.row(),current.column());
}
