#include "widget.h"
#include "ui_widget.h"
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<myview.h>
#include<myscene.h>
#include<timeboard.h>
#include<tank.h>
#include<tank2.h>
#include<bullet.h>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    MainScene=new MyScene();
    MainScene->setSceneRect(0,0,800,500);
    player1 = new Tank(QPixmap("..\\Splatank\\res\\1.png"),MainScene);
    player2 = new Tank2(QPixmap("..\\Splatank\\res\\2.png"),MainScene);
    MainView=new MyView(this,MainScene);
    //MainView->fitInView(MainScene->sceneRect(), Qt::KeepAspectRatio);

}

Widget::~Widget()
{
    delete ui;
}

//void Widget::StartGame()
//{
//    MainView->show();// 显示 QGraphicsView 窗口
//}

/*void Widget::keyPressEvent(QKeyEvent *event){

    if(event->key()==Qt::Key_Q){
        player1->b1.shoot(x(),y(),player1->rotation() * M_PI / 180);
    }
    if (event->key() == Qt::Key_A) {
        aKeyPressed = true;
        if (!dKeyPressed) {
            player1->setTransformOriginPoint(player1->boundingRect().center());
            player1->setRotation(player1->rotation() - 7);

            if(wKeyPressed)
            {
                if(!sKeyPressed)
                {
                    qreal angle = player1->rotation() * M_PI / 180;
                    player1->setPos(x() + 10*qCos(angle), y() + 10*qSin(angle));
                }
            }
            if(sKeyPressed)
            {
                if(!wKeyPressed)
                {
                    qreal angle = player1->rotation() * M_PI / 180;
                    player1->setPos(x() - 10*qCos(angle), y() - 10*qSin(angle));
                }
            }
        }
    }

    else if (event->key() == Qt::Key_D) {
        dKeyPressed = true;
        if (!aKeyPressed) {
            player1->setTransformOriginPoint(player1->boundingRect().center());
            player1->setRotation(player1->rotation() + 7);

            if(wKeyPressed)
            {
                if(!sKeyPressed)
                {
                    qreal angle = player1->rotation() * M_PI / 180;
                    player1->setPos(x() + 10*qCos(angle), y() + 10*qSin(angle));
                }
            }
            if(sKeyPressed)
            {
                if(!wKeyPressed)
                {
                    qreal angle = player1->rotation() * M_PI / 180;
                    player1->setPos(x() - 10*qCos(angle), y() - 10*qSin(angle));
                }
            }
        }
    }

    else if (event->key() == Qt::Key_W) {
        wKeyPressed = true;
        if (!sKeyPressed) {
            qDebug()<<1;
            qreal angle = player1->rotation() * M_PI / 180;
            player1->setPos(x() + 10*qCos(angle), y() + 10*qSin(angle));

            if(aKeyPressed){
                if (!dKeyPressed) {
                    player1->setTransformOriginPoint(player1->boundingRect().center());
                    player1->setRotation(player1->rotation() - 7);
                }
            }
            if(dKeyPressed){
                if (!aKeyPressed) {
                    player1->setTransformOriginPoint(player1->boundingRect().center());
                    player1->setRotation(player1->rotation() + 7);
                }
            }
        }
    }

    else if (event->key() == Qt::Key_S) {
        sKeyPressed = true;
        if (!wKeyPressed) {
            qreal angle = player1->rotation() * M_PI / 180;
            player1->setPos(x() - 10*qCos(angle), y() - 10*qSin(angle));

            if(aKeyPressed){
                if (!dKeyPressed) {
                    player1->setTransformOriginPoint(player1->boundingRect().center());
                    player1->setRotation(player1->rotation() - 7);
                }
            }
            if(dKeyPressed){
                if (!aKeyPressed) {
                    player1->setTransformOriginPoint(player1->boundingRect().center());
                    player1->setRotation(player1->rotation() + 7);
                }
            }
        }
    }
}
*/


void Widget::on_pushButton_clicked()
{
    timeBoard* TimeBoard=new timeBoard(180);
    MainScene->addItem(TimeBoard);
    MainView->show();
    close();
}


void Widget::on_pushButton_2_clicked()
{
    close();
}

