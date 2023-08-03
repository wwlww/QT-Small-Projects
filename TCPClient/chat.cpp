#include "chat.h"
#include "ui_chat.h"

chat::chat(QTcpSocket *s,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);

    socket = s;
}

chat::~chat()
{
    delete ui;
}

void chat::on_clearButton_clicked()
{
    ui->lineEdit->clear();
}

void chat::on_sendButton_clicked()
{
    QByteArray ba;
    ba.append(ui->lineEdit->text());
    socket->write(ba);
}
