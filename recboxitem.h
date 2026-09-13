#ifndef RECBOXITEM_H
#define RECBOXITEM_H

#include <QWidget>

namespace Ui {
class recBoxItem;
}

class recBoxItem : public QWidget
{
    Q_OBJECT

public:
    explicit recBoxItem(QWidget *parent = nullptr);
    ~recBoxItem();

private:
    Ui::recBoxItem *ui;
};

#endif // RECBOXITEM_H
