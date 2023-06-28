#include<QDebug>
#include "myscene.h"
#include<tank.h>
#include<timeboard.h>
#include<tank2.h>
#include"QPainter"
#include<QTime>
#include<QGraphicsRectItem>
#include<QApplication>
#include<QRandomGenerator64>
#include<qtransform.h>
#include <windows.h>
#include<QThread>
#include<QGraphicsTextItem>
#include<config.h>

MyScene::MyScene():shouldDraw(false),circleX(0),circleY(0),count1(0),count2(0)
{
    player1 = new Tank(QPixmap("..\\Splatank\\res\\1.png"),(MyScene*)this);
    player2 = new Tank2(QPixmap("..\\Splatank\\res\\2.png"),(MyScene*)this);
    TimeBoard=new timeBoard(TIME,(MyScene*)this);
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
    changeX=0;
    changeY=0;
    QGraphicsTextItem* winner= nullptr;
}


void MyScene::bombAt(int color,qreal X,qreal Y)
{
    changeX=fmax(0,X-75);
    changeY=fmax(0,Y-75);
    for(int i=changeX;i<fmin(800,changeX+150);i++)
        for(int j=changeY;j<fmin(500,changeY+150);j++)
        {
            qreal dis=(i-X)*(i-X)+(j-Y)*(j-Y);
            if(dis<=5625&&can_be_reached_by_color(X,Y,i,j))
            {
                double f=2000/(dis+1500);
                double tmp = QRandomGenerator::global()->bounded(1.0);
                if(tmp<=f)
                {map[i][j]=color;}
            }
        }
    update(QRectF(X-75,Y-75,150,150));
}

void MyScene::init_map()
{
    memset(map,0,sizeof(map));
    count1=0;
    count2=0;
    for (int x = 0; x < 800; x++) {
        for (int y = 0; y < 500; y++) {
            if (x < 8 || x >= 800 - 8 || y < 8 || y >= 500 - 8) {
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
    for(int i=rect.x();i<rect.x()+rect.width();i+=PAINT_ACCURACY)
    {
        for(int j=rect.y();j<rect.y()+rect.height();j+=PAINT_ACCURACY)
        {
            if(map[i-i%PAINT_ACCURACY][j-j%PAINT_ACCURACY]==1)
                ptr->fillRect(QRectF(i-i%PAINT_ACCURACY,j-j%PAINT_ACCURACY,PAINT_ACCURACY,PAINT_ACCURACY),QBrush(Qt::red));
            if(map[i-i%PAINT_ACCURACY][j-j%PAINT_ACCURACY]==-1)
                ptr->fillRect(QRectF(i-i%PAINT_ACCURACY,j-j%PAINT_ACCURACY,PAINT_ACCURACY,PAINT_ACCURACY),QBrush(Qt::green));
            if(map[i-i%PAINT_ACCURACY][j-j%PAINT_ACCURACY]==2)
                ptr->fillRect(QRectF(i-i%PAINT_ACCURACY,j-j%PAINT_ACCURACY,PAINT_ACCURACY,PAINT_ACCURACY),QBrush(Qt::black));
        }
    }
}

void MyScene::endGame()
{
    removeItem(player1);
    removeItem(player2);
    ((Tank*)player1)->destroyed=true;
    ((Tank2*)player2)->destroyed=true;
    for(int i=0;i<800;i++)
        for(int j=0;j<500;j++)
        {
            QTransform transform;
            if(map[i][j]==1)
                count1++;
            if(map[i][j]==-1)
                count2++;
        }
    if(count1>count2)
        winner=new QGraphicsTextItem("<--");
    else if(count1<count2)
        winner=new QGraphicsTextItem("-->");
    else
        winner=new QGraphicsTextItem("<->");
    QFont font = winner->font();
    font.setPointSize(48);
    winner->setFont(font);
    int col;
    col=(800*count1)/(count1+count2);
    if(count1==count2)
        col=400;
    QTimer::singleShot(1500, [this]() {
        removeItem(TimeBoard);
    });
    QTimer::singleShot(1600, [this,col]() {
        for(int i=0;i<800;i++)
        {
            if(i==399||i==400)
                for(int j=500;j<550;j++)
                    map[i][j]=2;
            else if(i<=col)
                for(int j=500;j<550;j++)
                    map[i][j]=1;
            else
                for(int j=500;j<550;j++)
                    map[i][j]=-1;
        }
    });
    col=fmin(col,800-col)/10;
    QTimer::singleShot(1200,[this,col](){
        ;
        QTimer::singleShot(500, [this,col]() {
            update(0*col,500,col,50);
            QTimer::singleShot(0, [this,col]() {
                update(800-col,500,col,50);
                QTimer::singleShot(500, [this,col]() {
                    update(col,500,col,50);
                    QTimer::singleShot(0, [this,col]() {
                        update(800-2*col,500,col,50);
                        QTimer::singleShot(500, [this,col]() {
                            update(2*col,500,col,50);
                            QTimer::singleShot(0, [this,col]() {
                                update(800-3*col,500,col,50);
                                QTimer::singleShot(500, [this,col]() {
                                    update(3*col,500,col,50);
                                    QTimer::singleShot(0, [this,col]() {
                                        update(800-4*col,500,col,50);
                                        QTimer::singleShot(500, [this,col]() {
                                            update(4*col,500,col,50);
                                            QTimer::singleShot(0, [this,col]() {
                                                update(800-5*col,500,col,50);
                                                QTimer::singleShot(1000, [this]() {
                                                    addWinner();
                                                    update(0,500,800,50);
                                                });
                                            });
                                        });
                                    });
                                });
                            });
                        });
                    });
                });
            });
        });
    });
}

void MyScene::addWinner()
{
    winner->setPos(335,475);
    addItem(winner);
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

    if(((Tank*)player1)->b[0]->shooted==true)
    {
        ((Tank*)player1)->b[0]->moveBy();
    }
    if(((Tank*)player1)->b[1]->shooted==true)
    {
        ((Tank*)player1)->b[1]->moveBy();
    }
    if(((Tank*)player1)->b[2]->shooted==true)
    {
        ((Tank*)player1)->b[2]->moveBy();
    }
    if(((Tank2*)player2)->b[0]->shooted==true)
    {
        ((Tank2*)player2)->b[0]->moveBy();
    }
    if(((Tank2*)player2)->b[1]->shooted==true)
    {
        ((Tank2*)player2)->b[1]->moveBy();
    }
    if(((Tank2*)player2)->b[2]->shooted==true)
    {
        ((Tank2*)player2)->b[2]->moveBy();
    }

}
