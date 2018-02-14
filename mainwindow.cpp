#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QPalette pal(QPalette::Background, Qt::black);
    this->setPalette(pal);
    ui->setupUi(this);

    //scene = new QGraphicsScene(this);
    //ui->graphicsView->setScene(scene);
    //scene->setSceneRect(0,0,width(),height());
//    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    inipontos();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    qint32 pointSize = std::min(
                this->width()/X,
                this->height()/Y
                ); // px

    QPen pen;
    pen.setWidth(pointSize);
    painter.setPen(pen);

    QPoint point;
    QColor color;

    qint32 width = this->width()-pointSize;
    qint32 height = this->height()-pointSize;
    qreal deltax = (qreal)width/(X-1);
    qreal deltay = (qreal)height/(Y-1);

    //float max = *std::max_element(&pontos[0][0],&pontos[length][length]);
    //qDebug() << "max" << max_pontos;


    for(int i = 0; i < X; ++i){
        for(int j = 0; j < Y; ++j){

            qreal val = pontos[i][j][0];
            qreal value;

            point.setX((qreal)(pointSize/2.0f+i*deltax));
            point.setY((qreal)(pointSize/2.0f+j*deltay));

            //float percent = (float)qrand()/RAND_MAX;

            //qDebug() << percent*255.0f << " " << val;
            //qDebug() << (qreal)val/max_pontos*255.0f << " " << val;

            value = val/max_pontos;
            if(value>1.0)
                value=1.0f;
            else if(value < 0.0)
                value=0.0f;
            //color.setRgb(percent*255, percent*255, percent*255);
            color.setRgbF(value, value, value);
            pen.setColor(color);

            painter.setPen(pen);
            painter.drawPoint(point);
        }
    }

}
/*
void MainWindow::initPontos(){
    float max = 0;
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j){
            pontos[i][j] = i*j;
            max = pontos[i][j] > max ? pontos[i][j] : max;
            //qDebug() << pontos[i][j] << " ";
        }

    max_pontos = max;
}*/

// -----
/*
void MainWindow::inipontos(){
    int ix, iy; qreal max = 0.0f;
    for (ix = 0; ix < nx; ix++) {
        for (iy = 1; iy < ny; iy++) {
            pontos[ix][iy][0] = 0.0f;
        }
    }
    for (ix = 0; ix < nx; ix++) {
        pontos[ix][0][0] = 100.0f;
    }
    max = 100.0f > max ? 100.0f : max;
    max_pontos = max;
}*/

void MainWindow::inipontos(){
    int ix, iy; qreal max = 0.0f;
    for (ix = 0; ix < nx; ix++) {
        for (iy = 0; iy < ny; iy++) {
            pontos[ix][iy][0] = (qreal)(ix*(nx-ix-1.0f))*(qreal)(iy*(ny-iy-1.0f));
            max = pontos[ix][iy][0] > max ? pontos[ix][iy][0] : max;
            //*(u1+ix*ny+iy) = (float)(ix * (nx - ix - 1) * iy * (ny - iy - 1));
            //if(pontos[ix][iy][0] < 0)
            //    qDebug() << "Valor negativo " << pontos[ix][iy][0];
        }
    }
    for (ix = 0; ix < nx; ix++) {
        pontos[ix][0][0] = 100.0f;
        //*(u1+ix*ny) =  100.0;
    }
    max = 100.0f > max ? 100.0f : max;
    max_pontos = max;
}

void MainWindow::uppontos(){
    int ix, iy;

    for (ix = 1; ix < nx-1; ix++) {
        for (iy = 1; iy < ny-1; iy++) {
            pontos[ix][iy][1-iz] = pontos[ix][iy][iz] +
                CX * (pontos[ix+1][iy][iz] + pontos[ix-1][iy][iz] - 2.0*pontos[ix][iy][iz]) +
                CY * (pontos[ix][iy+1][iz] + pontos[ix][iy-1][iz] - 2.0*pontos[ix][iy][iz]);

            /**(u2+ix*ny+iy) = *(u1+ix*ny+iy) +
                CX * (*(u1+(ix+1)*ny+iy) + *(u1+(ix-1)*ny+iy) - 2.0 * *(u1+ix*ny+iy)) +
                CY * (*(u1+ix*ny+iy+1) + *(u1+ix*ny+iy-1) - 2.0 * *(u1+ix*ny+iy));*/
        }
    }

    iz = 1 - iz;
}
