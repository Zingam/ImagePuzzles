#include "forms/mainwindow.hpp"

#include <QtCore/QDebug>
#include <QtCore/QLibrary>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
