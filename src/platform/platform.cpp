#include "platform.h"

#include "../gameengine/gameengine.h"

Platform::Platform(int argc, char *argv[]) :
    m_gameEngine(new GameEngine(argc, argv))
{

}
