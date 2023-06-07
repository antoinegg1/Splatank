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
    MainScene=nullptr;
    MainView=nullptr;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::reshow(){
    if(MainScene!=nullptr&&MainView!=nullptr)
    {
        delete MainScene;
        delete MainView;
    }
    show();
}
void Widget::on_pushButton_clicked()//start
{
    MainScene=new MyScene();
    MainScene->setSceneRect(0,0,800,500);
    MainView=new MyView(this,MainScene);
    MainView->setScene(MainScene);
    MainScene->init_map();
    MainView->show();
    ((timeBoard*)MainScene->TimeBoard)->timer->start(1000);
    QObject::connect(MainScene,SIGNAL(escSignal()),this,SLOT(reshow()));
    hide();
}


void Widget::on_pushButton_2_clicked()//exit
{
    close();
}


void Widget::on_pushButton_3_clicked()//introduce
{
    introduce* i;
    i=new introduce();
    i->show();
    QObject::connect(i,SIGNAL(mySignal()),this,SLOT(reshow()));
    hide();
}


