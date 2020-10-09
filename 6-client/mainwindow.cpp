/**
 * @file mainwindow.cpp
 * @author Roman Safin
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>
#include <QTextStream>
QFile file("..\\file.txt");
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::readyRead,
            [&](){
        QTextStream T(socket);
        auto text = T.readAll();
        ui->textEdit->append(text);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_send_clicked()
{
    QTextStream T(socket);
    T << ui->nickname->text() << ":" << ui->message->text();
    list.push_back(ui->nickname->text() + ":" + ui->message->text());
    if(!file.open(QIODevice::WriteOnly)){
           qInfo() << "File isn't open.";
       }
    k++;

    if (k > 10){
            list.removeFirst();
        }
    QTextStream stream(&file);
        foreach(QString str, list){
            if (str != ""){
               stream << str << endl;
           }
        }
        file.close();
}

void MainWindow::on_connect_clicked()
{
    socket->connectToHost
            ("localhost",3333);
}
