#include "ground.h"

#include "platform/platform.h"

Ground::Ground(GameEngine *engine) :
    Entity(engine)
{
    m_bodyDef = new b2BodyDef();
    m_bodyDef->position.Set(0, 10);
    m_body = world->CreateBody(m_bodyDef);
    polygonShape = new b2PolygonShape();
    shape = polygonShape;
    m_width = 10;
    m_height = 10;
    polygonShape->SetAsBox(m_width / 2, m_height / 2);
    m_body->CreateFixture(shape, 0.0);

    m_sprite = platform->createSprite("box.png"); // TODO create real sprites
}
