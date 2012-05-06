#ifndef PLATFORM_H
#define PLATFORM_H

#include "sprite.h"

#include <string>

class Platform
{
public:
    Platform(int argc, char* argv[]);
    virtual int exec() = 0;
    virtual void startAdvanceTimer() = 0;
    virtual void stopAdvanceTimer() = 0;
    virtual void setAdvanceTimerInterval(double interval) = 0;
    virtual Sprite *createSprite(std::string spriteFile) = 0;
    virtual void drawSprite(Sprite* sprite, double x, double y, double width, double height, double rotation) = 0;
    virtual void clear() = 0;
};

#endif // PLATFORM_H
