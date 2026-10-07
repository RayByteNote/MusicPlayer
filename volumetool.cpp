#include "volumetool.h"
#include "ui_volumetool.h"
#include<QGraphicsDropShadowEffect>
#include<QPainter>

VolumeTool::VolumeTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VolumeTool)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    //窗口添加自定义阴影效果
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setColor("#646464");
    shadowEffect->setBlurRadius(10);
    shadowEffect->setOffset(0,0);
    this->setGraphicsEffect(shadowEffect);

    //设置按钮图标
    ui->silenceBtn->setIcon(QIcon(":/images/volumn.png"));

    //设置默认音量
    ui->volumeRatio->setText("20%");

    //设置ouline尺寸
    QRect rect = ui->outLine->geometry();
    ui->outLine->setGeometry(rect.x(),rect.height()+18,rect.width(),36);

    //移动按钮位置
    ui->sliderBtn->move(ui->sliderBtn->x(),ui->outLine->y() - ui->sliderBtn->height()/2);
}

VolumeTool::~VolumeTool()
{
    delete ui;
}

void VolumeTool::paintEvent(QPaintEvent *event)
{
    //绘制volumetool界面下三角
    QPainter painter(this);

    //设置画笔
    painter.setPen(Qt::NoPen);

    //设置画刷
    painter.setBrush(QBrush(Qt::white));

    //绘制三角形
    QPolygon polygon;
    QPoint a(10,300),b(90,300),c(50,320);
    polygon.append(a);
    polygon.append(b);
    polygon.append(c);

    painter.drawPolygon(polygon);
}
