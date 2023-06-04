#include<QDebug>
#include <QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<myscene.h>
#include <QTimer>
#include<bullet.h>
#include<tank.h>
#include<tank2.h>


Bullet::Bullet(MyScene* scene,QGraphicsPixmapItem* tank,int Color) : QGraphicsPixmapItem(QPixmap("..\\Splatank\\res\\bullet.png")),color(Color)
{
    parent=scene;
    speed = 5;
    dx = 0;
    dy = 0;
    startX=0;
    startY=0;
    parentTank=tank;
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::moveBy);
    timer->start(10);
}

Bullet::~Bullet()
{

}

void Bullet::shoot(qreal X,qreal Y,qreal angle) {
        setPos(X,Y);
        startX=X;
        startY=Y;
        bomb=false;
        parent->addItem(this);
        dx = qCos(angle) * speed;
        dy = qSin(angle) * speed;
    }

void Bullet:: moveBy() {
        setPos(x() + dx, y() + dy);
        qreal dis=(x()-startX)*(x()-startX)+(y()-startY)*(y()-startY);
        QList<QGraphicsItem *> collidingItems = this->collidingItems();
        if (!collidingItems.isEmpty()||dis>=40000) {
            // item与其他图形项发生了碰撞
            if(!bomb)
            {
                bomb=true;
                parent->shouldDraw=true;
                parent->bombAt(color,x()+5,y()+4);
                parent->removeItem(this);
                parent->update();
                if(color==1)
                    ((Tank*)parentTank)->haveBullet=true;
                else if(color==-1)
                    ((Tank2*)parentTank)->haveBullet=true;
                for (QGraphicsItem *item : collidingItems)
                {
                    if (item->type() == Tank::Type)
                        ((Tank*)item)->destroy();
                    if (item->type() == Tank2::Type)
                        ((Tank2*)item)->destroy();

                }
            }
        }
    }
