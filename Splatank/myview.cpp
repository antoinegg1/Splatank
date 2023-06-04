#include<QDebug>
#include "myview.h"

MyView::MyView(Widget* widget,QGraphicsScene* scene):QGraphicsView(scene),parent(widget)
{
    player1KeyPressed=false;
    player2KeyPressed=false;

}

void MyView::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A||event->key()==Qt::Key_D||event->key()==Qt::Key_W||event->key()==Qt::Key_S||event->key()==Qt::Key_Q)
    {
        player1KeyPressed=true;
        player1Key=event->key();
        parent->player1->MykeyPressEvent(event->key());
        if(player2KeyPressed){
            parent->player2->MykeyPressEvent(player2Key);
        }
    }
    if(event->key()==Qt::Key_Left||event->key()==Qt::Key_Right||event->key()==Qt::Key_Up||event->key()==Qt::Key_Down||event->key()==Qt::Key_M)
    {
        player2KeyPressed=true;
        player2Key=event->key();
        parent->player2->MykeyPressEvent(player2Key);
        if(player1KeyPressed){
            parent->player1->MykeyPressEvent(player1Key);
        }
    }
    if(event->key()==Qt::Key_Escape){
       emit escSignal();
    }
}

void MyView::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A||event->key()==Qt::Key_D||event->key()==Qt::Key_W||event->key()==Qt::Key_S||event->key()==Qt::Key_Q)
    {
        player1KeyPressed=false;
        parent->player1->MykeyReleaseEvent(event->key());
    }
    if(event->key()==Qt::Key_Left||event->key()==Qt::Key_Right||event->key()==Qt::Key_Up||event->key()==Qt::Key_Down||event->key()==Qt::Key_M)
    {
        player2KeyPressed=false;
        parent->player2->MykeyReleaseEvent(event->key());
    }
}
