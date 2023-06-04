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
    leftKeyPressed = false;
    rightKeyPressed = false;
    upKeyPressed = false;
    downKeyPressed = false;
    haveBullet=true;
    parent=scene;
    parent->addItem(this);
    setPos(700,227);
    //setFocus();
}

void Tank2::destroy()
{
    parent->removeItem(this);
    QTimer::singleShot(3000, [this]() {
        setPos(700,227);
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
    setRotation(rotation() - 8);
    if(collision())
        turnRight();
}
void Tank2::turnRight()
{
    setTransformOriginPoint(boundingRect().center());
    setRotation(rotation() + 8);
    if(collision())
        turnLeft();
}
void Tank2::goForward()
{
    qreal angle = rotation() * M_PI / 180;
    setPos(x() - 10*qCos(angle), y() - 10*qSin(angle));
    if(collision())
        goBack();
}
void Tank2::goBack()
{
    qreal angle = rotation() * M_PI / 180;
    setPos(x() + 10*qCos(angle), y() + 10*qSin(angle));
    if(collision())
        goForward();
}

void Tank2::MykeyPressEvent(int key){

    if(key==Qt::Key_M&&haveBullet){
        haveBullet=false;
        b1->shoot(x()+18+qCos(rotation() * M_PI / 180+M_PI)*28,y()+10+qSin(rotation() * M_PI / 180+M_PI)*28,rotation() * M_PI / 180+M_PI);
    }
    if (key== Qt::Key_Left) {
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

    else if (key == Qt::Key_Right) {
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

    else if (key == Qt::Key_Up) {
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

    else if (key == Qt::Key_Down) {
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


void Tank2::MykeyReleaseEvent(int key) {
    if (key == Qt::Key_Left) {
        leftKeyPressed = false;
    } else if (key == Qt::Key_Right) {
        rightKeyPressed = false;
    } else if (key == Qt::Key_Up) {
        upKeyPressed = false;
    } else if (key == Qt::Key_Down) {
        downKeyPressed = false;
    }
}
