#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QTcpSocket>
#include <QKeyEvent>
namespace Ui {
class chat;
}

class chat : public QWidget
{
    Q_OBJECT

public:
    explicit chat(QTcpSocket *s,QWidget *parent = nullptr);
    ~chat();

private slots:

    void on_clearButton_clicked();

    void on_sendButton_clicked();

    void keyPressEvent(QKeyEvent *event);

private:
    Ui::chat *ui;
    QTcpSocket *socket;
};

#endif // CHAT_H
