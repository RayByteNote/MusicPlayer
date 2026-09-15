#ifndef BTFORM_H
#define BTFORM_H

#include <QWidget>
#include<QPropertyAnimation>

namespace Ui {
class BtForm;
}

class BtForm : public QWidget
{
    Q_OBJECT

public:
    explicit BtForm(QWidget *parent = nullptr);
    void setIconAndText(const QString& btIcon,const QString& btText,int pageId);
    ~BtForm();

    int getpageId()const;
    void clearBackground();

    void showAnimation();
signals:
    void btClick(int id);
protected:
    void mousePressEvent(QMouseEvent* event);

private:
    Ui::BtForm *ui;
    int pageId;

    QPropertyAnimation * AnimationLine1;
    QPropertyAnimation * AnimationLine2;
    QPropertyAnimation * AnimationLine3;
    QPropertyAnimation * AnimationLine4;
};

#endif // BTFORM_H
