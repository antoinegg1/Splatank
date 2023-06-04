#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<myscene.h>
#include<tank.h>
#include<tank2.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void StartGame();

    Tank *player1;
    Tank2 *player2;

    //void keyPressEvent(QKeyEvent *event) override;
    //void keyReleaseEvent(QKeyEvent *event) override;

protected:

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    MyScene* MainScene;
    QGraphicsView* MainView;
    bool wKeyPressed;
    bool aKeyPressed;
    bool sKeyPressed;
    bool dKeyPressed;

};
#endif // WIDGET_H
