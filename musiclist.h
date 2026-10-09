#ifndef MUSICLIST_H
#define MUSICLIST_H

#include<QVector>
#include"music.h"
#include<QList>
#include<QUrl>
#include<QSharedPointer>

typedef QVector<QSharedPointer<Music>>::iterator iterator;

class MusicList
{
public:
    MusicList();

    void addMusicByUrl(const QList<QUrl> &musicUrls);
    iterator findMusicByMusicId(const QString& musicId);

    iterator begin();
    iterator end();
private:
    QVector<QSharedPointer<Music>> musicList;
};

#endif // MUSICLIST_H
