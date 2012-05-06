#include "ball.h"

#include "platform/platform.h"

Ball::Ball(GameEngine *engine) :
    Entity(engine)
{
    m_bodyDef = new b2BodyDef();
    m_bodyDef->type = b2_dynamicBody;
    m_bodyDef->position.Set(4, 20);
    m_bodyDef->linearVelocity.y = 5;
    m_bodyDef->linearVelocity.x = 1;
    m_body = world->CreateBody(m_bodyDef);
    shape = new b2CircleShape();
    m_height = m_width = 3;
    shape->m_radius = m_height / 2;

    b2FixtureDef *fixtureDef = new b2FixtureDef();
    fixtureDef->shape = shape;
    fixtureDef->density = 1.0f;
    fixtureDef->restitution = 0.4f;
    fixtureDef->friction = 0.3f;

    m_body->CreateFixture(fixtureDef);
    m_sprite = platform->createSprite("ball.png"); // TODO create real sprites
}
