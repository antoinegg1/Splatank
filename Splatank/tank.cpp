#include<QDebug>
#include "tank.h"
#include<bullet.h>
#include<QKeyEvent>
#include<myscene.h>
#include<QGraphicsScene>

Tank::Tank(const QPixmap &pixmap,MyScene *scene):QGraphicsPixmapItem(pixmap)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    b1=new Bullet(scene,this,1);
    leftKeyPressed = false;
    rightKeyPressed = false;
    upKeyPressed = false;
    downKeyPressed = false;
    haveBullet=true;
    parent=scene;
    parent->addItem(this);
    setPos(54,227);
    //setFocus();
}

void Tank::destroy()
{
    parent->removeItem(this);
    QTimer::singleShot(3000, [this]() {
        setPos(54,227);
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
    setRotation(rotation() - 8);
    if(collision())
        turnRight();
}
void Tank::turnRight()
{
    setTransformOriginPoint(boundingRect().center());
    setRotation(rotation() + 8);
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

void Tank::MykeyPressEvent(int key){

    if(key==Qt::Key_Q&&haveBullet){
        haveBullet=false;
        b1->shoot(x()+18+qCos(rotation() * M_PI / 180)*28,y()+10+qSin(rotation() * M_PI / 180)*28,rotation() * M_PI / 180);
    }
    if (key== Qt::Key_A) {
        leftKeyPressed = true;
        if (!rightKeyPressed) {
            turnLeft();

            if(upKeyPressed)
            {
                if(!downKeyPressed)
                {
                    goForward();
                }
            }
            if(downKeyPressed)
            {
                if(!upKeyPressed)
                {
                    goBack();
                }
            }
        }
    }

    else if (key == Qt::Key_D) {
        rightKeyPressed = true;
        if (!leftKeyPressed) {
            turnRight();

            if(upKeyPressed)
            {
                if(!downKeyPressed)
                {
                    goForward();
                }
            }
            if(downKeyPressed)
            {
                if(!upKeyPressed)
                {
                    goBack();
                }
            }
        }
    }

    else if (key == Qt::Key_W) {
        upKeyPressed = true;
        if (!downKeyPressed) {

            goForward();

            if(leftKeyPressed){
                if (!rightKeyPressed) {
                    turnLeft();
                }
            }
            if(rightKeyPressed){
                if (!leftKeyPressed) {
                    turnRight();
                }
            }
        }
    }

    else if (key == Qt::Key_S) {
        downKeyPressed = true;
        if (!upKeyPressed) {
            goBack();

            if(leftKeyPressed){
                if (!rightKeyPressed) {
                    turnLeft();
                }
            }
            if(rightKeyPressed){
                if (!leftKeyPressed) {
                    turnRight();
                }
            }
        }
    }
}

void Tank::MykeyReleaseEvent(int key) {
    if (key == Qt::Key_A) {
        leftKeyPressed = false;
    } else if (key == Qt::Key_D) {
        rightKeyPressed = false;
    } else if (key == Qt::Key_W) {
        upKeyPressed = false;
    } else if (key == Qt::Key_S) {
        downKeyPressed = false;
    }
}

