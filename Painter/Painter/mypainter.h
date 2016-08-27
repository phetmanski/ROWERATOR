#ifndef MYPAINTER_H
#define MYPAINTER_H

//#include "cyclist.h"
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
    void isImageLoaded_set(bool c);

    float length_get();
    float angle_get();

    void len_set(QPoint a, QPoint b, int n);

protected:
    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);

    void paintEvent(QPaintEvent *e);

    void paintScaleEvent(QPaintEvent *e);
    void paintBodyEvent(QPaintEvent *e);
    void paintUperLegEvent(QPaintEvent *e);
    void paintLowerLegEvent(QPaintEvent *e);
    void paintUperArmEvent(QPaintEvent *e);
    void paintLowerArmEvent(QPaintEvent *e);
    void paintCustom1Event(QPaintEvent *e);
    void paintCustom2Event(QPaintEvent *e);

private:
    float scale, length, angle;
    bool isScaled;
    bool canDraw;
    bool isImageLoaded;
    bool drawFlag[2];
    QPoint a,b;
    QPoint len[8][2];
    int measType;

    //Cyclist *myCyclist;

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
