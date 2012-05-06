#include "ground.h"

#include "platform/platform.h"

Ground::Ground(GameEngine *engine) :
    Entity(engine)
{
    bodyDef = new b2BodyDef();
    bodyDef->position.Set(0, 5);
    m_body = world->CreateBody(bodyDef);
    polygonShape = new b2PolygonShape();
    shape = polygonShape;
    m_width = 50;
    m_height = 10;
    polygonShape->SetAsBox(m_width, m_height);
    m_body->CreateFixture(shape, 0.0);

    m_sprite = platform->createSprite("..."); // TODO create real sprites
}
