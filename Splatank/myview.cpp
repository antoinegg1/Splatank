#include<QDebug>
#include "myview.h"

MyView::MyView(Widget* widget,QGraphicsScene* scene):QGraphicsView(scene),parent(widget)
{
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
//void MyView::keyPressEvent(QKeyEvent *event)
//{
//    if(event->key()==Qt::Key_Escape)
//        emit escSignal();
//}

