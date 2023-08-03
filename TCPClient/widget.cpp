#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    socket=new QTcpSocket;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_cancelButton_clicked()
{
    this->close();
}

void Widget::on_connectButton_clicked()
{
    QString IP=ui->ipLineEdit->text();
    QString port=ui->portLineEdit->text();

    socket->connectToHost(QHostAddress(IP),port.toShort());

    connect(socket,&QTcpSocket::connected,[this](){
        QMessageBox::information(this,"连接提示","连接成功");

        this->hide();
        chat *c=new chat(socket);
        c->show();
    });

    connect(socket,&QTcpSocket::disconnected,[this](){
        QMessageBox::warning(this,"连接提示","连接失败");
    });
}
