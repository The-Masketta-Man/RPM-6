/**
 * @file main.cpp
 * @author Roman Safin
 */

#include "mainwindow.cpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
