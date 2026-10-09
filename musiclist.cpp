#include "musiclist.h"
#include<QMimeDatabase>

MusicList::MusicList()
{

}

void MusicList::addMusicByUrl(const QList<QUrl> &musicUrls)
{
    //将所有音乐放置到musiclist
    for(auto e : musicUrls)
    {
        //检测歌曲MIME类型
        QMimeDatabase mimeDB;
        QMimeType mimeType = mimeDB.mimeTypeForFile(e.toLocalFile());
        QString mime = mimeType.name();

        if(mime == "audio/mpeg" || mime == "audio/flac" || mime == "audio/wav")
        {
            //将url创建为music
            auto music = QSharedPointer<Music>::create(e);
            musicList.push_back(music);
        }
    }
}

iterator MusicList::findMusicByMusicId(const QString &musicId)
{
    for(auto music = musicList.begin();music != musicList.end();++music)
    {
        if((*music)->getMusicId() == musicId)
        {
            return music;
        }
    }

    return end();
}

iterator MusicList::begin()
{
    return musicList.begin();
}

iterator MusicList::end()
{
    return musicList.end();
}
