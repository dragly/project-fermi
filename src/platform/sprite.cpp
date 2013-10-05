#include "sprite.h"

Sprite::Sprite() :
    ID(staticID++)
{

}

unsigned int Sprite::staticID = 0;
