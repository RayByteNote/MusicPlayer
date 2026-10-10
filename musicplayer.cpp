#include "musicplayer.h"
#include "ui_musicplayer.h"
#include<QJsonObject>
#include<QJsonArray>
#include<QFileDialog>

MusicPlayer::MusicPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicPlayer)
    ,musiclist()
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


    ui->recMusicBox->initRecBoxUi(randomPiction(),1);
    ui->supplyMusicBox->initRecBoxUi(randomPiction(),2);

    ui->likepage->setMusicListType(LIKE_PAGE);
    ui->likepage->setCommonPageUI("我喜欢",":/images/ilikebg.png");
    ui->localpage->setMusicListType(LOCAL_PAGE);
    ui->localpage->setCommonPageUI("本地音乐",":/images/localbg.png");
    ui->recentpage->setMusicListType(HISTORY_PAGE);
    ui->recentpage->setCommonPageUI("最近播放",":/images/recentbg.png");

    volumeTool = new VolumeTool(this);
}

QJsonArray MusicPlayer::randomPiction()
{
    //推荐图片是随机的
    QVector<QString> vecImageName;
    vecImageName<<"001.png"<<"003.png"<<"004.png"<<"005.png"<<"006.png"<<"007.png"<<"008.png"<<"009.png"<<"010.png"<<"011.png"<<"012.png"<<"013.png"<<"014.png"
                <<"015.png"<<"016.png"<<"017.png"<<"018.png"<<"019.png"<<"020.png"<<"021.png"<<"022.png"<<"023.png"<<"024.png"<<"025.png"<<"026.png"<<"027.png"<<"028.png"
                 <<"029.png"<<"030.png"<<"031.png"<<"032.png"<<"033.png"<<"034.png"<<"035.png"<<"036.png"<<"037.png"<<"038.png"<<"039.png"<<"040.png";

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vecImageName.begin(),vecImageName.end(),g);


    QJsonArray objArray;
    for(int i=0;i<vecImageName.size();i++)
    {
        QJsonObject obj;
        obj.insert("path",":/images/rec/"+vecImageName[i]);

        QString strText = QString("推荐-%1").arg(i+1,3,10,QChar('0'));
        obj.insert("text",strText);
        objArray.append(obj);
    }
    return objArray;
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

    //处理收藏
    connect(ui->localpage,&CommonPage::upDateLikeMusic,this,&MusicPlayer::upDateLikeMusicAndPage);
    connect(ui->likepage,&CommonPage::upDateLikeMusic,this,&MusicPlayer::upDateLikeMusicAndPage);
    connect(ui->recentpage,&CommonPage::upDateLikeMusic,this,&MusicPlayer::upDateLikeMusicAndPage);
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
    if(!isDragging) return ;
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPosition().toPoint()-dragposition);
        return ;
    }
}

void MusicPlayer::mousePressEvent(QMouseEvent *event)
{
    if(Qt::LeftButton == event->button())
    {
        isDragging = true;

        dragposition = event->globalPosition().toPoint() - geometry().topLeft();
        event->accept();
    }else event->ignore();
}

void MusicPlayer::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) isDragging = false;
    dragposition = {};
}


void MusicPlayer::on_volume_clicked()
{
    //获取ui->volume控件的left-top坐标，转换为基于屏幕的全局坐标
    QPoint point = ui->volume->mapToGlobal(QPoint(0,0));

    //计算volumeTool需要移动的位置
    QPoint volumeLeftTop = point - QPoint(volumeTool->width()/2,volumeTool->height());

    volumeLeftTop.setX(volumeLeftTop.x()+15);
    volumeLeftTop.setY(volumeLeftTop.y()+30);
    //移动
    volumeTool->move(volumeLeftTop);
    volumeTool->show();
}


void MusicPlayer::on_addlocal_clicked()
{
    QFileDialog fileDialog(this);

    //设置窗口标题
    fileDialog.setWindowTitle("添加本地音乐");
    //设置显示目录
    QDir dir(QDir::currentPath());
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
    QString projectPath = dir.path();
    qDebug()<<projectPath;
    fileDialog.setDirectory(projectPath);
    //设置一次打开多个文件
    fileDialog.setFileMode(QFileDialog::ExistingFiles);

    //通过文件后缀过滤
    //fileDialog.setNameFilter("mp3文件(*.mp3)");

    //通过文件的MIME类型过滤
    QStringList mimetype;
    mimetype << "application/octet-stream";//保证没有文件遗漏,musiclist中有做过滤
    fileDialog.setMimeTypeFilters(mimetype);

    if(QDialog::Accepted == fileDialog.exec())
    {
        //获取选中的文件
        QList<QUrl> fileUrls = fileDialog.selectedUrls();

        //将Url填充到本地下载
        musiclist.addMusicByUrl(fileUrls);


        //将commonpage切换到本地下载页
        ui->stackedWidget->setCurrentIndex(4);

        ui->localpage->reFresh(musiclist);
    }

}

void MusicPlayer::upDateLikeMusicAndPage(bool isLike, const QString &musicId)
{
    //修改状态
    auto it = musiclist.findMusicByMusicId(musicId);
    if(it != musiclist.end())
    {
        auto music = *it;
        music->setIsLike(isLike);
    }

    ui->likepage->reFresh(musiclist);
    ui->recentpage->reFresh(musiclist);
    ui->localpage->reFresh(musiclist);
}

