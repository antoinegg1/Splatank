#ifndef TIMEBOARD_H
#define TIMEBOARD_H
#include <QGraphicsTextItem>
#include <QTimer>

class timeBoard :public QGraphicsTextItem
{
    Q_OBJECT
public:
    timeBoard(int CountdownSeconds);

private slots:
    void updateCountdown();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QTimer *timer;
    int countdownSeconds;
};

#endif // TIMEBOARD_H
