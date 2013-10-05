#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "platform/platform.h"
#include "entity/entity.h"

#include <Box2D.h>
#include <vector>

class GameEngine
{
public:
    GameEngine(int argc, char *argv[]);

    enum GameState{
        GameStarted, /*! The game has just started */
        GameRunning, /*! The game is running */
        GamePaused,  /*! The game has been paused */
        GameOver,    /*! The level was failed */
        GameInstructionPause /*! The game is running, but we are showing instructions on screen */
    };

    enum EngineMode {
        ModeGame, /*! The engine is running as a regular game */
        ModeTestbed /*! The engine is running in testbed mode */
    };

    enum SpecialEntityIdentifyer {
        AwesomeBlueBox /*! Nice to have identifyers for quick access to a group of entities (e.g. to switch off lights etc.) */
    };

    GameState gameState() {
        return m_gameState;
    }

    EngineMode engineMode() {
        return m_engineMode;
    }

    void setPlatform(Platform* platform) {
        m_platform = platform;
    }

    void initBox2D(int velocityIterations, int positionIterations, double timestep);
    void advance();
    void startGame();
    void exitGame();
    void redraw();

    std::vector<Entity *> getEntitiesFromID(int ID);

    b2World *world() {
        return m_world;
    }

    Platform* platform() {
        return m_platform;
    }

    void onMouseReleased(int x, int y);
    void moveBox(int direction);
    void launchBox();
private:
    EngineMode m_engineMode;
    GameState m_gameState;

    b2World *m_world;

    Platform *m_platform;

    std::vector<Entity*> entities;

    double m_scale;

    int velocityIterations;
    int positionIterations;
    double timeStep;
};

#endif // GAMEENGINE_H
