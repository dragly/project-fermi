#ifndef ENTITY_H
#define ENTITY_H

class GameEngine;
class Platform;
class Sprite;
#include <Box2D.h>

class Entity
{
public:
    Entity(GameEngine *m_engine);

    Sprite* sprite() {
        return m_sprite;
    }

    b2Body *body() {
        return m_body;
    }

    double width() {
        return m_width;
    }

    double height() {
        return m_height;
    }

    // TODO check that this is assigned a fixtureDef
    b2FixtureDef *fixtureDef() {
        return m_fixtureDef;
    }

protected:
    GameEngine *m_engine;
    b2World *m_world;
    b2BodyDef *m_bodyDef;
    b2Body *m_body;
    b2Shape *m_shape;
    Platform *m_platform;
    b2FixtureDef *m_fixtureDef;

    double m_width;
    double m_height;

    Sprite *m_sprite;
};

#endif // ENTITY_H
