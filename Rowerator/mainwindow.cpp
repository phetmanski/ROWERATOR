#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"

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

void MainWindow::on_pushButton_2_clicked()
{
    Player * myPlayer = new Player;
    myPlayer->show();
}

void MainWindow::on_pushButton_clicked()
{

}
