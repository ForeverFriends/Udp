#include "TcpTest.h"
#include "ui_TcpTest.h"

TcpTest::TcpTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpTest)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(8888);

    setWindowTitle(QObject::tr("服务器端口9999"));

    connect(udpSocket, &QUdpSocket::readyRead, this, &TcpTest::delMsg);

}
void TcpTest::delMsg()
{
    char buf[1024] = {0};
    QHostAddress cliAddr;
    quint16 port;
    qint64 len = udpSocket->readDatagram(buf, sizeof(buf) , &cliAddr, &port);
    if(len > 0)
    {
        QString str = QString( "[%1:%2] %3").arg(cliAddr.toString())
                .arg(port).arg(buf);
        ui->textEdit->setText(str);
    }
}

TcpTest::~TcpTest()
{
    delete ui;
}

void TcpTest::on_BtnSend_clicked()
{
    QString strIp = ui->IPEdit->text();
    quint16 port = ui->PortEdit->text().toInt();
    QString strMsg = ui->textEdit->toPlainText();

    udpSocket->writeDatagram(strMsg.toUtf8(), QHostAddress(strIp), port);
}
