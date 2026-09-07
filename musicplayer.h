#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QWidget>
#include<QPushButton>
#include<QMouseEvent>
#include<QGraphicsDropShadowEffect>

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
private slots:
    void on_quit_clicked();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    Ui::MusicPlayer *ui;

    QPoint dragposition;
};
#endif // MUSICPLAYER_H
