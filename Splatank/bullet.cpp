<<<<<<< HEAD
#include <QPainter>
#include <QRect>
#include <board.h>
#include <bullet.h>

Bullet::Bullet(int x, int y, int attackpower,int direction) : m_x(x), m_y(y), m_attackpower(attackpower),m_direction(direction) {};

void Bullet::move()
    {
        // 根据子弹的方向更新子弹的位置
        switch (m_direction)
        {
        case Up:
            m_y -= m_speed;
            break;
        case Down:
            m_y += m_speed;
            break;
        case Left:
            m_x -= m_speed;
            break;
        case Right:
            m_x += m_speed;
            break;
        }
    }

 void Bullet::draw(QPainter& painter)
    {
        // 绘制子弹
        painter.setBrush(Qt::black);
        painter.drawRect(m_x, m_y, m_width, m_height);
    }


    QRect Bullet::getRect() const
    {
        // 返回子弹的矩形边界
        return QRect(m_x, m_y, m_width, m_height);
    }

    void Bullet::bulletsplash(GameBoard &a,int x,int y,int color)
    {
        for(int i=x-splashrange;i<=x+splashrange;i++)
        {
            for(int j=y-splashrange;j<=y+splashrange;j++)
            {
                if(sqrt(i*i+j*j)<=splashrange)
                {
                    if(a.can_be_reached(x,y,i,j))
                    {
                        a.map[i][j]=color;
                    }
                }
            }
        }

    }


=======
#include<QDebug>
#include <QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<myscene.h>
#include <QTimer>
#include<bullet.h>
#include<tank.h>
#include<tank2.h>


Bullet::Bullet(MyScene* scene,QGraphicsPixmapItem* tank,int Color) : QGraphicsPixmapItem(QPixmap("..\\Splatank\\res\\bullet.png")),color(Color)
{
    parent=scene;
    speed = 5;
    dx = 0;
    dy = 0;
    startX=0;
    startY=0;
    parentTank=tank;
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::moveBy);
    timer->start(10);
}

Bullet::~Bullet()
{

}

void Bullet::shoot(qreal X,qreal Y,qreal angle) {
        setPos(X,Y);
        startX=X;
        startY=Y;
        bomb=false;
        parent->addItem(this);
        dx = qCos(angle) * speed;
        dy = qSin(angle) * speed;
    }

void Bullet:: moveBy() {
        setPos(x() + dx, y() + dy);
        qreal dis=(x()-startX)*(x()-startX)+(y()-startY)*(y()-startY);
        QList<QGraphicsItem *> collidingItems = this->collidingItems();
        if (!collidingItems.isEmpty()||dis>=40000) {
            // item与其他图形项发生了碰撞
            if(!bomb)
            {
                bomb=true;
                parent->shouldDraw=true;
                parent->bombAt(color,x()+5,y()+4);
                parent->removeItem(this);
                parent->update();
                if(color==1)
                    ((Tank*)parentTank)->haveBullet=true;
                else if(color==-1)
                    ((Tank2*)parentTank)->haveBullet=true;
                for (QGraphicsItem *item : collidingItems)
                {
                    if (item->type() == Tank::Type)
                        ((Tank*)item)->destroy();
                    if (item->type() == Tank2::Type)
                        ((Tank2*)item)->destroy();

                }
            }
        }
    }
>>>>>>> c9835b1f649d8de747fc08e1cf97824ae2bb7def
