#include "widget.h"
#include "form.h"
#include <QApplication>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< HEAD
//    Widget w;
//    w.show();
//    w.StartGame();
    Form s;
    s.show();

=======
    Widget w;
    w.show();
//    w.StartGame();
>>>>>>> c9835b1f649d8de747fc08e1cf97824ae2bb7def
    return a.exec();
}
