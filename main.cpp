#include "mastermind.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    //Initiera ljudklass
    //Skapa ett QApplicationobjekt
    QApplication a(argc, argv);
    //Skapa och visa ett MasterMindobjekt
    MasterMind w;
    w.showNormal();
    return a.exec();
}
