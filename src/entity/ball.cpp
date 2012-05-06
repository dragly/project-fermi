#include "ball.h"

#include "platform/platform.h"

Ball::Ball(GameEngine *engine, const b2Vec2 &position, double radius) :
    Entity(engine)
{
    m_bodyDef = new b2BodyDef();
    m_bodyDef->type = b2_dynamicBody;
    m_bodyDef->position = position;
    m_body = m_world->CreateBody(m_bodyDef);
    m_shape = new b2CircleShape();
    m_height = m_width = radius * 2;
    m_shape->m_radius = radius;

    b2FixtureDef *fixtureDef = new b2FixtureDef();
    fixtureDef->shape = m_shape;
    fixtureDef->density = 1.0f;
    fixtureDef->restitution = 0.4f;
    fixtureDef->friction = 0.3f;

    m_body->CreateFixture(fixtureDef);
    m_sprite = m_platform->createSprite("ball.png"); // TODO create real sprites
}
