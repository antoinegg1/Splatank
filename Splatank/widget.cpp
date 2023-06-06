#include "widget.h"
#include "ui_widget.h"
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
    MainView=new MyView(this,MainScene);
    //MainView->fitInView(MainScene->sceneRect(), Qt::KeepAspectRatio);
    QObject::connect(&i,SIGNAL(mySignal()),this,SLOT(tostart()));
    QObject::connect(MainView,SIGNAL(escSignal()),this,SLOT(tostart()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()//start
{
    MainScene=new MyScene();
    MainScene->setSceneRect(0,0,800,500);
    MainView->setScene(MainScene);
    MainScene->init_map();
    MainView->show();
    ((timeBoard*)MainScene->TimeBoard)->timer->start(1000);
    hide();
}


void Widget::on_pushButton_2_clicked()//exit
{
    close();
}


void Widget::on_pushButton_3_clicked()//introduce
{
    i.show();
    hide();
}
void Widget::tostart(){
    this->show();
    i.hide();
    MainView->close();
    delete MainScene;
}
//void Widget::toset(){
//    MainView->hide();
//}

