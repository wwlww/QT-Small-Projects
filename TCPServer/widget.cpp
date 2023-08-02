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

}
