#ifndef BOX_H
#define BOX_H

#include "entity.h"

class Box : public Entity
{
public:
    Box(GameEngine *gameEngine);
private:
    b2PolygonShape* polygonShape;
};

#endif // BOX_H
