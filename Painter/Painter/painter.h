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

private:
    Ui::Painter *ui;

private slots:
    void on_fileOpen_triggered();
};

#endif // PAINTER_H
