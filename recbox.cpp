#include "recbox.h"
#include "ui_recbox.h"
#include"recboxitem.h"

recBox::recBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::recBox)
{
    ui->setupUi(this);

    recBoxItem* item = new recBoxItem();
    ui->recListUpLayout->addWidget(item);
}

recBox::~recBox()
{
    delete ui;
}
