#ifndef TANK2_H
#define TANK2_H
#include<QTimer>
#include<bullet.h>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<myscene.h>
#include<QObject>

class Tank2 : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tank2(const QPixmap &pixmap, MyScene *scene);

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
    enum { Type = UserType + 1 };
    int type() const override {
        return Type;
    }
    bool destroyed;
    bool outofwar;
    void beHarmed(int harm);
    int tank_hp;
    int speed;
    int recover_remaintime;

protected:

private:
    bool collision();
    QGraphicsScene *parent;
    bool shootCD;
    int bulletTurn;
};


#endif // TANK2_H
