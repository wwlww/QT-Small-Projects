#include "mythread.h"

myThread::myThread(QTcpSocket *s)
{
    socket = s;
}

void myThread::run()
{
    connect(socket,&QTcpSocket::readyRead,this,&myThread::clienInfoSlot);
}


void myThread::clienInfoSlot()
{
    //qDebug()<<socket->readAll();

    //自定义信号
    emit sendToWidget(socket->readAll());
}
