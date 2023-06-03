#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>
#include <QPaintEvent>
#include "QKeyEvent"
#include "QtGui/qpainter.h"




#define WIDTH  800
#define LENGTH  500

#define blankspace  0
#define wall  1

#define p1color  11
#define p2color  12

#define p1colorname red
#define p2colorname blue

class GameBoard:public QGraphicsScene{

    int map[WIDTH+1][LENGTH+1];
public:
    void init()
    {
        for(int i=1;i<=WIDTH;i++)
        {
            for(int j=1;j<=LENGTH;j++)
            {
                map[i][j]=0;
                if(i%15==0)
                {
                    if(j>=i&&j<=2*i)
                    {
                        map[i][j] = 1;
                    }
                }
            }
        }
    }

    bool can_be_painted(int x,int y)
    {
        if(map[x][y]==1)
            return false;
        else
            return true;
    }

    void map_be_painted(int x,int y,int color)
    {
        if(x>=WIDTH||x<=0||y>=LENGTH||y<=0)
            return;
        else if(can_be_painted(x,y))
            map[x][y]=color;
    }

    void paint_map(QPaintEvent *event)

    {
        QPen mypen;
        QPainter painter;
        mypen.setWidth(1);
        for(int i=1;i<=WIDTH;i++)
        {
            for(int j=1;j<=LENGTH;j++)
            {
                if(map[i][j]==p1color)
                {
                    mypen.setColor(Qt::p1colorname);
                    painter.setPen(mypen);
                    painter.drawPoint(i,j);

                }
                if(map[i][j]==p2color)
                {
                    mypen.setColor(Qt::p2colorname);
                    painter.setPen(mypen);
                    painter.drawPoint(i,j);
                }
            }
        }
    }

};
