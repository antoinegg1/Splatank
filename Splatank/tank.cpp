#include<QDebug>
#include "tank.h"
#include<bullet.h>
#include<QKeyEvent>
#include<QGraphicsScene>

Tank::Tank(const QPixmap &pixmap,MyScene *scene):QGraphicsPixmapItem(pixmap),b1(scene)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    leftKeyPressed = false;
    rightKeyPressed = false;
    upKeyPressed = false;
    downKeyPressed = false;
    parent=scene;
    parent->addItem(this);
    setPos(54,227);
    setFocus();
}


void Tank::MykeyPressEvent(int key){

    if(key==Qt::Key_Q){
        b1.shoot(x()+18+qCos(rotation() * M_PI / 180)*28,y()+10+qSin(rotation() * M_PI / 180)*28,rotation() * M_PI / 180);
    }
    if (key== Qt::Key_A) {
        leftKeyPressed = true;
        if (!rightKeyPressed) {
            setTransformOriginPoint(boundingRect().center());
            setRotation(rotation() - 7);

            if(upKeyPressed)
            {
                if(!downKeyPressed)
                {
                    qreal angle = rotation() * M_PI / 180;
                    setPos(x() + 10*qCos(angle), y() + 10*qSin(angle));
                }
            }
            if(downKeyPressed)
            {
                if(!upKeyPressed)
                {
                    qreal angle = rotation() * M_PI / 180;
                    setPos(x() - 10*qCos(angle), y() - 10*qSin(angle));
                }
            }
        }
    }

    else if (key == Qt::Key_D) {
        rightKeyPressed = true;
        if (!leftKeyPressed) {
            setTransformOriginPoint(boundingRect().center());
            setRotation(rotation() + 7);

            if(upKeyPressed)
            {
                if(!downKeyPressed)
                {
                    qreal angle = rotation() * M_PI / 180;
                    setPos(x() + 10*qCos(angle), y() + 10*qSin(angle));
                }
            }
            if(downKeyPressed)
            {
                if(!upKeyPressed)
                {
                    qreal angle = rotation() * M_PI / 180;
                    setPos(x() - 10*qCos(angle), y() - 10*qSin(angle));
                }
            }
        }
    }

    else if (key == Qt::Key_W) {
        upKeyPressed = true;
        if (!downKeyPressed) {

            qreal angle = rotation() * M_PI / 180;
            setPos(x() + 10*qCos(angle), y() + 10*qSin(angle));

            if(leftKeyPressed){
                if (!rightKeyPressed) {
                    setTransformOriginPoint(boundingRect().center());
                    setRotation(rotation() - 7);
                }
            }
            if(rightKeyPressed){
                if (!leftKeyPressed) {
                    setTransformOriginPoint(boundingRect().center());
                    setRotation(rotation() + 7);
                }
            }
        }
    }

    else if (key == Qt::Key_S) {
        downKeyPressed = true;
        if (!upKeyPressed) {
            qreal angle = rotation() * M_PI / 180;
            setPos(x() - 10*qCos(angle), y() - 10*qSin(angle));

            if(leftKeyPressed){
                if (!rightKeyPressed) {
                    setTransformOriginPoint(boundingRect().center());
                    setRotation(rotation() - 7);
                }
            }
            if(rightKeyPressed){
                if (!leftKeyPressed) {
                    setTransformOriginPoint(boundingRect().center());
                    setRotation(rotation() + 7);
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

