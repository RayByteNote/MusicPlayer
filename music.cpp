#include "music.h"
#include<QMediaPlayer>
#include<QMediaMetaData>
#include<QCoreApplication>
#include<QAudioOutput>

Music::Music()
    :isLike(false)
    ,isHistory(false)
{}

Music::Music(QUrl url)
    :isLike(false)
    ,isHistory(false)
    ,musicUrl(url)
{
    musicId = QUuid::createUuid().toString();
    parseMediaMetaMusic();
}

void Music::setMusicName(const QString &musicName)
{
    this->musicName=musicName;
}

void Music::setMusicSinger(const QString &musicSinger)
{
    this->musicSinger=musicSinger;
}

void Music::setMusicAlbumn(const QString &musicAlbumn)
{
    this->musicAlbumn=musicAlbumn;
}

void Music::setMusicDuration(qint64 duration)
{
    this->duration=duration;
}

void Music::setIsLike(bool isLike)
{
    this->isLike=isLike;
}

void Music::setIsHistory(bool isHistory)
{
    this->isHistory=isHistory;
}

void Music::setMusicUrl(QUrl musicUrl)
{
    this->musicUrl=musicUrl;
}

QString Music::getMusicName() const
{
    return this->musicName;
}

QString Music::getMusicSinger() const
{
    return this->musicSinger;
}

QString Music::getMusicAlbumn() const
{
    return this->musicAlbumn;
}

qint64 Music::getMusicDuration() const
{
    return this->duration;
}

bool Music::getIsLike() const
{
    return this->isLike;
}

bool Music::getIsHistory() const
{
    return this->isHistory;
}

QUrl Music::getMusicUrl() const
{
    return this->musicUrl;
}

QString Music::getMusicId() const
{
    return this->musicId;
}

void Music::parseMediaMetaMusic()
{
    //创建媒体播放对象
    player = new QMediaPlayer(this);

    connect(player,&QMediaPlayer::mediaStatusChanged,this,[this](QMediaPlayer::MediaStatus status){
        if(status == QMediaPlayer::LoadedMedia || status == QMediaPlayer::BufferedMedia)
        {
            musicName = player->metaData().value(QMediaMetaData::Title).toString();
            musicAlbumn = player->metaData().value(QMediaMetaData::AlbumTitle).toString();
            musicSinger = player->metaData().value(QMediaMetaData::Author).toString();
            duration = player->metaData().value(QMediaMetaData::Duration).toLongLong();

            QString filename = musicUrl.fileName();
            int index = filename.indexOf('-');
            //metadata为空的处理
            if(musicName.isEmpty())
            {
                if(index!=-1)
                {
                    musicName = filename.mid(0,index).trimmed();
                }
                else
                {
                    musicName = filename.mid(0,filename.indexOf('.')).trimmed();
                }
            }
            if(musicSinger.isEmpty())
            {
                if(index!=-1)
                {
                    musicSinger = filename.mid(index+1,filename.indexOf('.')-index-1).trimmed();
                }
                else
                {
                    musicSinger = "未知歌手";
                }
            }
            if(musicAlbumn.isEmpty())
            {
                musicAlbumn = "未知专辑";
            }

            emit metaDataReady();
        }
        else if(status == QMediaPlayer::InvalidMedia)
        {
            qDebug()<<"媒体加载失败";
        }
    });

    player->setSource(musicUrl);
}
