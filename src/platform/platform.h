#ifndef PLATFORM_H
#define PLATFORM_H

#include "sprite.h"
#include <string>

class GameEngine;
class Entity;

class Platform
{
public:

    Platform(int argc, char* argv[]);

    virtual int exec() = 0;
    virtual void clear() = 0;
    virtual void close() = 0;

    virtual void startAdvanceTimer() = 0;
    virtual void stopAdvanceTimer() = 0;
    virtual void setAdvanceTimerInterval(double interval) = 0;

    virtual void prepareEntity(Entity* entity) {(void) entity;}

    virtual Sprite *createSprite(std::string spriteFile) = 0;
    virtual void drawSprite(Sprite* sprite, double x, double y, double width, double height, double rotation) = 0;

    GameEngine *gameEngine() {
        return m_gameEngine;
    }

    void setGameEngine(GameEngine* engine){
        m_gameEngine = engine;
    }


protected:

    GameEngine *m_gameEngine;

};

#endif // PLATFORM_H
