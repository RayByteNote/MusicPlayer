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

    //在RecBox控件添加RecBoxItem
    createRecBoxItem();
}

void recBox::createRecBoxItem()
{
    //创建RecBoxItem对象，往RecBox中添加
    //col
    for(int i=0;i<col;i++)
    {
        recBoxItem* item = new recBoxItem();

        //设置图片与对应文本
        QJsonObject obj = imageList[i].toObject();
        item->setRecText(obj.value("text").toString());
        item->setRecImage(obj.value("path").toString());

        if(i>=col/2 && 2==row)
        {
            ui->recListDownLayout->addWidget(item);
        }
        else
        {
            ui->recListUpLayout->addWidget(item);
        }
    }


}

void recBox::on_btDown_clicked()
{

}


void recBox::on_btUp_clicked()
{

}

