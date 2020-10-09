/**
 * @file server.h
 * @author Roman Safin
 * @brief Custom server class
 */
#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
class socket;
class server : public QTcpServer
{
public:
    server(QObject *parent = nullptr);
    /**
     * @brief start server
     * @param port
     * @return started
     */
    bool startServer(quint16 port);
    /**
     * @brief connect/disconnect socket
     * @param socket handle
     */
    void incomingConnection(qintptr handle) override;
    /**
     * @brief send last 10 message
     * @param socket
     */
    void sendRecent(socket* s);
private:
    QList<socket *> LSockets;
};

#endif // SERVER_H
