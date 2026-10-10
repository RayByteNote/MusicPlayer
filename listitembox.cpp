#include "listitembox.h"
#include "ui_listitembox.h"

#include <QEnterEvent>

listItemBox::listItemBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::listItemBox)
    ,isLike(false)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground, true);   // 保证背景由样式表绘制

    connect(ui->likebtn,&QPushButton::clicked,this,&listItemBox::onLikeBtnClicked);
}

listItemBox::~listItemBox()
{
    delete ui;
}

void listItemBox::enterEvent(QEnterEvent *event)
{
    (void)event;
    setStyleSheet("background-color:#EFEFEF");
}

void listItemBox::leaveEvent(QEvent *event)
{
    (void)event;
    setStyleSheet("");
}

void listItemBox::setMusicName(const QString &musicName)
{
    ui->musicNameLabel->setText(musicName);
    ui->musicNameLabel->setStyleSheet("color:black;");
}

void listItemBox::setMusicSinger(const QString &musicSinger)
{
    ui->musicSingerLabel->setText(musicSinger);
    ui->musicSingerLabel->setStyleSheet("color:black;");
}

void listItemBox::setMusicAlbum(const QString &musicAlbum)
{
    ui->musicAlbumLabel->setText(musicAlbum);
    ui->musicAlbumLabel->setStyleSheet("color:black;");
}

void listItemBox::setLikeMusic(bool isLike)
{
    this->isLike=isLike;
    if(isLike)
    {
        ui->likebtn->setIcon(QIcon(":/images/like_2.png"));
    }
    else
    {
        ui->likebtn->setIcon(QIcon(":/images/like_3.png"));
    }
}

void listItemBox::onLikeBtnClicked()
{
    this->isLike = !isLike;
    setLikeMusic(isLike);
    emit setIslike(isLike);
}
