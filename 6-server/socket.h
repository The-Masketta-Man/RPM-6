/**
 * @file socket.h
 * @author Roman Safin
 * @brief Custom socket class
 */
#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>
class socket : public QTcpSocket
{
    Q_OBJECT
public:
    socket(qintptr handle, QObject *parent = nullptr);
signals:
    void SReadyRead(socket *);
    void SStateChanged(socket *, int);
};

#endif // SOCKET_H
