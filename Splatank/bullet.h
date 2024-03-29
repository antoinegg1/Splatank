#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include<myscene.h>
#include <QTimer>

class Bullet : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(MyScene* scene, QGraphicsPixmapItem* tank,int Color);
    ~Bullet();
    void shoot(qreal X,qreal Y,qreal angle);
    void moveBy() ;
    bool bomb;
    bool shooted;

private slots:

private:
    qreal speed;
    qreal dx;
    qreal dy;
    qreal startX;
    qreal startY;
    int color;
    MyScene* parent;
    QGraphicsPixmapItem* parentTank;
};

#endif // BULLET_H
