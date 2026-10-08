#include "integration.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    integration w;
    w.show();
    return QApplication::exec();
}
