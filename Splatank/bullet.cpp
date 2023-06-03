#include <QPainter>
#include <QRect>

class Bullet
{
public:
    Bullet(int x, int y, int attackpower,int direction) : m_x(x), m_y(y), m_attackpower(attackpower),m_direction(direction) {}

    void move()
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

    void draw(QPainter& painter)
    {
        // 绘制子弹
        painter.setBrush(Qt::black);
        painter.drawRect(m_x, m_y, m_width, m_height);
    }

    QRect getRect() const
    {
        // 返回子弹的矩形边界
        return QRect(m_x, m_y, m_width, m_height);
    }

private:
    int m_x;              // 子弹的x坐标
    int m_y;              // 子弹的y坐标
    int m_direction;      // 子弹的方向
    int m_attackpower;      // 子弹的伤害
    int m_speed = 5;      // 子弹的速度
    int m_width = 5;      // 子弹的宽度
    int m_height = 10;    // 子弹的高度

    // 定义子弹的方向常量
    enum Direction
    {
        Up,
        Down,
        Left,
        Right
    };
};
