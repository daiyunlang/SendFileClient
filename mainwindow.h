#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SendFile.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void SetPercent(int per);

private slots:
    void on_ChoosePushButton_clicked();

    void on_SendPushButton_clicked();

    void on_connectPushButton_clicked();

signals:
    void StartConnect(QString ip, unsigned short port);
    void SendFileSignals(QString tPath);

private:
    Ui::MainWindow *ui;

    SendFile * _sendFile;

    QThread    _thread;
};
#endif // MAINWINDOW_H
