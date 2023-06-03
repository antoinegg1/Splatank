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


