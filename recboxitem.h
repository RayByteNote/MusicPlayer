#ifndef RECBOXITEM_H
#define RECBOXITEM_H

#include <QWidget>
#include<QObject>

namespace Ui {
class recBoxItem;
}

class recBoxItem : public QWidget
{
    Q_OBJECT

public:
    explicit recBoxItem(QWidget *parent = nullptr);
    ~recBoxItem();
    bool eventFilter(QObject *watched,QEvent *event);
    //设置推荐文本
    void setRecText(const QString& text);

    //设置图片
    void setRecImage(const QString& imagePath);




private:
    Ui::recBoxItem *ui;
};

#endif // RECBOXITEM_H
