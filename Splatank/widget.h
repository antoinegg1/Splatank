#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<myscene.h>
#include<tank.h>
#include<tank2.h>
#include "introduce.h"
#include<QGraphicsScene>
#include<QGraphicsItem>
#include <QObject>

#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void StartGame();

public slots:
    void reshow();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    MyScene* MainScene;
    QGraphicsView* MainView;
};
#endif // WIDGET_H
