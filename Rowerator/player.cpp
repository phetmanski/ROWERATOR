#include "player.h"
#include "ui_player.h"

Player::Player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Player)
{
    ui->setupUi(this);
    play = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    //vsf = new QVideoSurfaceFormat(this);
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
    d_rate=1.0;
}

Player::~Player()
{
    delete ui;
    delete play;
    delete slider;
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
    play->pause();
    d_rate=1.0;
    play->setPlaybackRate(1.0);
    play->play();
    ui->statusbar->showMessage("Play");
}

void Player::on_actionPause_triggered()
{
    play->pause();
    play->setPlaybackRate(1.0);
    d_rate=1.0;
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

void Player::on_actionRewind_triggered()
{
    if(d_rate>0.30){
        d_rate=d_rate/2.0;
        play->setPlaybackRate(d_rate);
        QString str = QString("%L0").arg(d_rate,0,'f',2);
        ui->statusbar->showMessage("Rate x"+str+"\n");
    }
}

void Player::on_actionForward_triggered()
{
    if(d_rate<3){
        d_rate=d_rate*2.0;
        play->setPlaybackRate(d_rate);
        QString str = QString("%L0").arg(d_rate,0,'f',2);
        ui->statusbar->showMessage("Rate x"+str+"\n");
    }
}

void Player::on_spinBox_valueChanged(int arg1)
{


}
