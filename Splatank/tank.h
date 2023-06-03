#ifndef TANK_H
#define TANK_H
#include<QGraphicsPixmapItem>
#include<QKeyEvent>

class Tank : public QGraphicsPixmapItem
{
public:
    Tank(const QPixmap &pixmap);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    bool leftKeyPressed;
    bool upKeyPressed;
    bool rightKeyPressed;
    bool downKeyPressed;
};


#endif // TANK_H
