#include<QDebug>
#include "tank.h"
#include<tank2.h>
#include<bullet.h>
#include<QKeyEvent>
#include<myscene.h>
#include<QGraphicsScene>

Tank::Tank(const QPixmap &pixmap,MyScene *scene):QGraphicsPixmapItem(pixmap)
{
    b[0]=new Bullet(scene,this,1);
    b[1]=new Bullet(scene,this,1);
    b[2]=new Bullet(scene,this,1);
    bulletNum=3;
    shootCD=true;
    bulletTurn=0;
    parent=scene;
    setPos(54,227);
    destroyed=false;
}

void Tank::destroy()
{
    destroyed=true;
    parent->removeItem(this);
    QTimer::singleShot(3000, [this]() {
        setPos(54,227);
        setRotation(0);
        destroyed=false;
        parent->addItem(this);
        QList<QGraphicsItem *> collidingItems = this->collidingItems();
        for (QGraphicsItem *item : collidingItems)
        {
            if (item->type() == Tank2::Type)
                ((Tank2*)item)->destroy();
        }
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
    setRotation(rotation() - 10);
    if(collision())
        turnRight();
}
void Tank::turnRight()
{
    setTransformOriginPoint(boundingRect().center());
    setRotation(rotation() + 10);
    if(collision())
        turnLeft();
}
void Tank::goForward()
{
    qreal angle = rotation() * M_PI / 180;
    setPos(x() + 10*qCos(angle), y() + 10*qSin(angle));
    if(collision())
        goBack();
}
void Tank::goBack()
{
    qreal angle = rotation() * M_PI / 180;
    setPos(x() - 10*qCos(angle), y() - 10*qSin(angle));
    if(collision())
        goForward();
}

void Tank::shoot()
{
    if(shootCD&&bulletNum>0&&!destroyed)
    {
        shootCD=false;
        bulletNum--;
        b[bulletTurn]->shoot(x()+18+qCos(rotation() * M_PI / 180)*28,y()+10+qSin(rotation() * M_PI / 180)*28,rotation() * M_PI / 180);
        bulletTurn=(bulletTurn+1)%3;
        QTimer::singleShot(300, [this]() {
            shootCD=true;
        });
    }
}

