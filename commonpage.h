#ifndef COMMONPAGE_H
#define COMMONPAGE_H

#include <QWidget>
#include"musiclist.h"

namespace Ui {
class CommonPage;
}

enum PageType
{
    LIKE_PAGE,
    LOCAL_PAGE,
    HISTORY_PAGE
};

class CommonPage : public QWidget
{
    Q_OBJECT

public:
    explicit CommonPage(QWidget *parent = nullptr);
    ~CommonPage();

    void setCommonPageUI(const QString& title,const QString& image);

    void setMusicListType(PageType musicListType);

    void addMusicToMusicPage(MusicList &musicList);

    void reFresh(MusicList &musicList);
signals:
    void upDateLikeMusic(bool,const QString&);
private:
    Ui::CommonPage *ui;

    PageType PageType; //保存该页面的类别

    QVector<QString> musicOfPage;//保存musiclisttype对应页面的歌曲id
};

#endif // COMMONPAGE_H
