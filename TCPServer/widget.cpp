#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    server = new QTcpServer;

    server->listen(QHostAddress::AnyIPv4,8000);

    connect(server,&QTcpServer::newConnection,this,&Widget::newClientHandler);
}


Widget::~Widget()
{
    delete ui;
}

void Widget::newClientHandler()
{
    QTcpSocket *socket = server->nextPendingConnection();

    ui->ipLineEdit->setText(socket->peerAddress().toString());
    ui->portLineEdit->setText(QString::number(socket->peerPort()));

//    //服务器接受客户端发送的消息
//    connect(socket,&QTcpSocket::readyRead,this,&Widget::clinetInfoSlot);

    //启动线程
    myThread *t = new myThread(socket);
    //触发mythread中的run函数
    t->start();
    //线程接收到消息后，发出信号并传递接收到的消息，触发自定义的槽函数在ui中显示接收到的消息
    connect(t,&myThread::sendToWidget,this,&Widget::threadSlot);
}

void Widget::clinetInfoSlot()
{
//    //获取信号的发出者
//    QTcpSocket *s = (QTcpSocket *)sender();
//    ui->receveLineEdit->setText(QString(s->readAll()));
}

void Widget::threadSlot(QByteArray b)
{
    //显示接收到的消息
    ui->receveLineEdit->setText(QString(b));
}
