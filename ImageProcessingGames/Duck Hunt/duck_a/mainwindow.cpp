#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



/*
QSound bells1("E:\\qtsound.wav");

//QSound::play("mysounds/D:\\qtsound.wav");


void MainWindow::on_pushButton_clicked()
{

 //bells1.play();



}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    //bells.play();

}


*/


