#include "mytimer.h"

MyTimer::MyTimer(MainWindow *win)
{
    janela = win;

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),SLOT(mySlots()));

    timer->start(100);
}

void MyTimer::mySlots(){
    for(int i=0;i<100;++i)
        janela->uppontos();
    janela->repaint();
    qDebug() << "Timer executed!";
}
