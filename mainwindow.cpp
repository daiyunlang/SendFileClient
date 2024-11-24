#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _sendFile(new SendFile)
{
    ui->setupUi(this);
    ui->IPLineEdit->setText("127.0.0.1");
    ui->PortLineEdit->setText("8999");
    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);

    _sendFile->moveToThread(&_thread);
    connect(this, &MainWindow::StartConnect, _sendFile, &SendFile::ConnectServer);
    _thread.start();

    connect(_sendFile, &SendFile::Connected, this, [=](){
        QMessageBox::information(this,
                                 "connect server",
                                 "connect server successfully",
                                 QMessageBox::Ok);
    });
    connect(_sendFile, &SendFile::DisConnected, this, [=](){
        QMessageBox::information(this,
                                 "connect server",
                                 "server disconnected",
                                 QMessageBox::Ok);
    });

    connect(this, &MainWindow::SendFileSignals, _sendFile, &SendFile::SendFileTo);

    connect(_sendFile, &SendFile::CurPercent, this, &MainWindow::SetPercent);
}

MainWindow::~MainWindow()
{
    delete ui;
    _thread.quit();
    _thread.wait();
    _sendFile->deleteLater();
}

void MainWindow::SetPercent(int per)
{
    ui->progressBar->setValue(per);
}


void MainWindow::on_ChoosePushButton_clicked()
{
    QString tPath = QFileDialog::getOpenFileName(this,
                                                 "choose send file",
                                                 QCoreApplication::applicationDirPath(),
                                                 tr("text, (*.txt)"));
    if(tPath.isEmpty()){
        return;
    }
    ui->FileLineEdit->setText(tPath);
}


void MainWindow::on_SendPushButton_clicked()
{
    emit SendFileSignals(ui->FileLineEdit->text());
}


void MainWindow::on_connectPushButton_clicked()
{
    QString ip = ui->IPLineEdit->text();
    unsigned short port = ui->PortLineEdit->text().toUShort();
    emit StartConnect(ip, port);
}

