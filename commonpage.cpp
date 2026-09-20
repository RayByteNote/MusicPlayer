#include "commonpage.h"
#include "ui_commonpage.h"
#include"listitembox.h"

CommonPage::CommonPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommonPage)
{
    ui->setupUi(this);
}

CommonPage::~CommonPage()
{
    delete ui;
}

void CommonPage::setCommonPageUI(const QString &title, const QString &image)
{
    //设置标题
    ui->pageTitle->setText(title);

    //设置封面栏
    ui->musicImageLabel->setPixmap(QPixmap(image));

    ui->musicImageLabel->setScaledContents(true);

    //将listitembox放置在pagemusicList中
    listItemBox* listItemBox = new class listItemBox(this);

    QListWidgetItem* item = new QListWidgetItem(ui->pageMusicList);
    item->setSizeHint(QSize(listItemBox->width(),listItemBox->height()));
    ui->pageMusicList->setItemWidget(item,listItemBox);
}
