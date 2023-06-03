#include "widget.h"
#include "form.h"
#include <QApplication>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
//    w.StartGame();
    Form s;
    s.show();

    return a.exec();
}
