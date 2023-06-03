#ifndef TANK2_H
#define TANK2_H

#include<bullet.h>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<myscene.h>

class Tank2 : public QGraphicsPixmapItem
{
public:
    Tank2(const QPixmap &pixmap, MyScene *scene);

    Bullet b1;

    void MykeyPressEvent(int key) ;
    void MykeyReleaseEvent(int key) ;

protected:
    void shoot();

private:
    bool leftKeyPressed;
    bool upKeyPressed;
    bool rightKeyPressed;
    bool downKeyPressed;
    QGraphicsScene *parent;
};


#endif // TANK2_H
