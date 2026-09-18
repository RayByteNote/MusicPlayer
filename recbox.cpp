#include "recbox.h"
#include "ui_recbox.h"
#include"recboxitem.h"

recBox::recBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::recBox)
    ,row(1)
    ,col(4)
{
    ui->setupUi(this);

}

recBox::~recBox()
{
    delete ui;
}

void recBox::initRecBoxUi(QJsonArray data, int row)
{
    if(2 == row)
    {
        this->row = row;
        col = 8;
    }
    else
    {
        ui->recListDown->hide();
    }

    imageList = data;

    currentIndex = 0;
    count = ceil(imageList.size()/col);

    //在RecBox控件添加RecBoxItem
    createRecBoxItem();
}

void recBox::createRecBoxItem()
{
    QList<recBoxItem*> recboxuplist = ui->recListUp->findChildren<recBoxItem*>();
    for(auto e : recboxuplist)
    {
        ui->recListUpLayout->removeWidget(e);
        delete e;
    }

    QList<recBoxItem*> recboxdownlist = ui->recListDown->findChildren<recBoxItem*>();
    for(auto e : recboxdownlist)
    {
        ui->recListDownLayout->removeWidget(e);
        delete e;
    }


    //创建RecBoxItem对象，往RecBox中添加
    //col
    int index = 0;
    for(int i=currentIndex*col;i<col+col*currentIndex;i++)
    {
        recBoxItem* item = new recBoxItem();

        //设置图片与对应文本
        QJsonObject obj = imageList[i].toObject();
        item->setRecText(obj.value("text").toString());
        item->setRecImage(obj.value("path").toString());

        if(index>=col/2 && 2==row)
        {
            ui->recListDownLayout->addWidget(item);
        }
        else
        {
            ui->recListUpLayout->addWidget(item);
        }

        ++index;
    }


}

void recBox::on_btDown_clicked()
{
    currentIndex++;
    if(currentIndex>=count) currentIndex = 0;
    createRecBoxItem();
}


void recBox::on_btUp_clicked()
{
    currentIndex--;
    if(currentIndex<0) currentIndex=0;
    createRecBoxItem();
}

