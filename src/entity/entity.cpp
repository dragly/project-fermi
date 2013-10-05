#include "entity.h"

#include "../platform/platform.h"
#include "../gameengine/gameengine.h"

Entity::Entity(GameEngine *engine,
               const b2Vec2 &position,
               std::string spriteName,
               b2Shape * shape,
               double width,
               double heigth,
               bool dynamic) :
    m_engine(engine),
    m_world(engine->world()),
    m_platform(engine->platform()),
    m_bodyDef(new b2BodyDef),
    m_shape(shape),
    m_width(width),
    m_height(heigth)
{

    //Defaults to static (see Box2D/dynamics/b2Body.h)
    if (dynamic) {
        m_bodyDef->type = b2_dynamicBody;
    }

    m_bodyDef->position = position;

    m_body = m_world->CreateBody(m_bodyDef);

    m_sprite = m_platform->createSprite(spriteName);

}

void Entity::createFixtureFromProps(float32 density, float32 restitution, float32 friction)
{
    assert(m_shape!=NULL && "Shape not set prior to fixture.");

    b2FixtureDef *fixtureDef = new b2FixtureDef();
    fixtureDef->shape = m_shape;
    fixtureDef->density = density;
    fixtureDef->restitution = restitution;
    fixtureDef->friction = friction;

    m_body->CreateFixture(fixtureDef);
}
