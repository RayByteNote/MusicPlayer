#include "listitembox.h"
#include "ui_listitembox.h"

#include <QEnterEvent>

listItemBox::listItemBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::listItemBox)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground, true);   // 保证背景由样式表绘制
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
