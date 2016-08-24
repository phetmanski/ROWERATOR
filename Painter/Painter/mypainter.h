#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QtGui>
#include <QtCore>
#include <qmath.h>

class myPainter : public QLabel
{
    Q_OBJECT
public:
    explicit myPainter(QWidget *parent = 0);

    void canDraw_set(bool c);
    float length_get();
    float angle_get();

protected:
    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);

    void paintEvent(QPaintEvent *e);
private:
    float scale, length, angle;
    bool isScaled;
    int measType;
    bool canDraw;

    bool drawFlag[3];
    QPoint a,b,c;

    void measure_angle();
    void measure_length();

    void reset_view();

signals:
    void sendMousePosition(QPoint&);
    void sendDebugMsg(float,float);

public slots:
    void reciveMeasType(int);
    void reciveDebug_for();
    void reciveScale(QString);
};

#endif // MYPAINTER_H
