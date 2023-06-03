#include<QDebug>
#include "myscene.h"
#include"QPainter"

MyScene::MyScene():shouldDraw(false),circleX(0),circleY(0)
{

}

void MyScene::drawBackground(QPainter *painter, const QRectF &rect) {
    // 绘制背景
    if(shouldDraw)
    {
        painter->setBrush(Qt::black);
        painter->drawEllipse(QRectF(circleX-50, circleY-50, 100, 100));
        shouldDraw=false;

    }
}
