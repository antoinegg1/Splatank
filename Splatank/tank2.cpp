#include<QDebug>
#include<tank.h>
#include "tank2.h"
#include<bullet.h>
#include<QTimer>
#include<QKeyEvent>
#include<QGraphicsScene>
#include<config.h>

Tank2::Tank2(const QPixmap &pixmap,MyScene *scene):QGraphicsPixmapItem(pixmap),tank_hp(100)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    b[0]=new Bullet(scene,this,-1);
    b[1]=new Bullet(scene,this,-1);
    b[2]=new Bullet(scene,this,-1);
    bulletNum=3;
    shootCD=true;
    bulletTurn=0;
    parent=scene;
    setPos(700,227);
    destroyed=false;
}

void Tank2::destroy()
{
    tank_hp=0;
    destroyed=true;
    parent->removeItem(this);
    QTimer::singleShot(3000, [this]() {
        setPos(700,227);
        setRotation(0);
        tank_hp=100;
        destroyed=false;
        parent->addItem(this);
        QList<QGraphicsItem *> collidingItems = this->collidingItems();
        for (QGraphicsItem *item : collidingItems)
        {
            if (item->type() == Tank::Type)
                ((Tank*)item)->destroy();
        }
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
    setRotation(rotation() - TANK_SPEED);
    if(collision())
        turnRight();
}
void Tank2::turnRight()
{
    setTransformOriginPoint(boundingRect().center());
    setRotation(rotation() + TANK_SPEED);
    if(collision())
        turnLeft();
}
void Tank2::goForward()
{
    qreal angle = rotation() * M_PI / 180;
    setPos(x() - TANK_SPEED*qCos(angle), y() - TANK_SPEED*qSin(angle));
    if(collision())
        goBack();
}
void Tank2::goBack()
{
    qreal angle = rotation() * M_PI / 180;
    setPos(x() + TANK_SPEED*qCos(angle), y() + TANK_SPEED*qSin(angle));
    if(collision())
        goForward();
}

void Tank2::shoot()
{
    if(shootCD&&bulletNum>0&&!destroyed)
    {
        shootCD=false;
        bulletNum--;
        b[bulletTurn]->shoot(x()+18+qCos(rotation() * M_PI / 180+M_PI)*28,y()+10+qSin(rotation() * M_PI / 180+M_PI)*28,rotation() * M_PI / 180+M_PI);
        bulletTurn=(bulletTurn+1)%3;
        QTimer::singleShot(300, [this]() {
            shootCD=true;
        });
    }
}

void Tank2::beHarmed(int harm)
{
    tank_hp-=harm;
    if(tank_hp<=0)
        destroy();
}
