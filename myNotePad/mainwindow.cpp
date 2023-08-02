#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->newAction,&QAction::triggered,this,&MainWindow::newActionSlot);
    connect(ui->openAction,&QAction::triggered,this,&MainWindow::openActionSlot);
    connect(ui->saveAction,&QAction::triggered,this,&MainWindow::saveActionSlot);
    connect(ui->codeAction,&QAction::triggered,this,&MainWindow::codeActionSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newActionSlot()
{
    ui->textEdit->clear();
    this->setWindowTitle("新建文本文档.txt");
}

void MainWindow::openActionSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, "选择一个文件",
                                 QCoreApplication::applicationFilePath(),
                                 "*.*");
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"警告","请选择一个文件");
    }
    else
    {
        //qDebug()<<fileName;
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        ui->textEdit->setText(QString(ba));
        file.close();
    }
}

void MainWindow::saveActionSlot()
{
    QString fileName=QFileDialog::getSaveFileName(this,"选择一个文件",QCoreApplication::applicationFilePath());

    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"警告","请选择一个文件");
    }
    else
    {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        QByteArray ba;
        ba.append(ui->textEdit->toPlainText());
        file.write(ba);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    if(k->modifiers()==Qt::ControlModifier && k->key()==Qt::Key_S){
        saveActionSlot();
    }
}

void MainWindow::codeActionSlot()
{
    qDebug()<<"编译功能暂时实现失败";
//    // 获取文本编辑器的内容
//    QString code = ui->textEdit->toPlainText();

//    // 保存到main.cpp文件
//    QFile file("main.cpp");
//    file.open(QIODevice::WriteOnly);
//    file.write(code.toUtf8());
//    file.close();

//    // 调用qmake生成Makefile
//    QProcess process;
//    process.start("qmake");
//    process.waitForFinished();

//    // 调用make进行编译
//    process.start("make");
//    process.waitForFinished();

//    // 显示编译结果
//    QString output = process.readAllStandardOutput();
//    QMessageBox::information(this, "Compile Result", output);
}

