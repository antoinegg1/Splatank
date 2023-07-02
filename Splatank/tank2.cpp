#include<QDebug>
#include "tank2.h"
#include<bullet.h>
#include<QKeyEvent>
#include<QGraphicsScene>

Tank2::Tank2(const QPixmap &pixmap,MyScene *scene):QGraphicsPixmapItem(pixmap),b1(scene)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    leftKeyPressed = false;
    rightKeyPressed = false;
    upKeyPressed = false;
    downKeyPressed = false;
    parent=scene;
    parent->addItem(this);
    setPos(700,227);
    setFocus();
}


void Tank2::MykeyPressEvent(int key){
    if(key==Qt::Key_M){
        b1.shoot(x()+18+qCos(rotation() * M_PI / 180+M_PI)*28,y()+10+qSin(rotation() * M_PI / 180+M_PI)*28,rotation() * M_PI / 180+M_PI);
    }
    if (key == Qt::Key_Left) {
        leftKeyPressed = true;
        if (!rightKeyPressed) {
            setTransformOriginPoint(boundingRect().center());
            setRotation(rotation() - 7);

            if(upKeyPressed)
            {
                if(!downKeyPressed)
                {
                    qreal angle = rotation() * M_PI / 180;
                    setPos(x() - 10*qCos(angle), y() - 10*qSin(angle));
                }
            }
            if(downKeyPressed)
            {
                if(!upKeyPressed)
                {
                    qreal angle = rotation() * M_PI / 180;
                    setPos(x() + 10*qCos(angle), y() + 10*qSin(angle));
                }
            }
        }
    }

    else if (key == Qt::Key_Right) {
        rightKeyPressed = true;
        if (!leftKeyPressed) {
            setTransformOriginPoint(boundingRect().center());
            setRotation(rotation() + 7);

            if(upKeyPressed)
            {
                if(!downKeyPressed)
                {
                    qreal angle = rotation() * M_PI / 180;
                    setPos(x() - 10*qCos(angle), y() - 10*qSin(angle));
                }
            }
            if(downKeyPressed)
            {
                if(!upKeyPressed)
                {
                    qreal angle = rotation() * M_PI / 180;
                    setPos(x() + 10*qCos(angle), y() + 10*qSin(angle));
                }
            }
        }
    }

    else if (key == Qt::Key_Up) {
        upKeyPressed = true;
        if (!downKeyPressed) {

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

    else if (key == Qt::Key_Down) {
        downKeyPressed = true;
        if (!upKeyPressed) {
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
