#ifndef MYVIEW_H
#define MYVIEW_H
#include<QMap>
#include<widget.h>
#include<QGraphicsView>
class MyView:public QGraphicsView
{
public:
    MyView(Widget* widget,QGraphicsScene* scene);

private:
    Widget* parent;
    bool player1KeyPressed;
    bool player2KeyPressed;
    int player1Key;
    int player2Key;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // MYVIEW_H
