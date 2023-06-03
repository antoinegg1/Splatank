#ifndef MYSCENE_H
#define MYSCENE_H
#include<QGraphicsScene>

class MyScene: public QGraphicsScene
{
public:
    MyScene();
    void drawBackground(QPainter *painter, const QRectF &rect) override;

    bool shouldDraw;
    qreal circleX;
    qreal circleY;
};

#endif // MYSCENE_H
