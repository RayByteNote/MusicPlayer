#include "listitembox.h"
#include "ui_listitembox.h"

#include <QEnterEvent>

listItemBox::listItemBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::listItemBox)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground, true);   // 保证背景由样式表绘制
}

listItemBox::~listItemBox()
{
    delete ui;
}

void listItemBox::enterEvent(QEnterEvent *event)
{
    (void)event;
    setStyleSheet("background-color:#EFEFEF");
}

void listItemBox::leaveEvent(QEvent *event)
{
    (void)event;
    setStyleSheet("");
}
