#ifndef MYSCENE_H
#define MYSCENE_H
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include <QObject>
#include <QWidget>
#include <QtGlobal>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>

class MyScene: public QGraphicsScene
{
    Q_OBJECT
    int map[800][550];
    bool aKeyPressed;
    bool dKeyPressed;
    bool wKeyPressed;
    bool sKeyPressed;
    bool qKeyPressed;
    bool upKeyPressed;
    bool downKeyPressed;
    bool leftKeyPressed;
    bool rightKeyPressed;
    bool mKeyPressed;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    int changeX;
    int changeY;
    QGraphicsTextItem* winner;
public:
    MyScene();
    void addWinner();
    void drawBackground(QPainter* ptr, const QRectF &rect) override;
    void bombAt(int color,qreal X,qreal Y,qreal range);
    void init_map();
    bool shouldDraw;
    bool can_be_reached_by_color(int sx,int sy,int ex,int ey);
    qreal circleX;
    qreal circleY;
    void endGame();
    int count1;
    int count2;
    QGraphicsPixmapItem* player1;
    QGraphicsPixmapItem* player2;
    QGraphicsTextItem* TimeBoard;
    QPixmap redtank;
    QPixmap greentank;

    void painthp(int player,int s,int e);
    void paintenergy(int player,int s,int e);
    void myUpdate();
signals:
    void escSignal();

};

#endif // MYSCENE_H
