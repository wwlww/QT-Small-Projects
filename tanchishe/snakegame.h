#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include"mainwindow.h"


#include <QKeyEvent>
#include <QLabel>
#include <QMainWindow>
#include <QPainter>
#include <QRect>
#include <QString>
#include <QTimer>
#include <QtMath>
#include <QVector>

class SnakeGame : public QMainWindow
{
    Q_OBJECT

public:
    SnakeGame(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void move();

private:
    enum Direction {
        Up,
        Down,
        Left,
        Right
    };

    void generateFood();
    bool checkCollision();

    QTimer *timer;
    QVector<QRect> snake;
    QRect food;
    Direction direction;
};

#endif // SNAKEGAME_H
