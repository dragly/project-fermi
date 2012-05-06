#include "box.h"

#include "platform/platform.h"

Box::Box(GameEngine *engine, const b2Vec2 &position, double width, double height) :
    Entity(engine)
{
    m_bodyDef = new b2BodyDef();
    m_bodyDef->type = b2_dynamicBody;
    m_bodyDef->position = position;
    m_body = m_world->CreateBody(m_bodyDef);

    polygonShape = new b2PolygonShape();
    m_width = width;
    m_height = height;
    polygonShape->SetAsBox(m_width / 2, m_height / 2);
    m_shape = polygonShape;

    b2FixtureDef *fixtureDef = new b2FixtureDef();
    fixtureDef->shape = m_shape;
    fixtureDef->density = 1.0f;
    fixtureDef->restitution = 0.4f;
    fixtureDef->friction = 0.3f;

    m_body->CreateFixture(fixtureDef);
    m_body->SetAngularVelocity(0.1);
    m_sprite = m_platform->createSprite("box.png"); // TODO create real sprites
}
