#ifndef ENTITY_H
#define ENTITY_H

class GameEngine;
class Platform;
class Sprite;
#include <Box2D.h>

class Entity
{
public:
    Entity(GameEngine *engine);

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

protected:
    GameEngine *engine;
    b2World *world;
    b2BodyDef *m_bodyDef;
    b2Body *m_body;
    b2Shape *shape;
    Platform *platform;

    double m_width;
    double m_height;

    Sprite *m_sprite;
};

#endif // ENTITY_H
