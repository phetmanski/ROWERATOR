#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QSlider>
#include <QImage>
#include <QVideoFrame>
#include <QImage>
#include <QPixmap>

namespace Ui {
class Player;
}

class Player : public QMainWindow
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = 0);
    ~Player();

private slots:
    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

    void on_actionScreenshot_triggered();
//    void capture_video(const QVideoFrame &frame);
private:
    Ui::Player *ui;
    QMediaPlayer *play;
    QVideoWidget *vw;
    QSlider *slider;
    QVideoFrame *video_frame;
};

#endif // PLAYER_H
