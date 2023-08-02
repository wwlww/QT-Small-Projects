#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>

#define TIMEOUT 1 * 1000

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    virtual void timerEvent(QTimerEvent *event);

private slots:
    //开始按钮
    void on_startButton_clicked();

    //暂停按钮
    void on_stopButton_clicked();

private:
    Ui::Widget *ui;
    int myTimerId;
    int picId;
};
#endif // WIDGET_H
