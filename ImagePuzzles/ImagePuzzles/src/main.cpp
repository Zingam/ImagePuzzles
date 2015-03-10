#include <QtCore/QDebug>
#include <QtCore/QLibrary>
#include <QtWidgets/QApplication>

#include "forms/mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
