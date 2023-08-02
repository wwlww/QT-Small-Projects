#include "snakegame.h"

#include <QMessageBox>

SnakeGame::SnakeGame(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(400, 400);
    setWindowTitle("贪吃蛇游戏");

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(200);

    direction = Right;
    generateFood();

    snake.append(QRect(200, 200, 20, 20));
}

void SnakeGame::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, 400, 400));

    for (const QRect &block : snake) {
        painter.fillRect(block, Qt::green);
    }

    painter.fillRect(food, Qt::red);
}

void SnakeGame::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Up:
            if (direction != Down)
                direction = Up;
            break;
        case Qt::Key_Down:
            if (direction != Up)
                direction = Down;
            break;
        case Qt::Key_Left:
            if (direction != Right)
                direction = Left;
            break;
        case Qt::Key_Right:
            if (direction != Left)
                direction = Right;
            break;
    }
}

void SnakeGame::move()
{
    QRect head = snake.first();
    int newX = head.x();
    int newY = head.y();

    switch (direction) {
        case Up:
            newY -= 20;
            break;
        case Down:
            newY += 20;
            break;
        case Left:
            newX -= 20;
            break;
        case Right:
            newX += 20;
            break;
    }

    QRect newHead(newX, newY, 20, 20);

    if (newHead.intersects(food)) {
        snake.prepend(newHead);
        generateFood();
    } else {
        snake.prepend(newHead);
        snake.removeLast();
    }

    if (checkCollision()) {
        timer->stop();
        QMessageBox::information(this, "游戏结束", "撞到了！");
        close();
    }

    update();
}

void SnakeGame::generateFood()
{
    int x = qrand() % 20 * 20;
    int y = qrand() % 20 * 20;
    food = QRect(x, y, 20, 20);
}

bool SnakeGame::checkCollision()
{
    QRect head = snake.first();

    if (head.x() < 0 || head.x() >= 400
        || head.y() < 0 || head.y() >= 400)
        return true;

    for (int i = 1; i < snake.size(); ++i) {
        if (head.intersects(snake.at(i)))
            return true;
    }

    return false;
}
