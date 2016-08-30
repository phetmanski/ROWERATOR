#ifndef XMLGENERATOR_H
#define XMLGENERATOR_H

#include <QString>
#include <qmath.h>

class XmlGenerator
{
public:
    XmlGenerator();

    ~XmlGenerator();
    void set(float *l,qreal *qr);
    QString generate();
private:
    float length[8];
    qreal angle[4];
};

#endif // XMLGENERATOR_H
