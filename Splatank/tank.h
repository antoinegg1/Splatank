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

    Bullet *b[3];
    int bulletNum;
    void destroy();
    void turnLeft();
    void turnRight();
    void goForward();
    void goBack();
    void shoot();
    void recover();
    void handletimeout();
    void resettimer();
    bool destroyed;
    bool outofwar;
    enum { Type = UserType + 2 };
    int type() const override {
        return Type;
    }
    void beHarmed(int harm);
    int tank_hp;
    qreal energy;
    int speed;
    int recover_remaintime;

protected:

private:
    bool collision();
    MyScene *parent;
    bool shootCD;
    int bulletTurn;
};


#endif // TANK_H
