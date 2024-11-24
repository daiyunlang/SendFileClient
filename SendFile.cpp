#include "SendFile.h"
#include <QHostAddress>
#include <QFile>
#include <QFileInfo>

SendFile::SendFile(QObject *parent)
    : QObject{parent}
    , _pTcpSocket(new QTcpSocket)
{

}

void SendFile::ConnectServer(QString tIP, unsigned short tPort)
{
    _pTcpSocket->connectToHost(QHostAddress(tIP), tPort);

    connect(_pTcpSocket, &QTcpSocket::connected, this, [=](){
        emit Connected();
    });
    connect(_pTcpSocket, &QTcpSocket::disconnected, this, [=](){
        _pTcpSocket->close();
        _pTcpSocket->deleteLater();
        emit DisConnected();
    });
}

void SendFile::SendFileTo(QString tPath)
{
    QFile file(tPath);
    QFileInfo tInfo(tPath);
    int fileSize = tInfo.size();
    int sendSize = 0;
    file.open(QFile::ReadOnly);
    while(!file.atEnd()){
        if(sendSize == 0){
            _pTcpSocket->write((char *)&fileSize, 4);
        }
        QByteArray tLine = file.readLine();
        _pTcpSocket->write(tLine);
        sendSize += tLine.size();
        int percent = sendSize/fileSize * 100;
        emit CurPercent(percent);
    }
}
