#ifndef TCPTEST_H
#define TCPTEST_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class TcpTest;
}

class TcpTest : public QWidget
{
    Q_OBJECT

public:
    explicit TcpTest(QWidget *parent = 0);
    ~TcpTest();

private slots:
    void on_BtnSend_clicked();

private:
    Ui::TcpTest *ui;
    QUdpSocket* udpSocket;
    void delMsg();
};

#endif // TCPTEST_H
