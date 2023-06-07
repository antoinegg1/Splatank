#include<QDebug>
#include "tank.h"
#include<tank2.h>
#include<bullet.h>
#include<QKeyEvent>
#include<myscene.h>
#include<QGraphicsScene>

Tank::Tank(const QPixmap &pixmap,MyScene *scene):QGraphicsPixmapItem(pixmap)
{
    b1=new Bullet(scene,this,1);
    haveBullet=true;
    parent=scene;
    setPos(54,227);
}

void Tank::destroy()
{
    parent->removeItem(this);
    QTimer::singleShot(3000, [this]() {
        setPos(54,227);
        setRotation(0);
        /*QList<QGraphicsItem *> collidingItems = this->collidingItems();
        for (QGraphicsItem *item : collidingItems)
        {
            if (item->type() == Tank2::Type)
                ((Tank2*)item)->destroy();
        }*/
        parent->addItem(this);
    });
}

bool Tank::collision()
{
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    if (!collidingItems.isEmpty())
        return true;
    return false;
}

void Tank::turnLeft()
{
    setTransformOriginPoint(boundingRect().center());
    setRotation(rotation() - 3);
    if(collision())
        turnRight();
}
void Tank::turnRight()
{
    setTransformOriginPoint(boundingRect().center());
    setRotation(rotation() + 3);
    if(collision())
        turnLeft();
}
void Tank::goForward()
{
    qreal angle = rotation() * M_PI / 180;
    setPos(x() + 3*qCos(angle), y() + 3*qSin(angle));
    if(collision())
        goBack();
}
void Tank::goBack()
{
    qreal angle = rotation() * M_PI / 180;
    setPos(x() - 3*qCos(angle), y() - 3*qSin(angle));
    if(collision())
        goForward();
}
void Tank::shoot()
{
    if(haveBullet)
    {
        haveBullet=false;
        b1->shoot(x()+18+qCos(rotation() * M_PI / 180)*28,y()+10+qSin(rotation() * M_PI / 180)*28,rotation() * M_PI / 180);
    }
}

