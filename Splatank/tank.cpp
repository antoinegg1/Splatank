#include<QDebug>
#include "tank.h"
#include <iostream>
#include<tank2.h>
#include<bullet.h>
#include<QKeyEvent>
#include<myscene.h>
#include<QGraphicsScene>
#include<config.h>

Tank::Tank(const QPixmap &pixmap,MyScene *scene):QGraphicsPixmapItem(pixmap),tank_hp(100),speed(TANK_SPEED)
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
    recover_remaintime=5;
    outofwar = false;
    tank_hp = TANK_HP;
}

void Tank::destroy()
{
    tank_hp=0;
    destroyed=true;
    parent->removeItem(this);
    QTimer::singleShot(3000, [this]() {
        setPos(54,227);
        setRotation(0);
        destroyed=false;
        tank_hp=100;
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
    setRotation(rotation() - speed);
    if(collision())
        turnRight();
}
void Tank::turnRight()
{
    setTransformOriginPoint(boundingRect().center());
    setRotation(rotation() + speed);
    if(collision())
        turnLeft();
}
void Tank::goForward()
{
    qreal angle = rotation() * M_PI / 180;
    setPos(x() + speed*qCos(angle), y() + speed*qSin(angle));
    if(collision())
        goBack();
}
void Tank::goBack()
{
    qreal angle = rotation() * M_PI / 180;
    setPos(x() - speed*qCos(angle), y() - speed*qSin(angle));
    if(collision())
        goForward();
}

void Tank::shoot()
{
    if(shootCD&&bulletNum>0&&!destroyed)
    {
        shootCD=false;
        bulletNum--;
        resettimer();
        b[bulletTurn]->shoot(x()+18+qCos(rotation() * M_PI / 180)*28,y()+10+qSin(rotation() * M_PI / 180)*28,rotation() * M_PI / 180);
        bulletTurn=(bulletTurn+1)%3;
        QTimer::singleShot(300, [this]() {
            shootCD=true;
        });
    }
}

void Tank::beHarmed(int harm)
{
    tank_hp-=harm;
    if(harm>0)
        resettimer();
    if(tank_hp<=0)
        destroy();
}
void Tank::handletimeout()
{
    recover_remaintime --;
    if(recover_remaintime==0)
    {
        outofwar = true;
        recover();
    }
    else if(outofwar)
    {
        recover();
    }
}
void Tank::resettimer()
{
    recover_remaintime = 5;
    outofwar=false;
}
void Tank::recover()
{
    if(tank_hp<TANK_HP)
    {
        tank_hp += fmin(RECOVER_HP,TANK_HP-tank_hp);
    }
}
