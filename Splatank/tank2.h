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

    Bullet *b1;
    bool haveBullet;
    void destroy();
    void turnLeft();
    void turnRight();
    void goForward();
    void goBack();
    void shoot();
    enum { Type = UserType + 1 };
    int type() const override {
        return Type;
    }

protected:

private:
    bool collision();
    QGraphicsScene *parent;
};


#endif // TANK2_H
