#include<QDebug>
#include "myscene.h"
#include"QPainter"
#include<QGraphicsRectItem>

MyScene::MyScene():shouldDraw(false),circleX(0),circleY(0),count1(0),count2(0)
{
    memset(map,0,sizeof(map));
}

void MyScene::bombAt(int color,qreal X,qreal Y)
{
    for(int i=0;i<800;i++)
        for(int j=0;j<500;j++)
        {
            qreal dis=(i-X)*(i-X)+(j-Y)*(j-Y);
            if(dis<=1500&&can_be_reached_by_color(X,Y,i,j))
                map[i][j]=color;
        }
}

void MyScene::init_map()
{
    for (int x = 0; x < 800; x++) {
        for (int y = 0; y < 500; y++) {
            if (x < 15 || x >= 800 - 15 || y < 15 || y >= 500 - 15) {
                map[x][y] = 10; // 将边界墙标记为障碍物
            }
        }
    }
    for(int x=200;x<230;x++)
    {
        for(int y=225;y<275;y++)
            map[x][y]=10;
    }
    for(int x=570;x<600;x++)
    {
        for(int y=225;y<275;y++)
            map[x][y]=10;
    }

    for(int x= 0;x<800;x++)
    {
        for(int y=0;y<500;y++)
        {
            if(map[x][y]==10)
            {
                QGraphicsRectItem * obstacle = new QGraphicsRectItem(x,y,1,1);
                obstacle->setBrush(Qt::black);
                addItem(obstacle);
            }
        }
    }
}

bool MyScene::can_be_reached_by_color(int sx,int sy,int ex,int ey)
{
    int dx = ex - sx;
    int dy = ey - sy;

    double slope = static_cast<double>(dy)/dx;

    // 根据斜率的绝对值来确定水平或垂直方向的移动步长
    int stepX = (dx > 0) ? 1 : -1;
    int stepY = (dy > 0) ? 1 : -1;

    // 根据斜率的绝对值来确定主要移动方向
    bool isMajorAxisX = (fabs(slope) <= 1);

    // 初始化当前点的坐标
    double currentX = sx;
    double currentY = sy;

    // 在主要移动方向上进行遍历
    if (isMajorAxisX) {
        while (abs(currentX-ex)>1e-6) {
            currentX += stepX;
            currentY += slope*stepX;

            // 检查当前点是否为障碍物
            if (map[int(currentX)][int(currentY)] == 10) {
                return false;
            }
        }
    } else {
        while (abs(currentY-ey)>1e-6) {
            currentY += stepY;
            currentX += (stepY / slope);

            // 检查当前点是否为障碍物
            if (map[(int)currentX][(int)currentY] == 10) {
                return false;
            }
        }
    }

    // 没有找到障碍物，返回true
    return true;
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

void MyScene::endGame()
{
    for(int i=0;i<800;i++)
        for(int j=0;j<500;j++)
        {
            if(map[i][j]==1)
                count1++;
            if(map[i][j]==-1)
                count2++;
        }
    if(count1>count2)
        qDebug()<<"1win";
    else if(count2>count1)
        qDebug()<<"2win";
    else
        qDebug()<<"noWin";

}
