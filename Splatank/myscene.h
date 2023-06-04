#ifndef MYSCENE_H
#define MYSCENE_H
#include<QGraphicsScene>

class MyScene: public QGraphicsScene
{
    int map[800][500];
public:
    MyScene();
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void bombAt(int color,qreal X,qreal Y);
    bool shouldDraw;
    qreal circleX;
    qreal circleY;
};

#endif // MYSCENE_H
