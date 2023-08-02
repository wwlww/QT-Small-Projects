#include "mainwindow.h"

#include <QApplication>
#include <QKeyEvent>
#include <QLabel>
#include <QMainWindow>
#include <QPainter>
#include <QRect>
#include <QString>
#include <QTimer>
#include <QtMath>
#include <QVector>
#include<QMessageBox>

#include"snakegame.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SnakeGame game;
    game.show();

    return app.exec();
}
