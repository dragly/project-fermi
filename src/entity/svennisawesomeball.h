#ifndef SVENNISAWESOMEBALL_H
#define SVENNISAWESOMEBALL_H

#include "circleentity.h"

class SvennisAwesomeBall : public circleEntity
{
public:
    SvennisAwesomeBall(GameEngine *gameEngine, const b2Vec2 &position, double radius);
};

#endif // SVENNISAWESOMEBALL_H
