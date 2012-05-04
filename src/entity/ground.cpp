#include "ground.h"

#include "platform/platform.h"

Ground::Ground(GameEngine *engine) :
    Entity(engine)
{
    bodyDef = new b2BodyDef();
    bodyDef->position.Set(0, -40);
    m_body = world->CreateBody(bodyDef);
    polygonShape = new b2PolygonShape();
    shape = polygonShape;
    polygonShape->SetAsBox(50, 10);
    m_body->CreateFixture(shape, 0.0);

    m_sprite = platform->createSprite("..."); // TODO create real sprites
}
