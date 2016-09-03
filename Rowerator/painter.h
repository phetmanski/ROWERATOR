#ifndef PAINTER_H
#define PAINTER_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Painter;
}

class Painter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Painter(QWidget *parent = 0);
    ~Painter();

signals:
    void sendMeasureType(int);
    //void sendDebug_for();
    void sendScale(QString);
    //void sendFileName(QString);
    void sendCalcTriger();
    void sendResetSig();
    void sendSaveTriger();

//public slots:
    //void show_debug(float,float);

private slots:
    void on_fileOpen_triggered();

    void on_comboBox_currentIndexChanged(int index);

    void on_calcButton_clicked();

    void on_genericButt_clicked();

private:
    Ui::Painter *ui;
};

#endif // PAINTER_H
