#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include<myscene.h>
#include <QTimer>

class Bullet : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(MyScene* scene);

    void shoot(qreal X,qreal Y,qreal angle);

private slots:
    void moveBy() ;

private:
    qreal speed;
    qreal dx;
    qreal dy;
    MyScene* parent;
};

#endif // BULLET_H
