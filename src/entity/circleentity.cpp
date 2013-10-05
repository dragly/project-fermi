#include "circleentity.h"

circleEntity::circleEntity(GameEngine *engine,
                           const b2Vec2 &position,
                           double radius,
                           std::string spriteName,
                           bool dynamic) :
    Entity(engine, position, spriteName, new b2CircleShape, radius*2, radius*2, dynamic)
{
    m_shape->m_radius = radius;

}
