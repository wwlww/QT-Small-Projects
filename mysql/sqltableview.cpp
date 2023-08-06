#include "sqltableview.h"
#include "ui_sqltableview.h"

sqltableview::sqltableview(QSqlDatabase *db,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sqltableview)
{
    ui->setupUi(this);
    mydb = db;

    m = new QSqlTableModel;
    m->setTable("student");
    ui->tableView->setModel(m);

    m->select();
}

sqltableview::~sqltableview()
{
    delete ui;
}
