#include "boxentity.h"

BoxEntity::BoxEntity(GameEngine *engine, const b2Vec2 &position, std::string spriteName, double width, double height, bool dynamic) :
    Entity(engine, position, spriteName, new b2PolygonShape, width, height, dynamic)
{
    ((b2PolygonShape*)m_shape)->SetAsBox(m_width / 2, m_height / 2);
}
