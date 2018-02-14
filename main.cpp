#include "mainwindow.h"
#include <QApplication>
#include "mytimer.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    MyTimer timer(&w);

    int iz = 0;
    //for (int i = 0; i < ITER; ++i){
        //w.uppontos(iz);
        //QThread::msleep(100);
        //w.update();
        //w.repaint();
        //iz = 1-iz;

        //qDebug() << "iterou";;
    //}
    qDebug() << "Finish";
    //w.show();

    return a.exec();
}
