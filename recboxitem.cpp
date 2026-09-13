#include "recboxitem.h"
#include "ui_recboxitem.h"

recBoxItem::recBoxItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::recBoxItem)
{
    ui->setupUi(this);
}

recBoxItem::~recBoxItem()
{
    delete ui;
}
