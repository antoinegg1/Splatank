#ifndef BULLET_H
#define BULLET_H
<<<<<<< HEAD
#include <QPainter>
#include <board.h>

class Bullet
{
public:
    Bullet(int x, int y, int attackpower,int direction) ;
    void move();

    void draw(QPainter& painter);
    QRect getRect() const;

    void bulletsplash(GameBoard &a,int x,int y,int color);


private:
    int m_x;              // 子弹的x坐标
    int m_y;              // 子弹的y坐标
    int m_direction;      // 子弹的方向
    int m_attackpower;      // 子弹的伤害
    int m_speed = 5;      // 子弹的速度
    int m_width = 5;      // 子弹的宽度
    int m_height = 10;    // 子弹的高度
    int splashrange = 5;

    // 定义子弹的方向常量
    enum Direction
    {
        Up,
        Down,
        Left,
        Right
    };
};


=======
#include <QGraphicsPixmapItem>
#include<myscene.h>
#include <QTimer>

class Bullet : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(MyScene* scene, QGraphicsPixmapItem* tank,int Color);
    ~Bullet();
    void shoot(qreal X,qreal Y,qreal angle);

private slots:
    void moveBy() ;

private:
    qreal speed;
    qreal dx;
    qreal dy;
    qreal startX;
    qreal startY;
    bool bomb;
    int color;
    MyScene* parent;
    QGraphicsPixmapItem* parentTank;
};

>>>>>>> c9835b1f649d8de747fc08e1cf97824ae2bb7def
#endif // BULLET_H
