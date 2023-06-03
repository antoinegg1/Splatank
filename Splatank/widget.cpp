#include "widget.h"
#include "ui_widget.h"
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<tank.h>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget),MainView(&MainScene)
{
    ui->setupUi(this);
    MainScene.setSceneRect(0,0,800,500);
    QPixmap pixmap("..\\Splatank\\res\\1.png");// 创建一个 QPixmap 对象并加载图像文件
    player1 = new Tank(pixmap);
    MainScene.addItem(player1);// 将 QGraphicsPixmapItem 对象添加到场景中
    player1->setPos(100,100);
    player1->setFocus();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::StartGame()
{
    MainView.show();// 显示 QGraphicsView 窗口
}


