#include<QDebug>
#include <QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<myscene.h>
#include <QTimer>
#include<bullet.h>
#include<tank.h>
#include<tank2.h>
#include<config.h>


Bullet::Bullet(MyScene* scene,QGraphicsPixmapItem* tank,int Color) : QGraphicsPixmapItem(QPixmap("..\\Splatank\\res\\bullet.png")),color(Color)
{
    parent=scene;
    speed = BULLET_SPEED;
    dx = 0;
    dy = 0;
    startX=0;
    startY=0;
    parentTank=tank;
    shooted=false;
}

Bullet::~Bullet()
{

}

void Bullet::shoot(qreal X,qreal Y,qreal angle) {
    shooted=true;
    setPos(X,Y);
    startX=X;
    startY=Y;
    bomb=false;
    parent->addItem(this);
    dx = qCos(angle) * speed;
    dy = qSin(angle) * speed;
}

void Bullet:: moveBy()
{
    setPos(x() + dx, y() + dy);
    qreal dis=(x()-startX)*(x()-startX)+(y()-startY)*(y()-startY);
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    if (!collidingItems.isEmpty()||dis>=40000) {
        // item与其他图形项发生了碰撞
        if(!bomb)
        {
            bomb=true;
            parent->bombAt(color,x()+5,y()+4,5625);
            parent->removeItem(this);
            if(color==1)
                ((Tank*)parentTank)->bulletNum++;
            if(color==-1)
                ((Tank2*)parentTank)->bulletNum++;
            /*for (QGraphicsItem *item : collidingItems)
                {
                    if (item->type() == Tank::Type)
                        ((Tank*)item)->destroy();
                    if (item->type() == Tank2::Type)
                        ((Tank2*)item)->destroy();
                }*/
            shooted=false;
        }
    }
}
