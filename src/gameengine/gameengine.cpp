#include "gameengine.h"

#include <Box2D.h>
#include <iostream>

/*!
  The GameEngine class contains all the logic to run the game or testbed.
  It also works as an interface between the Platform and Box2D.
  */
/*
    Developer notes: Divide this class into reasonable modules in as great an
    extent as possible. The main class in a game engine tends to get quite bloaty
    in time. Putting things in modules from the beginning should make it easier to
    maintain (and quicker to compile).
*/
GameEngine::GameEngine(int argc, char* argv[])
{
    engineMode = ModeTestbed;
    gameState = GameStarted;
}

void GameEngine::initBox2D() {
    if(engineMode == ModeTestbed) {

    } else {
        std::cerr << "Mode not implemented!" << std::endl;
    }
}

