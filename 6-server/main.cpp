/**
 * @file main.cpp
 * @author Roman Safin
 */
#include "server.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    server server;
    if (!server.startServer(3333))
    {
        qDebug() << "Error:" << server.errorString();
        return 1;
    }
    qDebug() << "Server started!";
    //MainWindow w;
    //w.show();
    return a.exec();
}
