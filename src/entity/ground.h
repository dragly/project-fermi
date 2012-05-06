#ifndef GROUND_H
#define GROUND_H

#include "entity.h"

class Ground : public Entity
{
public:
    Ground(GameEngine *m_engine, const b2Vec2 &position, double width, double height);
private:
    b2PolygonShape* m_polygonShape;
};

#endif // GROUND_H
