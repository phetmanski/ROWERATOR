#include "cyclist.h"

Cyclist::Cyclist()
{
    for(int i=0;i<7;++i){
        this->len[i]=-1;
        if(i<4)
            this->dir[i]=-1;
    }

}

Cyclist::~Cyclist()
{

}
