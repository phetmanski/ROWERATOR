#ifndef CYCLIST_H
#define CYCLIST_H

#include <QPoint>

class Cyclist
{
public:
    Cyclist();
    ~Cyclist();

    void len_set(QPoint a, QPoint b, int n);
    void dir_set(float a, int n);
private:
    QPoint len[7][2];
    float dir[4];

};

#endif // CYCLIST_H
