#include "painter.h"
#include "ui_painter.h"

Painter::Painter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Painter)
{
    ui->setupUi(this);
}

Painter::~Painter()
{
    delete ui;
}
