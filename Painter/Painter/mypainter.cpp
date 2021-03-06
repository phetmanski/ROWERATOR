#include "mypainter.h"

#define UNUSED(expr) do { (void)(expr); } while (0)

myPainter::myPainter(QWidget *parent) : QLabel(parent)
{
    this->scale = 0;
    //this->isScaled = false;
    this->measType = 0;
    this->canDraw = false;

    this->drawFlag[0] = false;
    this->drawFlag[1] = false;

    this->a.setX(-1);
    this->a.setY(-1);
    this->b.setX(-1);
    this->b.setY(-1);
}

void myPainter::canDraw_set(bool c)
{
    this->canDraw = c;
}

void myPainter::isImageLoaded_set(bool c)
{
    this->isImageLoaded = c;
}

void myPainter::len_set(QPoint a, QPoint b, int n)
{
    this->len[n][0] = a;
    this->len[n][1] = b;
}

void myPainter::measCalculate()
{
    for(int i = 0; i<8; ++i){
        this->length[i] = qSqrt( (this->len[i][0].x() - this->len[i][1].x()) *
                                 (this->len[i][0].x() - this->len[i][1].x()) +
                                 (this->len[i][0].y() - this->len[i][1].y()) *
                                 (this->len[i][0].y() - this->len[i][1].y())
                                );
        if(this->scale > 0 && i > 0){
            float tmp = this->length[i];
            this->length[i] = this->scale * tmp / this->length[0];
        }
    }
    if(this->scale > 0) this->length[0] = this->scale;

    //measure angles
    //HipAngle
    this->angle[0] = this->measure_angle(this->avergePointGen(this->len[1][1],this->len[2][0]), this->len[1][0], this->len[2][1]);
    //KneeAngle
    this->angle[1] = this->measure_angle(this->avergePointGen(this->len[2][1],this->len[3][0]), this->len[2][0], this->len[3][1]);
    //ElbowAngle
    this->angle[2] = this->measure_angle(this->avergePointGen(this->len[4][1],this->len[5][0]), this->len[4][0], this->len[5][1]);
    //CustomAngle
    this->angle[3] = this->measure_angle(this->avergePointGen(this->len[6][1],this->len[7][0]), this->len[6][0], this->len[7][1]);
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

    if (mouse_event->button() == Qt::LeftButton){
        if (!this->drawFlag[0]){
            this->a.setX(mouse_pos.x());
            this->a.setY(mouse_pos.y());
            //this->canDraw_set(false);
            this->drawFlag[0] = true;
        } else if (this->drawFlag[0] && !this->drawFlag[1]) {
            this->b.setX(mouse_pos.x());
            this->b.setY(mouse_pos.y());
            this->len_set(this->a,this->b,this->measType);
            for (int i=0; i<2; ++i) {
                this->drawFlag[i] = false;
            }
            this->canDraw_set(true);
        }
        this->update();
    }

    //this->measure_length();
    //this->measure_angle();
}

void myPainter::paintEvent(QPaintEvent *e)
{
    this->paintScaleEvent(e);
    this->paintBodyEvent(e);
    this->paintUperLegEvent(e);
    this->paintLowerLegEvent(e);
    this->paintUperArmEvent(e);
    this->paintLowerArmEvent(e);
    this->paintCustom1Event(e);
    this->paintCustom2Event(e);
}

