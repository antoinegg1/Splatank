#ifndef TIMEBOARD_H
#define TIMEBOARD_H
#include <QGraphicsTextItem>
#include<myscene.h>
#include <QTimer>

class timeBoard :public QGraphicsTextItem
{
    Q_OBJECT
public:
    timeBoard(int CountdownSeconds,MyScene* scene);
    QTimer *timer;

private slots:
    void updateCountdown();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int countdownSeconds;
    MyScene* parent;
};

#endif // TIMEBOARD_H
