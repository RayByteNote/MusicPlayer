#include "commonpage.h"
#include "ui_commonpage.h"
#include"listitembox.h"

CommonPage::CommonPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommonPage)
{
    ui->setupUi(this);
    ui->pageMusicList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

CommonPage::~CommonPage()
{
    delete ui;
}

void CommonPage::setCommonPageUI(const QString &title, const QString &image)
{
    //设置标题
    ui->pageTitle->setText(title);

    //设置封面栏
    ui->musicImageLabel->setPixmap(QPixmap(image));

    ui->musicImageLabel->setScaledContents(true);

}

void CommonPage::setMusicListType(enum PageType PageType)
{
    this->PageType = PageType;
}

void CommonPage::addMusicToMusicPage(MusicList &musicList)
{
    musicOfPage.clear();
    for(auto& music : musicList)
    {
        switch(PageType)
        {
        case LIKE_PAGE:
            if(music->getIsLike())
            {
                musicOfPage.push_back(music->getMusicId());
            }
            break;
        case LOCAL_PAGE:
                musicOfPage.push_back(music->getMusicId());
            break;
        case HISTORY_PAGE:
            if(music->getIsHistory())
            {
                musicOfPage.push_back(music->getMusicId());
            }
            break;
        default:
            qDebug()<<"不支持";
        }
    }
}

//将歌曲信息更新到界面
void CommonPage::reFresh(MusicList &musicList)
{
    ui->pageMusicList->clear();
    addMusicToMusicPage(musicList);

    for(auto &musicId : musicOfPage)
    {
        auto it = musicList.findMusicByMusicId(musicId);
        if(it ==musicList.end())
            continue;


        auto *row = new listItemBox(this);
        Music *music = (*it).data();
        //设置歌曲名称
        auto updateText = [music, row]()
        {
            row->setMusicName(music->getMusicName());
            row->setMusicSinger(music->getMusicSinger());
            row->setMusicAlbum(music->getMusicAlbumn());
            row->setLikeMusic(music->getIsLike());
        };
        connect(music, &Music::metaDataReady, row, updateText);
        updateText();

        QListWidgetItem* item = new QListWidgetItem(ui->pageMusicList);
        item->setSizeHint(QSize(row->width(),row->height()));
        ui->pageMusicList->setItemWidget(item,row);

        connect(row,&listItemBox::setIslike,this,[=](bool isLike){
            emit upDateLikeMusic(isLike,music->getMusicId());
        });
    }
    repaint();
}
