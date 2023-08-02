#include "widget.h"
#include "ui_widget.h"
#include"calculate.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMaximumSize(379,470);
    this->setMinimumSize(379,470);

    this->setWindowTitle("计算器");

    QFont f("仿宋",14);
    ui->mainLineEdit->setFont(f);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_oneButton_clicked()
{
    expression+="1";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_twoButton_clicked()
{
    expression+="2";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_threeButton_clicked()
{
    expression+="3";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_fourButton_clicked()
{
    expression+="4";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_fiveButton_clicked()
{
    expression+="5";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_sixButton_clicked()
{
    expression+="6";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_sevenButton_clicked()
{
    expression+="7";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_eightButton_clicked()
{
    expression+="8";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_nineButton_clicked()
{
    expression+="9";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_zeroButton_clicked()
{
    expression+="0";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_leftButton_clicked()
{
    expression+="(";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_rightButton_clicked()
{
    expression+=")";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_equalButton_clicked()
{
    //expression+="=";
    //ui->mainLineEdit->setText(expression);
    //设置背景颜色
    //ui->equalButton->setStyleSheet("bankground:blue");

    QString res=Calculator::calculate(expression);
    ui->mainLineEdit->setText(res);
    expression=res;
}

void Widget::on_divButton_clicked()
{
    expression+="/";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_mulButton_clicked()
{
    expression+="*";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_subButton_clicked()
{
    expression+="-";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_addButton_clicked()
{
    expression+="+";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_clearButton_clicked()
{
    expression.clear();
    ui->mainLineEdit->setText("");
}

void Widget::on_delButton_clicked()
{
    expression.chop(1);
    ui->mainLineEdit->setText(expression);
}
