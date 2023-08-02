#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    picId = 2;
    QPixmap pix("C:\\Users\\wwl\\Pictures\\1.png");
    ui->label->setPixmap(pix);
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()!=myTimerId) return;

    QString path("C:\\Users\\wwl\\Pictures\\");
    path+=QString::number(picId);
    path+=".png";

    QPixmap pix(path);
    ui->label->setPixmap(pix);

    picId++;
    if(4==picId) picId=1;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    myTimerId = this->startTimer(TIMEOUT);

}

void Widget::on_stopButton_clicked()
{
    this->killTimer(myTimerId);
}
