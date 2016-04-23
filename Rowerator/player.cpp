#include "player.h"
#include "ui_player.h"

Player::Player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Player)
{
    ui->setupUi(this);
    play = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    play->setVideoOutput(vw);
    this->setCentralWidget(vw);
    slider= new QSlider(this);
    //Ustawienie orientacji Slidera
    slider->setOrientation(Qt::Horizontal);
    //dodanie widegetu slider
    ui->statusbar->addPermanentWidget(slider);

    //połączenie odtwarzania filmu z sliderem
    //dostosowanie długości slidera
    connect(play,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    //przewijanie slidera
    connect(play,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);

    //włączenie możliwości przewijania sliderem
    connect(slider,&QSlider::sliderMoved,play,&QMediaPlayer::setPosition);
}

Player::~Player()
{
    delete ui;
}

void Player::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Otworz Plik","","Video File (*.avi;*.mpg;*.mp4)");
    //zatrzymanie filmu
    on_actionStop_triggered();

    play->setMedia(QUrl::fromLocalFile(filename));
    //po uruchomieniu automatycznie zaczyna odtwarzać film
    on_actionPlay_triggered();
}

void Player::on_actionPlay_triggered()
{
    play->play();
    ui->statusbar->showMessage("Play");
}

void Player::on_actionPause_triggered()
{
    play->pause();
    ui->statusbar->showMessage("Pause");
}

void Player::on_actionStop_triggered()
{
    play->stop();
    ui->statusbar->showMessage("Stop");
}

void Player::on_actionScreenshot_triggered()
{
    play->pause();
    QString saveFilename = QFileDialog::getSaveFileName(this, "Save as", "Choose a filename", "PNG(*.png);; BMP(*.bmp);; JPEG(*.jpg *.jpeg)");
    QString saveExtension = "PNG";
    int pos = saveFilename.lastIndexOf('.');
    if (pos >= 0)
        saveExtension = saveFilename.mid(pos + 1);
    play->play();
    play->pause();
    if(!QPixmap::grabWindow(vw->winId()).save(saveFilename))
    {
        QMessageBox::warning(this, "File could not be saved", "ok", QMessageBox::Ok);
    }
}
