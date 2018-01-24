#include "bj.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BJ w;
    w.show();

    return a.exec();
}
