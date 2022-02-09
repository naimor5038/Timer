#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent) : QWidget(parent)
{
this->setGeometry(100,100, 300,500);

edt = new QLineEdit(this);
edt-> setGeometry(100,0,100, 20);

lcd = new QLCDNumber(this);
lcd->setGeometry(100,30, 100,40);

btnStart = new QPushButton(this);
btnStart-> setGeometry(100,100, 100, 30);
btnStart-> setText("старт");

sb = new QPushButton(this);
sb-> setGeometry(100,150, 100, 30);
sb-> setText("сброс");

btnUp = new QRadioButton(this);
btnUp->setGeometry(10, 300, 200, 30);
btnUp->setText("прямой");
btnUp->setChecked(true);

btnDown = new QRadioButton(this);
btnDown->setGeometry(200, 300, 200, 30);
btnDown->setText("обратный");

timer = new QTimer(this);
timer-> setInterval(1000);

second = 0;

connect(timer, SIGNAL(timeout()),this,SLOT(time()));
connect(btnStart, SIGNAL(pressed()),this,SLOT(start()));
connect(sb, SIGNAL(pressed()),this,SLOT(sbros()));
connect(edt,SIGNAL(textEdited(QString)),this,SLOT(change(QString)));
}

void MyWindow::time(){
    if (btnUp->isChecked()){
        second++;
    } else{
        second--;
    }

    lcd-> display(second);
}

void MyWindow::start(){
    if(timer->isActive()){
        timer->stop();
        btnStart->setText("старт");
    }else{
    timer-> start();
    btnStart->setText("стоп");
    }
}
void MyWindow::sbros(){
    timer->stop();
    second = this->edt->text().toInt();
    lcd-> display(second);
    btnStart->setText("Старт");
}
void MyWindow::change(QString newText){
    timer->stop();
    btnStart->setText("Старт");

    second = newText.toInt();
    lcd->display(second);

}
