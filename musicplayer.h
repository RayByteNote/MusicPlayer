#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QWidget>
#include<QPushButton>
#include<QMouseEvent>
#include<QGraphicsDropShadowEffect>
#include<random>
#include"volumetool.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MusicPlayer;
}
QT_END_NAMESPACE

class MusicPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MusicPlayer(QWidget *parent = nullptr);
    ~MusicPlayer() override;

    void initui();

    QJsonArray randomPiction();

    void connectSignalAndSlots();
private slots:
    void on_quit_clicked();
    void onBtFormClick(int pageId);

    void on_volume_clicked();

    void on_addlocal_clicked();

protected:
    void mouseMoveEvent(QMouseEvent *event)override;
    void mousePressEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;
private:
    Ui::MusicPlayer *ui;

    bool isDragging = false;

    QPoint dragposition;

    VolumeTool* volumeTool;
};
#endif // MUSICPLAYER_H
