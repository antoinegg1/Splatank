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
    void MykeyPressEvent(int key) ;
    void MykeyReleaseEvent(int key);
    void destroy();
    void turnLeft();
    void turnRight();
    void goForward();
    void goBack();
    void shoot();

protected:

private:
    bool leftKeyPressed;
    bool upKeyPressed;
    bool rightKeyPressed;
    bool downKeyPressed;
    bool collision();
    QGraphicsScene *parent;
};


#endif // TANK_H
