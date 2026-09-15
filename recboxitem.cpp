#include "recboxitem.h"
#include "ui_recboxitem.h"
#include <QPropertyAnimation>

recBoxItem::recBoxItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::recBoxItem)
{
    ui->setupUi(this);
    ui->musicImageBox->installEventFilter(this);
}

recBoxItem::~recBoxItem()
{
    delete ui;
}

bool recBoxItem::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->musicImageBox)
    {
        if(event->type() == QEvent::Enter)
        {
            //添加图片上移动画
            QPropertyAnimation *animation = new QPropertyAnimation(ui->musicImageBox,"geometry");
            animation->setDuration(150);
            animation->setStartValue(QRect(10,10,ui->musicImageBox->width(),ui->musicImageBox->height()));
            animation->setEndValue(QRect(10,0,ui->musicImageBox->width(),ui->musicImageBox->height()));
            animation->start();
            connect(animation,&QPropertyAnimation::finished,this,[=](){delete animation;});
            return true;
        }
        else if(event->type() == QEvent::Leave)
        {
            //添加图片下移动画
            QPropertyAnimation *animation = new QPropertyAnimation(ui->musicImageBox,"geometry");
            animation->setDuration(150);
            animation->setStartValue(QRect(10,0,ui->musicImageBox->width(),ui->musicImageBox->height()));
            animation->setEndValue(QRect(10,10,ui->musicImageBox->width(),ui->musicImageBox->height()));
            animation->start();
            connect(animation,&QPropertyAnimation::finished,this,[=](){delete animation;});
            return true;
        }
        return false;
    }

    return QObject::eventFilter(watched,event);
}

void recBoxItem::setRecText(const QString &text)
{
    ui->recBoxItemText->setText(text);
}

void recBoxItem::setRecImage(const QString &imagePath)
{
    QString style = "background-image:url("+imagePath+");";
    ui->recMusicImage->setStyleSheet(style);
}
