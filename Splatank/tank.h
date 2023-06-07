#ifndef TANK_H
#define TANK_H
#include<bullet.h>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QTimer>
#include<myscene.h>

class Tank : public QGraphicsPixmapItem
{
public:
    Tank(const QPixmap &pixmap, MyScene *scene);

    Bullet *b1;
    bool haveBullet;
    void destroy();
    void turnLeft();
    void turnRight();
    void goForward();
    void goBack();
    void shoot();

protected:

private:
    bool collision();
    QGraphicsScene *parent;
};


#endif // TANK_H
