#ifndef BOX_H
#define BOX_H

#include "entity.h"

class BoxEntity : public Entity
{
protected:
    BoxEntity(GameEngine *gameEngine, const b2Vec2 &position,
              std::string spriteName = ENTITY_DEFAULT_SPRITE,
              double width = ENTITY_NO_SIZE,
              double height = ENTITY_NO_SIZE,
              bool dynamic = true);
};

#endif // BOX_H
