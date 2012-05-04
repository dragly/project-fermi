#ifndef GROUND_H
#define GROUND_H

#include "entity.h"

class Ground : public Entity
{
public:
    Ground(GameEngine *engine);
private:
    b2PolygonShape* polygonShape;
};

#endif // GROUND_H