void myPainter::paintScaleEvent(QPaintEvent *e)
{
    UNUSED(e);
    if (this->isImageLoaded && this->canDraw) {
        this->paintingActive();
        QPainter painter(this);
        QPen linepen(Qt::red);
        linepen.setWidth(3);
        painter.setPen(linepen);
        painter.drawLine(this->len[0][0],this->len[0][1]);
    }
    this->update();
}
void myPainter::paintBodyEvent(QPaintEvent *e)
{
    UNUSED(e);
    if (this->isImageLoaded && this->canDraw) {
        this->paintingActive();
        QPainter painter(this);
        QPen linepen(Qt::blue);
        linepen.setWidth(3);
        painter.setPen(linepen);
        painter.drawLine(this->len[1][0],this->len[1][1]);
    }
}
void myPainter::paintUperLegEvent(QPaintEvent *e)
{
    UNUSED(e);
    if (this->isImageLoaded && this->canDraw) {
        this->paintingActive();
        QPainter painter(this);
        QPen linepen(Qt::green);
        linepen.setWidth(3);
        painter.setPen(linepen);
        painter.drawLine(this->len[2][0],this->len[2][1]);
    }
}
void myPainter::paintLowerLegEvent(QPaintEvent *e)
{
    UNUSED(e);
    if (this->isImageLoaded && this->canDraw) {
        this->paintingActive();
        QPainter painter(this);
        QPen linepen(Qt::green);
        linepen.setWidth(3);
        painter.setPen(linepen);
        painter.drawLine(this->len[3][0],this->len[3][1]);
    }
}
void myPainter::paintUperArmEvent(QPaintEvent *e)
{
    UNUSED(e);
    if (this->isImageLoaded && this->canDraw) {
        this->paintingActive();
        QPainter painter(this);
        QPen linepen(Qt::yellow);
        linepen.setWidth(3);
        painter.setPen(linepen);
        painter.drawLine(this->len[4][0],this->len[4][1]);
    }
}
void myPainter::paintLowerArmEvent(QPaintEvent *e)
{
    UNUSED(e);
    if (this->isImageLoaded && this->canDraw) {
        this->paintingActive();
        QPainter painter(this);
        QPen linepen(Qt::yellow);
        linepen.setWidth(3);
        painter.setPen(linepen);
        painter.drawLine(this->len[5][0],this->len[5][1]);
    }
}
void myPainter::paintCustom1Event(QPaintEvent *e)
{
    UNUSED(e);
    if (this->isImageLoaded && this->canDraw) {
        this->paintingActive();
        QPainter painter(this);
        QPen linepen(Qt::black);
        linepen.setWidth(3);
        painter.setPen(linepen);
        painter.drawLine(this->len[6][0],this->len[6][1]);
    }
}
void myPainter::paintCustom2Event(QPaintEvent *e)
{
    UNUSED(e);
    if (this->isImageLoaded && this->canDraw) {
        this->paintingActive();
        QPainter painter(this);
        QPen linepen(Qt::black);
        linepen.setWidth(3);
        painter.setPen(linepen);
        painter.drawLine(this->len[7][0],this->len[7][1]);
    }
}

QPoint myPainter::avergePointGen(QPoint a, QPoint b)
{
    QPoint result;
    result.setX((int)((a.x()+b.x())/2));
    result.setY((int)((a.y()+b.y())/2));

    return result;
}

qreal myPainter::measure_angle(QPoint a, QPoint b, QPoint c)
{
    qreal result;
    float AB,AC,BC;
    // from cosinus theorem
    // c2 = a2 + b2 - 2ab cos(DIR) , so
    // DIR = arcos( (a2 + b2 - c2) / 2ab )
    AB = qSqrt( (a.x() - b.x()) *
                    (a.x() - b.x()) +
                    (a.y() - b.y()) *
                    (a.y() - b.y()) );
    AC = qSqrt( (a.x() - c.x()) *
                    (a.x() - c.x()) +
                    (a.y() - c.y()) *
                    (a.y() - c.y()) );
    BC = qSqrt( (c.x() - b.x()) *
                    (c.x() - b.x()) +
                    (c.y() - b.y()) *
                    (c.y() - b.y()) );
    result = qAcos(((AB*AB)+(AC*AC)-(BC*BC))/(2*AB*AC)) * 180 / 3.1415;

    return result;
}

void myPainter::reset_view()
{
    this->drawFlag[0] = false;
    this->drawFlag[1] = false;
    for(int i = 0; i< 8; ++i){
        for(int j=0; j<2; ++j){
            this->len[i][j].setX(-1);
            this->len[i][j].setY(-1);
        }
    }
}

void myPainter::reciveSaveTriger()
{
    this->xmlGen.set(this->length,this->angle);

    QString fName = "";
    fName += this->fileName + ".xml";
    QFile fileName(fName);
    fileName.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&fileName);

    out<<this->xmlGen.generate()<<endl;
    fileName.close();
}

void myPainter::reciveMeasType(int index)
{
    this->measType = index;
    this->update();
}

//void myPainter::reciveDebug_for()
//{
//   // emit this->sendDebugMsg(this->length,this->angle);
//}

void myPainter::reciveScale(QString s)
{
    this->scale = s.toDouble();
}

void myPainter::reciveFileName(QString s)
{
    this->fileName = s;
}

void myPainter::reciveCalcTriger()
{
    this->measCalculate();
}
