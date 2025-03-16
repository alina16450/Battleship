#include "battleShip.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    battleShip b;
    b.show();
    return a.exec();
}
