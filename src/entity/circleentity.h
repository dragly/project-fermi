#ifndef CIRCLEENTITY_H
#define CIRCLEENTITY_H

#include "entity.h"

class circleEntity : public Entity
{
protected:
    circleEntity(GameEngine *engine,
                 const b2Vec2 &position,
                 double radius = ENTITY_NO_SIZE,
                 std::string spriteName = ENTITY_DEFAULT_SPRITE,
                 bool dynamic = true);
};

#endif // CIRCLEENTITY_H
