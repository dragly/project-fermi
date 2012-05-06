#ifndef PLATFORM_H
#define PLATFORM_H

#include "sprite.h"

#include <string>

class GameEngine;

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

    GameEngine *gameEngine() {
        return m_gameEngine;
    }

protected:
    GameEngine *m_gameEngine;
	void set_pixelres(int pixelres) {
		this->pixelres = pixelres;
	}

	//Is this a reasonable way to do things? I want to keep it out of the engine-class, since they are totally disconnected.
	//Doing the appropritate conversions from meter to pixels just seems more logical in the graphics class...
	//Converting angels etc. should also be done outside the engine... Are they?

	//Very nice job, you have to give me a brief intro to the code sometime; atm I'm afraid to touch anything! :P
	int pixelres;
};

#endif // PLATFORM_H
