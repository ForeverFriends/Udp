#include "TcpTest.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    TcpTest w;
    w.show();

    return a.exec();
}
