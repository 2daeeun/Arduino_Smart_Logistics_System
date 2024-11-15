// main.cpp
#include <QApplication>
#include "MainWindow1.h"
// #include "MainWindow2.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow1 mainWindow1;
    // MainWindow2 mainWindow2;

    mainWindow1.show();
    // mainWindow2.show();

    return app.exec();
}
