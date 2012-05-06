#include "box.h"

#include "platform/platform.h"

Box::Box(GameEngine *engine) :
    Entity(engine)
{
    bodyDef = new b2BodyDef();
    bodyDef->type = b2_dynamicBody;
    bodyDef->position.Set(0, 20);
    bodyDef->linearVelocity.y = 5;
    bodyDef->linearVelocity.x = 10;
    m_body = world->CreateBody(bodyDef);

    polygonShape = new b2PolygonShape();
    shape = polygonShape;
    m_width = 2;
    m_height = 2;
    polygonShape->SetAsBox(m_width, m_height);

    b2FixtureDef *fixtureDef = new b2FixtureDef();
    fixtureDef->shape = shape;
    fixtureDef->density = 1.0f;
    fixtureDef->restitution = 0.4f;
    fixtureDef->friction = 0.3f;

    m_body->CreateFixture(fixtureDef);
    m_body->SetAngularVelocity(0.1);
    m_sprite = platform->createSprite("..."); // TODO create real sprites
}
