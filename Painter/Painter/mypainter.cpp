#include "mypainter.h"

myPainter::myPainter(QWidget *parent) : QLabel(parent)
{
    this->scale = 0;
    this->isScaled = false;
    this->measType = 0;
    this->canDraw = false;

    this->drawFlag[0] = false;
    this->drawFlag[1] = false;
    this->drawFlag[2] = false;

    this->a.setX(-1);
    this->a.setY(-1);
    this->b.setX(-1);
    this->b.setY(-1);
    this->c.setX(-1);
    this->c.setY(-1);
}

void myPainter::canDraw_set(bool c)
{
    this->canDraw = c;
}

float myPainter::length_get()
{
    return this->length;
}

float myPainter::angle_get()
{
    return this->angle;
}

void myPainter::mouseMoveEvent(QMouseEvent *mouse_event)
{
    QPoint mouse_pos = mouse_event->pos();

    if (mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height()) {
        if (mouse_pos.x() > 0 && mouse_pos.y() > 0) {
            emit sendMousePosition(mouse_pos);
        }
    }
}

void myPainter::mousePressEvent(QMouseEvent *mouse_event)
{
    QPoint mouse_pos = mouse_event->pos();

    //emit sendScaleValues(mouse_pos);
    if (this->measType == 0) {
        if (mouse_event->button() == Qt::LeftButton){
            if (!this->drawFlag[0]){
                this->a.setX(mouse_pos.x());
                this->a.setY(mouse_pos.y());
                this->drawFlag[0] = true;
            } else if (this->drawFlag[0] && !this->drawFlag[1]) {
                this->b.setX(mouse_pos.x());
                this->b.setY(mouse_pos.y());

                for (int i=0; i<3; ++i) {
                    this->drawFlag[i] = false;
                }
            }
            this->update();
        }
    } else if (this->measType == 1) {
        if (mouse_event->button() == Qt::LeftButton){
            if (!this->drawFlag[0]){
                this->a.setX(mouse_pos.x());
                this->a.setY(mouse_pos.y());
                this->drawFlag[0] = true;
            } else if (this->drawFlag[0] && !this->drawFlag[1]) {
                this->b.setX(mouse_pos.x());
                this->b.setY(mouse_pos.y());
                this->drawFlag[1] = true;
            } else if (this->drawFlag[0] && this->drawFlag[1] && !this->drawFlag[2]) {
                this->c.setX(mouse_pos.x());
                this->c.setY(mouse_pos.y());

                for (int i=0; i<3; ++i) {
                    this->drawFlag[i] = false;
                }
            }
            this->update();
        }
    }
    this->measure_length();
    this->measure_angle();
}

void myPainter::paintEvent(QPaintEvent *e)
{
    if (this->canDraw) {
        this->paintingActive();
        QPainter painter(this);
        QPen linepen(Qt::red);
        linepen.setWidth(2);
        painter.setPen(linepen);
        painter.drawLine(this->a,this->b);
        if (this->measType == 1)
            painter.drawLine(this->b,this->c);
    }
}

void myPainter::measure_angle()
{
    float A,B,C,P;
    A = (qSqrt(qAbs(this->a.x() - this->b.x())+qAbs(this->a.y() - this->b.y())));
    B = (qSqrt(qAbs(this->c.x() - this->b.x())+qAbs(this->c.y() - this->b.y())));
    C = (qSqrt(qAbs(this->a.x() - this->c.x())+qAbs(this->a.y() - this->c.y())));

    P = qAcos((C*C-(A*A)-(B*B))/(-2*A*B)) * 180 / 3.1415;
    if (P > 90) P = 270 - P;
    this->angle = P;
}

void myPainter::measure_length()
{
    this->length = (qSqrt(qAbs(this->a.x() - this->b.x())+qAbs(this->a.y() - this->b.y())));
}

void myPainter::reset_view()
{
    this->canDraw = false;

    this->drawFlag[0] = false;
    this->drawFlag[1] = false;
    this->drawFlag[2] = false;

    this->a.setX(-1);
    this->a.setY(-1);
    this->b.setX(-1);
    this->b.setY(-1);
    this->c.setX(-1);
    this->c.setY(-1);
}

void myPainter::reciveMeasType(int s)
{
    this->measType = s;
}

void myPainter::reciveDebug_for()
{
    emit this->sendDebugMsg(this->length,this->angle);
}

void myPainter::reciveScale(QString s)
{
    this->measure_length();
    this->scale = s.toDouble() / this->length;
}
