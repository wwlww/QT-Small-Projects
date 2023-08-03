#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(QTcpSocket *s);
    void run();
    void clienInfoSlot();
signals:
    void sendToWidget(QByteArray b);
private:
    QTcpSocket *socket;

};

#endif // MYTHREAD_H
