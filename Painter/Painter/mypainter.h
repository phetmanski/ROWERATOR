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
    void isImageLoaded_set(bool c);

    void len_set(QPoint a, QPoint b, int n);
    void measCalculate();

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
    float scale;
    //bool isScaled;
    bool canDraw;
    bool isImageLoaded;
    bool drawFlag[2];
    QPoint a,b;
    QPoint len[8][2];
    float length[8];
    int measType;

    //void measure_angle();
    //void measure_length();



signals:
    void sendMousePosition(QPoint&);
    //void sendDebugMsg(float,float);

public slots:
    void reciveMeasType(int);
    //void reciveDebug_for();
    void reciveScale(QString);
    void reciveCalcTriger();
    void reset_view();
    void reciveSaveTriger();
};

#endif // MYPAINTER_H
