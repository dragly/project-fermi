#ifndef ENTITY_H
#define ENTITY_H

#define ENTITY_NO_SIZE -1
#define ENTITY_DEFAULT_SPRITE "defaultpicture.png"
#define ENTITY_STATIC_FIXTURE 0, 0

class GameEngine;
class Platform;
class Sprite;

#include <Box2D.h>
#include <string>

class Entity
{
public:

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

    const int * identifyer() {
        return m_identifyer;
    }

    void setIdentifyer(int identifyer){

        if (m_identifyer == NULL) {
            m_identifyer = new int(identifyer);
        } else {
        *(m_identifyer) = identifyer;
        }

    }

    static unsigned int getNumberOfSprites(){
        return staticID;
    }

    std::string description(){
        return m_description;
    }


protected:

    Entity(GameEngine *m_engine,
           const b2Vec2 &position,
           std::string spriteName = ENTITY_DEFAULT_SPRITE,
           b2Shape * shape = NULL,
           double width = ENTITY_NO_SIZE,
           double height = ENTITY_NO_SIZE,
           bool dynamic = true);

    GameEngine *m_engine;

    b2World *m_world;

    Platform *m_platform;

    b2BodyDef *m_bodyDef;
    b2Body *m_body;

    b2Shape *m_shape;

    Sprite *m_sprite;

    double m_width;
    double m_height;

    static unsigned int staticID;

    int* m_identifyer;

    std::string m_description;

    void createFixtureFromProps(float32 density,
                                float32 restitution,
                                float32 friction = 0.2f);

};

#endif // ENTITY_H
