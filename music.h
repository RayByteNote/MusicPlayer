#ifndef MUSIC_H
#define MUSIC_H

#include<QUrl>
#include<QUuid>
#include<QMediaPlayer>
#include<QObject>

class Music : public QObject
{
    Q_OBJECT
public:
    Music();

    Music(QUrl url);

    void setMusicName(const QString &musicName);
    void setMusicSinger(const QString &musicSinger);
    void setMusicAlbumn(const QString &musicAlbumn);
    void setMusicDuration(qint64 duration);
    void setIsLike(bool isLike);
    void setIsHistory(bool isHistory);
    void setMusicUrl(QUrl musicUrl);

    QString getMusicName() const;
    QString getMusicSinger() const;
    QString getMusicAlbumn() const;
    qint64 getMusicDuration() const;
    bool getIsLike() const;
    bool getIsHistory() const;
    QUrl getMusicUrl() const;
    QString getMusicId() const;

signals:
    void metaDataReady();

private:
    void parseMediaMetaMusic();
private:
    //音乐名称，专辑，歌手，时长，是否喜欢，是否为历史播放，音乐QUrl
    QString musicName;
    QString musicSinger;
    QString musicAlbumn;
    qint64 duration = 0;
    bool isLike;
    bool isHistory;
    QUrl musicUrl;
    //保证歌曲唯一性
    QString musicId;

    QMediaPlayer *player = nullptr;
};

#endif // MUSIC_H
