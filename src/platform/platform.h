#ifndef PLATFORM_H
#define PLATFORM_H

#include <string>

class Platform
{
public:
    Platform(int argc, char* argv[]);
    virtual int exec() = 0;
    virtual void startAdvanceTimer() = 0;
    virtual void stopAdvanceTimer() = 0;
    virtual void setAdvanceTimerInterval(double interval) = 0;
    virtual void *createSprite(std::string spriteFile) = 0;
    virtual void drawSprite(void* sprite, double x, double y, double width, double height, double rotation) = 0;
    virtual void clear() = 0;
};

#endif // PLATFORM_H
