/**
 * @file socket.cpp
 * @author Roman Safin
 * @brief Custom socket class
 */
#include "socket.h"

socket::socket(qintptr handle, QObject *parent)
{
    setSocketDescriptor(handle);
    connect(this, &socket::readyRead, [&]()
    {
        emit SReadyRead(this);
    });
    connect(this, &socket::stateChanged, [&](int S)
    {emit SStateChanged(this, S);
    });
}

