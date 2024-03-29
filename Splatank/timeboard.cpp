#include<QDebug>
#include "timeboard.h"
#include<myscene.h>
#include"QTimer"
#include<QFont>
#include<QPainter>
#include<tank.h>
#include<tank2.h>

timeBoard::timeBoard(int CountdownSeconds,MyScene* scene): QGraphicsTextItem(), countdownSeconds(CountdownSeconds),parent(scene)
{
    setPlainText(QString::number(countdownSeconds));
    // 创建定时器
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &timeBoard::updateCountdown);
    //timer->start(1000);
    setPos(368,500);//225
    QFont font = this->font();
    font.setPointSize(24);
    setFont(font);
}

void timeBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // 绘制文本背景颜色
    QRectF rect = boundingRect();
    painter->setBrush(Qt::lightGray);
    painter->drawRect(rect);

    // 调用基类的paint函数来绘制文本
    QGraphicsTextItem::paint(painter, option, widget);
}

void timeBoard::updateCountdown()
{
    // 更新倒计时
    countdownSeconds--;
    ((Tank*)(parent->player1))->handletimeout();
    ((Tank2*)(parent->player2))->handletimeout();
    setPlainText(QString::number(countdownSeconds));
    // 倒计时结束
    if (countdownSeconds == -1)
    {
        timer->stop();
        QFont font =this->font();
        font.setPointSize(12);
        setFont(font);
        setPlainText("The Winner is……");
        parent->endGame();
    }
}
