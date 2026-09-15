#include "btform.h"
#include "ui_btform.h"

BtForm::BtForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BtForm)
{
    ui->setupUi(this);

    //设置line1的动画
    AnimationLine1 = new QPropertyAnimation(ui->line1,"geometry",this);
    AnimationLine1->setDuration(1500);
    AnimationLine1->setKeyValueAt(0,QRect(0,15,2,0));
    AnimationLine1->setKeyValueAt(0.5,QRect(0,0,2,15));
    AnimationLine1->setKeyValueAt(1,QRect(0,15,2,0));
    AnimationLine1->setLoopCount(-1);
    AnimationLine1->start();
    //line2
    AnimationLine2 = new QPropertyAnimation(ui->line2,"geometry",this);
    AnimationLine2->setDuration(1600);
    AnimationLine2->setKeyValueAt(0,QRect(7,15,2,0));
    AnimationLine2->setKeyValueAt(0.5,QRect(7,0,2,15));
    AnimationLine2->setKeyValueAt(1,QRect(7,15,2,0));
    AnimationLine2->setLoopCount(-1);
    AnimationLine2->start();
    //line3
    AnimationLine3 = new QPropertyAnimation(ui->line3,"geometry",this);
    AnimationLine3->setDuration(1700);
    AnimationLine3->setKeyValueAt(0,QRect(14,15,2,0));
    AnimationLine3->setKeyValueAt(0.5,QRect(14,0,2,15));
    AnimationLine3->setKeyValueAt(1,QRect(14,15,2,0));
    AnimationLine3->setLoopCount(-1);
    AnimationLine3->start();
    //line4
    AnimationLine4 = new QPropertyAnimation(ui->line4,"geometry",this);
    AnimationLine4->setDuration(1800);
    AnimationLine4->setKeyValueAt(0,QRect(21,15,2,0));
    AnimationLine4->setKeyValueAt(0.5,QRect(21,0,2,15));
    AnimationLine4->setKeyValueAt(1,QRect(21,15,2,0));
    AnimationLine4->setLoopCount(-1);
    AnimationLine4->start();
    ui->lineBox->hide();
}


void BtForm::setIconAndText(const QString &btIcon, const QString &btText,int pageId)
{
    //设置按钮图标
    ui->btIcon->setPixmap(QPixmap(btIcon));
    //设置按钮文本
    ui->btText->setText(btText);

    //关联page
    this->pageId = pageId;
}

BtForm::~BtForm()
{
    delete ui;
}

int BtForm::getpageId() const
{
    return pageId;
}

void BtForm::clearBackground()
{
    //btStyle
    ui->btStyle->setStyleSheet("#btStyle:hover{background-color:#D8D8D8;}");
    ui->lineBox->hide();
}

void BtForm::showAnimation()
{
    ui->lineBox->show();
}

void BtForm::mousePressEvent(QMouseEvent *event)
{
    //1.当按钮按下后修改背景颜色
    ui->btStyle->setStyleSheet("#btStyle{background-color:rgb(30,206,154);}");
    //2.按钮按下后，切换page
    emit btClick(pageId);
}
