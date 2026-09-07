#include "musicplayer.h"
#include "ui_musicplayer.h"

MusicPlayer::MusicPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);
    initui();
}

MusicPlayer::~MusicPlayer()
{
    delete ui;
}

void MusicPlayer::initui()
{
    this->setWindowFlag(Qt::FramelessWindowHint);

    //给窗口设计透明背景
    setAttribute(Qt::WA_TranslucentBackground);
    //给窗口设置阴影效果
    QGraphicsDropShadowEffect* shadoweffect = new QGraphicsDropShadowEffect(this);
    shadoweffect->setOffset(0,0);
    shadoweffect->setColor(Qt::black);
    shadoweffect->setBlurRadius(20);
    this->setGraphicsEffect(shadoweffect);
}

void MusicPlayer::on_quit_clicked()
{
    close();
}

void MusicPlayer::mouseMoveEvent(QMouseEvent *event)
{
    if(Qt::LeftButton == event->buttons())
    {
        move(event->globalPos()-dragposition);
    }
}

void MusicPlayer::mousePressEvent(QMouseEvent *event)
{
    if(Qt::LeftButton == event->button())
    {
        dragposition = event->globalPos() - geometry().topLeft();
    }
}

