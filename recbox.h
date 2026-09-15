#ifndef RECBOX_H
#define RECBOX_H

#include <QWidget>
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonValue>

namespace Ui {
class recBox;
}

class recBox : public QWidget
{
    Q_OBJECT

public:
    explicit recBox(QWidget *parent = nullptr);
    ~recBox();


    //初始化recboxitem
    void initRecBoxUi(QJsonArray data,int row);

private slots:
    void on_btDown_clicked();

    void on_btUp_clicked();

private:
    void createRecBoxItem();
private:
    Ui::recBox *ui;

    int row;
    int col;

    QJsonArray imageList;
};

#endif // RECBOX_H
