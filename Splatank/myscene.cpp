#include<QDebug>
#include "myscene.h"
#include"QPainter"

MyScene::MyScene():shouldDraw(false),circleX(0),circleY(0)
{
    memset(map,0,sizeof(map));
}

void MyScene::bombAt(int color,qreal X,qreal Y)
{
    for(int i=0;i<800;i++)
        for(int j=0;j<500;j++)
        {
            qreal dis=(i-X)*(i-X)+(j-Y)*(j-Y);
            if(dis<=1500)
                map[i][j]=color;
        }
}

void MyScene::drawBackground(QPainter *painter, const QRectF &rect) {
    // 绘制背景
    if(1)//(shouldDraw)
    {

        for(int i=0;i<800;i++)
            for(int j=0;j<500;j++)
            {
                if(map[i][j]==1)
                {
                    //painter->setBrush(Qt::white);
                    painter->fillRect(QRectF(i,j,1,1),QBrush(Qt::red));
                }
                if(map[i][j]==-1)
                {
                   painter->fillRect(QRectF(i,j,1,1),QBrush(Qt::green));
                }
            }
        //painter->drawEllipse(QRectF(circleX-50, circleY-50, 100, 100));
        shouldDraw=false;

    }
}
