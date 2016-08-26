#include "cyclist.h"

Cyclist::Cyclist()
{

}

Cyclist::~Cyclist()
{

}

void Cyclist::len_set(QPoint a, QPoint b, int n)
{
    this->len[n][0] = a;
    this->len[n][1] = b;
}

void Cyclist::dir_set(float a, int n)
{
    this->dir[n] = a;
}
