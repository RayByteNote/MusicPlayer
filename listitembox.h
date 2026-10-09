#ifndef LISTITEMBOX_H
#define LISTITEMBOX_H

#include <QWidget>

class QEnterEvent;

namespace Ui {
class listItemBox;
}

class listItemBox : public QWidget
{
    Q_OBJECT

public:
    explicit listItemBox(QWidget *parent = nullptr);
    ~listItemBox();

    void setMusicName(const QString &musicName);
    void setMusicSinger(const QString &musicSinger);
    void setMusicAlbum(const QString &musicAlbum);

protected:
    void enterEvent(QEnterEvent *event) override;   // Qt6：这里必须是 QEnterEvent*
    void leaveEvent(QEvent *event) override;

private:
    Ui::listItemBox *ui;
};

#endif // LISTITEMBOX_H
