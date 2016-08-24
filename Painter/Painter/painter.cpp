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

void Painter::on_fileOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
            tr("Open Images"), "", tr("Image Files (*.png *.jpeg *.jpg *.gif *.bmp *.PNG"));
    if (QString::compare(filename, QString()) != 0) {
        QImage image;
        bool valid = image.load(filename);

        if (valid) {
            image = image.scaledToHeight(ui->imgView->height(), Qt::SmoothTransformation);
            ui->imgView->setPixmap(QPixmap::fromImage(image));
        } else {
            //error handling
        }
    }
}
