#ifndef GAMEENGINE_H
#define GAMEENGINE_H

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
        ModeGame,
        ModeTestbed
    };

    GameState gameState() {
        return m_gameState;
    }

    EngineMode engineMode() {
        return m_engineMode;
    }

private:
    EngineMode m_engineMode;
    GameState m_gameState;
};

#endif // GAMEENGINE_H
