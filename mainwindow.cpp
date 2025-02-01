#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "vehiclewindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    vehiclewindow = new VehicleWindow(this);
    vehiclewindow->show();
    vehiclewindow->setAttribute(Qt::WA_DeleteOnClose);
}

