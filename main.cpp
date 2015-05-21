#include <QCoreApplication>
#include "control.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    control * processo = new control;
    processo->setParent(&app);
    processo->plasticReady(true);
    return app.exec();
}
