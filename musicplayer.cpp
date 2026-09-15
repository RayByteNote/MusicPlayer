#include "musicplayer.h"
#include "ui_musicplayer.h"

MusicPlayer::MusicPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);
    initui();

    connectSignalAndSlots();
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

    //设置btForm图标 & 文本信息
    ui->Rec->setIconAndText(":/images/rec.png","推荐",0);
    ui->radio->setIconAndText(":/images/radio.png","电台",1);
    ui->music->setIconAndText(":/images/music.png","音乐馆",2);
    ui->like->setIconAndText(":/images/like.png","我喜欢",3);
    ui->local->setIconAndText(":/images/local.png","本地下载",4);
    ui->recent->setIconAndText(":/images/recent.png","最近播放",5);

    ui->local->showAnimation();
    ui->stackedWidget->setCurrentIndex(4);

    randomPiction();
}

void MusicPlayer::randomPiction()
{
    //推荐图片是随机的
    QVector<QString> vecImageName;
    vecImageName<<"001.png"<<"002.png"<<"003.png"<<"004.png"<<"005.png"<<"006.png"<<"007.png"<<"008.png"<<"009.png"<<"010.png"<<"011.png"<<"012.png"<<"013.png"<<"014.png"
                <<"015.png"<<"016.png"<<"017.png"<<"018.png"<<"019.png"<<"020.png"<<"021.png"<<"022.png"<<"023.png"<<"024.png"<<"025.png"<<"026.png"<<"027.png"<<"028.png"
                 <<"029.png"<<"030.png"<<"031.png"<<"032.png"<<"033.png"<<"034.png"<<"035.png"<<"036.png"<<"037.png"<<"038.png"<<"039.png"<<"040.png";

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vecImageName.begin(),vecImageName.end(),g);

}

void MusicPlayer::connectSignalAndSlots()
{
    //关联BtForm信号及处理的槽函数
    connect(ui->Rec,&BtForm::btClick,this,&MusicPlayer::onBtFormClick);
    connect(ui->radio,&BtForm::btClick,this,&MusicPlayer::onBtFormClick);
    connect(ui->music,&BtForm::btClick,this,&MusicPlayer::onBtFormClick);
    connect(ui->like,&BtForm::btClick,this,&MusicPlayer::onBtFormClick);
    connect(ui->local,&BtForm::btClick,this,&MusicPlayer::onBtFormClick);
    connect(ui->recent,&BtForm::btClick,this,&MusicPlayer::onBtFormClick);
}

void MusicPlayer::on_quit_clicked()
{
    close();
}

void MusicPlayer::onBtFormClick(int pageId)
{
    //清除之前按钮的颜色
    //获取所有的按钮
    QList<BtForm*> btFormList = this->findChildren<BtForm*>();
    for(auto btForm : btFormList)
    {
        if(btForm->getpageId() != pageId)
        {
            btForm->clearBackground();
        }
    }

    ui->stackedWidget->setCurrentIndex(pageId);
    if(pageId==0)ui->Rec->showAnimation();
    if(pageId==1)ui->radio->showAnimation();
    if(pageId==2)ui->music->showAnimation();
    if(pageId==3)ui->like->showAnimation();
    if(pageId==4)ui->local->showAnimation();
    if(pageId==5)ui->recent->showAnimation();
}

void MusicPlayer::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        move(event->globalPosition().toPoint()-dragposition);
        qDebug()<<"mouse move";
        return ;
    }
    QWidget::mouseMoveEvent(event);
}

void MusicPlayer::mousePressEvent(QMouseEvent *event)
{
    if(Qt::LeftButton == event->button())
    {
        dragposition = event->globalPosition().toPoint() - geometry().topLeft();
        return ;
    }
    QWidget::mousePressEvent(event);
}

