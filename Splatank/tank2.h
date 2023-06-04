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

    void MykeyPressEvent(int key) ;
    void MykeyReleaseEvent(int key) ;
    void destroy();
    enum { Type = UserType + 1 };
    int type() const override {
        return Type;
    }

protected:
    void shoot();

private:
    bool leftKeyPressed;
    bool upKeyPressed;
    bool rightKeyPressed;
    bool downKeyPressed;
    void turnLeft();
    void turnRight();
    void goForward();
    void goBack();
    bool collision();
    QGraphicsScene *parent;
};


#endif // TANK2_H
