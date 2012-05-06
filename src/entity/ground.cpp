#include "ground.h"

#include "platform/platform.h"

Ground::Ground(GameEngine *engine, const b2Vec2 &position, double width, double height) :
    Entity(engine)
{
    m_bodyDef = new b2BodyDef();
    m_bodyDef->position = position;
    m_body = m_world->CreateBody(m_bodyDef);
    m_polygonShape = new b2PolygonShape();
    m_shape = m_polygonShape;
    m_width = width;
    m_height = height;
    m_polygonShape->SetAsBox(m_width / 2, m_height / 2);
    m_body->CreateFixture(m_shape, 0.0);

    m_sprite = m_platform->createSprite("box.png"); // TODO create real sprites
}
