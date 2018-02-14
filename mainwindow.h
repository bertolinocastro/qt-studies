#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGui>
#include <QDebug>
#include <algorithm>

#define CX 0.000000002
#define CY 0.000000002

#define X 500
#define Y 500
#define ITER 500000000
//#define X 10
//#define Y 10
//#define ITER 10

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //std::array<std::array<std::array<qreal, X>, Y>, 2> pontos; // Utilização de std::array estava gerando enormes problemas.
    qreal pontos[X][Y][2];
    int nx = X;
    int ny = Y;
    //float pontos[10][10];
    qreal max_pontos;

    //void initPontos(void);

    int iz = 0;

    void inipontos();
    void uppontos();
    //void prtdat(int, int, double *, char *);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
