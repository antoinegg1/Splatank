#include<QDebug>
#include "myview.h"

MyView::MyView(Widget* widget,QGraphicsScene* scene):QGraphicsView(scene),parent(widget)
{
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
}


