#include "spacegame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpaceGame w;
    w.show();

    return a.exec();
}
