#ifndef GROUND_H
#define GROUND_H

#include "boxentity.h"

class Ground : public BoxEntity
{
public:
    Ground(GameEngine *m_engine, const b2Vec2 &position, double width, double height);
};

#endif // GROUND_H
