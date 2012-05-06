#ifndef BOX_H
#define BOX_H

#include "entity.h"

class Box : public Entity
{
public:
    Box(GameEngine *gameEngine, const b2Vec2 &position, double width, double height);
private:
    b2PolygonShape* polygonShape;
};

#endif // BOX_H
