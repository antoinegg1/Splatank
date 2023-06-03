#include<QDebug>
#include <QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<myscene.h>
#include <QTimer>
#include<bullet.h>


Bullet::Bullet(MyScene* scene) : QGraphicsPixmapItem(QPixmap("..\\Splatank\\res\\bullet.png"))
{
    parent=scene;
    speed = 5;
    dx = 0;
    dy = 0;
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::moveBy);
    timer->start(10);
}

void Bullet::shoot(qreal X,qreal Y,qreal angle) {
        setPos(X,Y);
        parent->addItem(this);
        dx = qCos(angle) * speed;
        dy = qSin(angle) * speed;
    }

void Bullet:: moveBy() {
        setPos(x() + dx, y() + dy);
        QList<QGraphicsItem *> collidingItems = this->collidingItems();
        if (!collidingItems.isEmpty()) {
            // item与其他图形项发生了碰撞
            parent->shouldDraw=true;
            parent->circleX=x()+5;
            parent->circleY=y()+4;
            parent->removeItem(this);

            parent->update(QRectF(parent->circleX-50, parent->circleY-50, 100, 100));
        }
    }
