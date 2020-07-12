#include "showvideotable.h"

ShowVideoTable::ShowVideoTable(int num, QWidget *parent, int type, int rowLimit) : QTableView(parent)
{
    videoController=new VideoController();
    recordNum=videoController->getVideoVector()->size();
    this->type=type;
    this->rowLimit=rowLimit;
    if(type==HORIZONTAL)
    {
        colNum=num;
        if(recordNum/colNum<rowLimit)
            rowNum=rowLimit;
        else
        {
            if(recordNum%colNum==0)
                rowNum=recordNum/colNum;
            else
                rowNum=recordNum/colNum+1;

        }
    }
    else
    {
        rowNum=num;
        if(recordNum/rowNum<4)
            colNum=4;
        else
        {
            if(recordNum%rowNum==0)
                colNum=recordNum/rowNum;
            else
                colNum=recordNum/rowNum+1;
        }
    }
    this->initWidgets();
    this->initLayout();
    this->initConnect();
}

ShowVideoTable::~ShowVideoTable()
{
    delete videoController;
}

void ShowVideoTable::initWidgets()
{
    item_model = new QStandardItemModel(this->rowNum,this->colNum);
}

void ShowVideoTable::initLayout()
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
    vector<Video>::iterator it=videoController->getVideoVector()->begin();
    for (int i = 0; i < rowNum; ++i)
    {
        for (int j = 0; j < colNum; ++j)
        {
            if(it!=videoController->getVideoVector()->end())
            {
                ShowNameLabel *lbl=new ShowNameLabel(it->getName(),it->getCover());
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

void ShowVideoTable::initConnect()
{
    connect(this,SIGNAL(clicked(const QModelIndex &)),this,SLOT(sendSelectedChange(const QModelIndex &)));
}

void ShowVideoTable::resetVideoList()
{
    recordNum=videoController->getVideoVector()->size();
    if(type==HORIZONTAL)
    {
        if(recordNum/colNum<rowLimit)
            rowNum=rowLimit;
        else
        {
            if(recordNum%colNum==0)
                rowNum=recordNum/colNum;
            else
                rowNum=recordNum/colNum+1;

        }
    }
    else
    {
        if(recordNum/rowNum<4)
            colNum=4;
        else
        {
            if(recordNum%rowNum==0)
                colNum=recordNum/rowNum;
            else
                colNum=recordNum/rowNum+1;
        }
    }
    delete item_model;
    item_model = new QStandardItemModel(this->rowNum,this->colNum);
    this->setModel(item_model);//关联view与model

    //填充内容
    QPen pen = QPen(Qt::black,50);
    QBrush brush = QBrush(Qt::black);
    vector<Video>::iterator it=videoController->getVideoVector()->begin();
    for (int i = 0; i < rowNum; ++i)
    {
        for (int j = 0; j < colNum; ++j)
        {
            if(it!=videoController->getVideoVector()->end())
            {
                ShowNameLabel *lbl=new ShowNameLabel(it->getName(),it->getCover());
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
    this->setGeometry(0,0,240*this->colNum,this->rowNum*130);
}

void ShowVideoTable::sendSelectedChange(const QModelIndex &current)
{
    emit selectedChange(current.row(),current.column());
}
