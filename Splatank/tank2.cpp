#include<QDebug>
#include "tank2.h"
#include<bullet.h>
#include<QTimer>
#include<QKeyEvent>
#include<QGraphicsScene>

Tank2::Tank2(const QPixmap &pixmap,MyScene *scene):QGraphicsPixmapItem(pixmap)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    b1=new Bullet(scene,this,-1);
    haveBullet=true;
    parent=scene;
    setPos(700,227);
}

void Tank2::destroy()
{
    parent->removeItem(this);
    QTimer::singleShot(3000, [this]() {
        setPos(700,227);
        setRotation(0);
        parent->addItem(this);
    });
}

bool Tank2::collision()
{
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    if (!collidingItems.isEmpty())
        return true;
    return false;
}

void Tank2::turnLeft()
{
    setTransformOriginPoint(boundingRect().center());
    setRotation(rotation() - 3);
    if(collision())
        turnRight();
}
void Tank2::turnRight()
{
    setTransformOriginPoint(boundingRect().center());
    setRotation(rotation() + 3);
    if(collision())
        turnLeft();
}
void Tank2::goForward()
{
    qreal angle = rotation() * M_PI / 180;
    setPos(x() - 3*qCos(angle), y() - 3*qSin(angle));
    if(collision())
        goBack();
}
void Tank2::goBack()
{
    qreal angle = rotation() * M_PI / 180;
    setPos(x() + 3*qCos(angle), y() + 3*qSin(angle));
    if(collision())
        goForward();
}

void Tank2::shoot()
{
    if(haveBullet)
    {
        haveBullet=false;
        b1->shoot(x()+18+qCos(rotation() * M_PI / 180+M_PI)*28,y()+10+qSin(rotation() * M_PI / 180+M_PI)*28,rotation() * M_PI / 180+M_PI);
    }
}
