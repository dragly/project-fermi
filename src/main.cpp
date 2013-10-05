#include <iostream>
#ifdef PLATFORM_IS_QT
#include "platform/qtplatform/qtplatform.h"
#endif
/*!
  The main file loads the platform which sets up everything it needs.
*/
int main(int argc, char* argv[]) {

    Platform *platform;

#ifdef PLATFORM_IS_QT
    platform = new QtPlatform(argc, argv);
#endif

    GameEngine fermiEngine(argc, argv, platform);

    fermiEngine.initBox2D(6, 2, 1./60, 10);
    fermiEngine.startGame();

    return platform->exec();
}
