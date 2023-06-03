#include "tank.h"
#include<QKeyEvent>

Tank::Tank(const QPixmap &pixmap):QGraphicsPixmapItem(pixmap)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    leftKeyPressed = false;
    rightKeyPressed = false;
    upKeyPressed = false;
    downKeyPressed = false;
}

void Tank::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Left) {
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

    else if (event->key() == Qt::Key_Right) {
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

    else if (event->key() == Qt::Key_Up) {
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

    else if (event->key() == Qt::Key_Down) {
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

void Tank::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        leftKeyPressed = false;
    } else if (event->key() == Qt::Key_Right) {
        rightKeyPressed = false;
    } else if (event->key() == Qt::Key_Up) {
        upKeyPressed = false;
    } else if (event->key() == Qt::Key_Down) {
        downKeyPressed = false;
    }
}
