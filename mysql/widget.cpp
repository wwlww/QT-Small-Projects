#include "widget.h"
#include "ui_widget.h"

#include <QSqlQuery>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //连接数据库
    db = QSqlDatabase::addDatabase("QMYSQL"); //加载mysql驱动

    db.setDatabaseName("mydatabase");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("123456");

    if(db.open()){
        QMessageBox::information(this,"提示","连接成功");
    }
    else{
        QMessageBox::warning(this,"警告","连接失败");
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_insertButton_clicked()
{
    QString id = ui->xuehaoLineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString birth = ui->birthLineEdit->text();

    QString sql = QString("insert into student values (%1,'%2','%3');").arg(id).arg(name).arg(birth);

    QSqlQuery query;
    if(query.exec(sql)){
        QMessageBox::information(this,"插入提示","插入成功");
    }
    else{
        QMessageBox::information(this,"插入提示","插入失败");
    }
}

void Widget::on_findButton_clicked()
{
    //创建数据库ui对象
    sqltableview *sqlview = new sqltableview(&db);
    sqlview->show();
}
