#include "box.h"

#include "platform/platform.h"

Box::Box(GameEngine *engine) :
    Entity(engine)
{
    m_bodyDef = new b2BodyDef();
    m_bodyDef->type = b2_dynamicBody;
    m_bodyDef->position.Set(0, 20);
    m_bodyDef->linearVelocity.y = 5;
    m_bodyDef->linearVelocity.x = 4;
    m_body = world->CreateBody(m_bodyDef);

    polygonShape = new b2PolygonShape();
    m_width = 4;
    m_height = 4;
    polygonShape->SetAsBox(m_width / 2, m_height / 2);
    shape = polygonShape;

    b2FixtureDef *fixtureDef = new b2FixtureDef();
    fixtureDef->shape = shape;
    fixtureDef->density = 1.0f;
    fixtureDef->restitution = 0.4f;
    fixtureDef->friction = 0.3f;

    m_body->CreateFixture(fixtureDef);
    m_body->SetAngularVelocity(0.1);
    m_sprite = platform->createSprite("box.png"); // TODO create real sprites
}
