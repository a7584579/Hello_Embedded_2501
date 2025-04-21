#include "mainwindow.h"
#include "coffee_daemon.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    CoffeeDaemon daemon;
    daemon.startDaemon();

    QObject::connect(&a, &QCoreApplication::aboutToQuit, [&daemon]() {
        daemon.stopDaemon();
    });

    return a.exec();
}
