/**
 * @file mainwindow.h
 * @author Roman Safin
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QTcpSocket;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /**
     * @brief send message
     */
    void on_send_clicked();
    /**
     * @brief connect to server
     */
    void on_connect_clicked();


private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QStringList list;
    int k = 0;

};
#endif // MAINWINDOW_H
