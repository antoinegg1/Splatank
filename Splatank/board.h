#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsScene>
#include <QPaintEvent>

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
    void init();

    bool can_be_painted(int x,int y);

    void map_be_painted(int x,int y,int color);

    void paint_map(QPaintEvent *event);
};

#endif // BOARD_H
