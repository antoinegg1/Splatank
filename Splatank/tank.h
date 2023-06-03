#ifndef TANK_H
#define TANK_H
#include<bullet.h>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<myscene.h>

class Tank : public QGraphicsPixmapItem
{
public:
    Tank(const QPixmap &pixmap, MyScene *scene);

    Bullet b1;
    void MykeyPressEvent(int key) ;
    void MykeyReleaseEvent(int key);

protected:
    void shoot();

private:
    bool leftKeyPressed;
    bool upKeyPressed;
    bool rightKeyPressed;
    bool downKeyPressed;
    QGraphicsScene *parent;
};


#endif // TANK_H
