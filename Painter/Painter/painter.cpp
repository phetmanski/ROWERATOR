#include "painter.h"
#include "ui_painter.h"

Painter::Painter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Painter)
{
    ui->setupUi(this);

    connect(this,SIGNAL(sendMeasureType(int)),ui->display,SLOT(reciveMeasType(int)));
    //connect(this,SIGNAL(sendDebug_for()),ui->display,SLOT(reciveDebug_for()));
    connect(this,SIGNAL(sendScale(QString)),ui->display,SLOT(reciveScale(QString)));
    //connect(ui->display,SIGNAL(sendDebugMsg(float,float)),this,SLOT(show_debug(float,float)));
    connect(this,SIGNAL(sendCalcTriger()),ui->display,SLOT(reciveCalcTriger()));
    connect(this,SIGNAL(sendResetSig()),ui->display,SLOT(reset_view()));
    connect(this,SIGNAL(sendSaveTriger()),ui->display,SLOT(reciveSaveTriger()));
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
            emit this->sendResetSig();
            ui->display->isImageLoaded_set(true);
        } else {
            //error handling
        }
    }
}
void Painter::on_button_scale_clicked()
{
    //emit this->sendScale(ui->scaleLable->text());
    //ui->debug->setText("scale: "+ui->scaleLable->text());
}

//void Painter::show_debug(float a, float b)
//{
//    ui->debug->setText("val: "+QString::number(this->measVal));
//}

void Painter::on_comboBox_currentIndexChanged(int index)
{
    emit this->sendMeasureType(index);
}

void Painter::on_calcButton_clicked()
{
    emit this->sendScale(ui->scaleEdit->text());
    emit this->sendCalcTriger();
}

void Painter::on_genericButt_clicked()
{
    if(true){
        emit this->sendSaveTriger();
    }
}
