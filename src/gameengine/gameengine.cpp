#include "gameengine.h"

#include <Box2D.h>
#include <iostream>
#include "platform/platform.h"
#include "entity/ball.h"
#include "entity/ground.h"
#include "entity/box.h"

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
GameEngine::GameEngine(Platform *platform_, int argc, char* argv[]) :
    m_platform(platform_)
{
    (void)argc;
    (void)argv;
    m_engineMode = ModeTestbed;
    m_gameState = GameStarted;

    m_platform->setAdvanceTimerInterval(1./60.);
    m_platform->stopAdvanceTimer();

    initBox2D();

    startGame();
}

void GameEngine::initBox2D() {
    std::cout << __PRETTY_FUNCTION__ << " called" << std::endl;
    if(engineMode() == ModeTestbed) {
        b2Vec2 gravity(0,-9.81);
        m_world = new b2World(gravity);
        Ground *ground = new Ground(this);
        entities.push_back(ground);
        Ground *ground2 = new Ground(this);
        ground2->body()->SetTransform(b2Vec2(10,10),0);
        entities.push_back(ground2);
        Ground *ground3 = new Ground(this);
        ground3->body()->SetTransform(b2Vec2(20,10),0);
        entities.push_back(ground3);
        Ground *ground4 = new Ground(this);
        ground4->body()->SetTransform(b2Vec2(30,10),0);
        entities.push_back(ground4);
        Box *box = new Box(this);
        entities.push_back(box);
        Ball *ball = new Ball(this);
        entities.push_back(ball);
    } else {
        std::cerr << "Mode not implemented!" << std::endl;
    }
}

void GameEngine::redraw() {
    platform()->clear();
    for(int i = 0; i < entities.size(); i++) {
        Entity* entity = entities.at(i);
        double scale = 10;
        // scaling should be redone
        double x = entity->body()->GetPosition().x * scale;
        double y = entity->body()->GetPosition().y * scale;
        double width = entity->width() * scale;
        double height = entity->height() * scale;
        platform()->drawSprite(entity->sprite(), x, y, width, height, entity->body()->GetAngle());
    }
}

void GameEngine::advance() {
    int velocityIterations = 6;
    int positionIterations = 2;
    double timeStep = 1./60.;

    m_world->Step(timeStep, velocityIterations, positionIterations);

    redraw();
}

void GameEngine::startGame()
{
    m_gameState = GameRunning;
    m_platform->startAdvanceTimer();
}
