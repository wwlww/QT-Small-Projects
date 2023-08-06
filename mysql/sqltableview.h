#ifndef SQLTABLEVIEW_H
#define SQLTABLEVIEW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class sqltableview;
}

class sqltableview : public QWidget
{
    Q_OBJECT

public:
    explicit sqltableview(QSqlDatabase *db,QWidget *parent = nullptr);
    ~sqltableview();

private:
    Ui::sqltableview *ui;
    QSqlDatabase *mydb;
    QSqlTableModel *m;
};

#endif // SQLTABLEVIEW_H
