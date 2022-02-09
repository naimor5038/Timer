#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QLCDNumber>
#include <QTimer>
#include <QLineEdit>
#include <QRadioButton>

class MyWindow : public QWidget
{
    Q_OBJECT
private:
    QLCDNumber *lcd;
    QPushButton *btnStart;
    QTimer *timer;
    QPushButton *sb;
    QLineEdit *edt;
    QRadioButton *btnDown;
    QRadioButton *btnUp;
    int second;
public:
    explicit MyWindow(QWidget *parent = nullptr);

public slots:
    void time();
    void start();
    void sbros();
    void change(QString);
};

#endif // MYWINDOW_H
