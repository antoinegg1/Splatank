#include "dialog.h"
#include "board.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    //test
    return a.exec();
}
