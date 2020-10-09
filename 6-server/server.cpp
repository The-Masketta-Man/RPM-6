/**
 * @file server.cpp
 * @author Roman Safin
 * @brief Custom server class
 */
#include "server.h"
#include "socket.h"
#include <QDebug>
#include <QTextStream>
#include <QFile>
QFile file("..\\file.txt");
server::server(QObject *parent)
    : QTcpServer(parent)

{
    file.close();
    if(!file.open(QIODevice::WriteOnly)){
            qInfo() << "File isn't open.";
        }
    file.resize(0);
}
bool server::startServer(quint16 port)
{
    return listen(QHostAddress::Any, port);
}
void server::incomingConnection(qintptr handle)
{
    qDebug() << "Client connected with handle:" << handle;
    auto sock = new socket(handle, this);
    LSockets << sock;
    sendRecent(sock);
    for (auto i: LSockets){
        QTextStream T(i);
        T << "Connected:" << handle;
        i->flush();
    }
    connect(sock, &socket::SReadyRead, [&](socket *S){
        qDebug() << "SReadyRead";
        QTextStream T(S);
        auto text = T.readAll();
        for (auto i : LSockets) {
            QTextStream K(i);
            K << text;
            i->flush();
        }

            });
    connect(sock, &socket::SStateChanged, [&](socket *S, int ST)
    {
         qDebug() << "SStateChanged";
        if (ST == QTcpSocket::UnconnectedState)
        {
            qDebug() << "Disconnected state with handle" << S->socketDescriptor();
            LSockets.removeOne(S);
            for (auto i : LSockets) {
                QTextStream K(i);
                K << "Client " <<
           S->socketDescriptor() << " has been disconnected"; //рассказать всем, что сокет отключился
                i->flush();
            }
        }
    });

}
void server::sendRecent(socket* s)
{
    file.close();
    if(!file.open(QIODevice::ReadOnly)){
    qInfo() << "File isn't open.";
}
socket* clSock = s;
QTextStream socket_stream (clSock);
QTextStream file_stream(&file);
socket_stream<<endl;
while(!file_stream.atEnd()){
    QString string = file_stream.readLine();
    socket_stream << string;
    socket_stream<<endl;

}
socket_stream<<endl;
file.close();
}
