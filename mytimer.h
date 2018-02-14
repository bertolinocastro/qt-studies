#ifndef MYTIMER_H
#define MYTIMER_H

#include <QObject>
#include <QtCore>
#include "mainwindow.h"

class MyTimer : public QObject
{
    Q_OBJECT

public:
    MyTimer(MainWindow *win);

    QTimer *timer;

    MainWindow *janela;

public slots:
    void mySlots();

};

#endif // MYTIMER_H
