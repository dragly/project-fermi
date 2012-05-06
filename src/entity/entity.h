#ifndef ENTITY_H
#define ENTITY_H

class GameEngine;
class Platform;

#include <Box2D.h>

class Entity
{
public:
    Entity(GameEngine *engine);

    void* sprite() {
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

protected:
    GameEngine *engine;
    b2World *world;
    b2BodyDef *bodyDef;
    b2Body *m_body;
    b2Shape *shape;
    Platform *platform;

    double m_width;
    double m_height;

    void *m_sprite;
};

#endif // ENTITY_H