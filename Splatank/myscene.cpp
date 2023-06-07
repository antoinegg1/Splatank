#include<QDebug>
#include "myscene.h"
#include<tank.h>
#include<timeboard.h>
#include<tank2.h>
#include"QPainter"
#include<QTime>
#include<QGraphicsRectItem>
#include<QRandomGenerator64>

MyScene::MyScene():shouldDraw(false),circleX(0),circleY(0),count1(0),count2(0)
{
    player1 = new Tank(QPixmap("..\\Splatank\\res\\1.png"),(MyScene*)this);
    player2 = new Tank2(QPixmap("..\\Splatank\\res\\2.png"),(MyScene*)this);
    TimeBoard=new timeBoard(30,(MyScene*)this);
    addItem(TimeBoard);
    addItem(player1);
    addItem(player2);
    aKeyPressed=false;
    dKeyPressed=false;
    wKeyPressed=false;
    sKeyPressed=false;
    qKeyPressed=false;
    leftKeyPressed=false;
    rightKeyPressed=false;
    upKeyPressed=false;
    downKeyPressed=false;
    mKeyPressed=false;
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MyScene::myUpdate);
    timer->start(10); 
}


void MyScene::bombAt(int color,qreal X,qreal Y)
{
    for(int i=0;i<800;i++)
        for(int j=0;j<500;j++)
        {
            qreal dis=(i-X)*(i-X)+(j-Y)*(j-Y);
            if(dis<=1500&&can_be_reached_by_color(X,Y,i,j))
            {
                double f=2000/(dis+1500);
                double tmp = QRandomGenerator::global()->bounded(1.0);
                if(tmp<=f)
                    map[i][j]=color;
            }
        }
    update(QRectF(X-39,Y-39,78,78));
}

void MyScene::init_map()
{
    memset(map,0,sizeof(map));
    count1=0;
    count2=0;
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

void MyScene::drawBackground(QPainter* ptr, const QRectF &rect)
{
    // 绘制背景
    for(int i=0;i<800;i++)
    {
        for(int j=0;j<500;j++)
        {
            if(map[i][j]==1)
                ptr->fillRect(QRectF(i,j,1,1),QBrush(Qt::red));
            if(map[i][j]==-1)
                ptr->fillRect(QRectF(i,j,1,1),QBrush(Qt::green));
        }
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

void MyScene::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A)
        aKeyPressed=true;
    if(event->key()==Qt::Key_D)
        dKeyPressed=true;
    if(event->key()==Qt::Key_W)
        wKeyPressed=true;
    if(event->key()==Qt::Key_S)
        sKeyPressed=true;
    if(event->key()==Qt::Key_Q)
        qKeyPressed=true;
    if(event->key()==Qt::Key_Left)
        leftKeyPressed=true;
    if(event->key()==Qt::Key_Right)
        rightKeyPressed=true;
    if(event->key()==Qt::Key_Up)
        upKeyPressed=true;
    if(event->key()==Qt::Key_Down)
        downKeyPressed=true;
    if(event->key()==Qt::Key_M)
        mKeyPressed=true;
    if(event->key()==Qt::Key_Escape){
        emit escSignal();
    }
}

void MyScene::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A)
        aKeyPressed=false;
    if(event->key()==Qt::Key_D)
        dKeyPressed=false;
    if(event->key()==Qt::Key_W)
        wKeyPressed=false;
    if(event->key()==Qt::Key_S)
        sKeyPressed=false;
    if(event->key()==Qt::Key_Q)
        qKeyPressed=false;
    if(event->key()==Qt::Key_Left)
        leftKeyPressed=false;
    if(event->key()==Qt::Key_Right)
        rightKeyPressed=false;
    if(event->key()==Qt::Key_Up)
        upKeyPressed=false;
    if(event->key()==Qt::Key_Down)
        downKeyPressed=false;
    if(event->key()==Qt::Key_M)
        mKeyPressed=false;

}

void MyScene::myUpdate()
{
    if(aKeyPressed)
        ((Tank*)player1)->turnLeft();
    if(dKeyPressed)
        ((Tank*)player1)->turnRight();
    if(wKeyPressed)
        ((Tank*)player1)->goForward();
    if(sKeyPressed)
        ((Tank*)player1)->goBack();
    if(qKeyPressed)
        ((Tank*)player1)->shoot();

    if(leftKeyPressed)
        ((Tank2*)player2)->turnLeft();
    if(rightKeyPressed)
        ((Tank2*)player2)->turnRight();
    if(upKeyPressed)
        ((Tank2*)player2)->goForward();
    if(downKeyPressed)
        ((Tank2*)player2)->goBack();
    if(mKeyPressed)
        ((Tank2*)player2)->shoot();

    if(((Tank*)player1)->haveBullet==false)
    {
        ((Tank*)player1)->b1->moveBy();
    }
    if(((Tank2*)player2)->haveBullet==false)
    {
        ((Tank2*)player2)->b1->moveBy();
    }

}
