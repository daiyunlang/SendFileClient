#ifndef SENDFILE_H
#define SENDFILE_H

#include <QObject>
#include <QTcpSocket>

class SendFile : public QObject
{
    Q_OBJECT
public:
    explicit SendFile(QObject *parent = nullptr);

    //connect server
    void ConnectServer(QString tIP, unsigned short tPort);

    //send file
    void SendFileTo(QString tPath);


signals:
    void Connected();
    void DisConnected();
    void CurPercent(int per);
private:
    QTcpSocket * _pTcpSocket;

};

#endif // SENDFILE_H
