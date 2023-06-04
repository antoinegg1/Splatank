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
    void init_map();
    bool shouldDraw;
    bool can_be_reached_by_color(int sx,int sy,int ex,int ey);
    qreal circleX;
    qreal circleY;
    void endGame();
    int count1;
    int count2;
};

#endif // MYSCENE_H
