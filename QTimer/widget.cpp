#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer=new QTimer;
    picId=2;
    QImage img;
    img.load("C:\\Users\\wwl\\Pictures\\");
    ui->label->setPixmap(QPixmap::fromImage(img));

    //定时器时间到，发出timeout信号
    connect(timer,&QTimer::timeout,this,&Widget::timeoutSlot);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    timer->start(TIMEOUT);
}

void Widget::timeoutSlot()
{
    QString path("C:\\Users\\wwl\\Pictures\\");
    path+=QString::number(picId);
    path+=".png";

    QImage img;
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));

    picId++;
    if(4==picId) picId=1;
}


void Widget::on_stopButton_clicked()
{
    timer->stop();
}

void Widget::on_onceButton_clicked()
{
    QTimer::singleShot(1,this,SLOT(timeoutSlot()));
}
