#include "gameengine.h"

#include <Box2D.h>
#include <iostream>
#include "platform/platform.h"
#include "entity/svennisawesomeball.h"
#include "entity/ground.h"
#include "entity/svenniscoolbluebox.h"

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
GameEngine::GameEngine(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    m_engineMode = ModeTestbed;
    m_gameState = GameStarted;
}

void GameEngine::initBox2D(int velocityIterations, int positionIterations, double timeStep) {
    std::cout << __PRETTY_FUNCTION__ << " called" << std::endl;

    m_platform->setAdvanceTimerInterval(timeStep);
    m_platform->stopAdvanceTimer();

    this->velocityIterations = velocityIterations;
    this->positionIterations = positionIterations;
    this->timeStep = timeStep;

    b2Vec2 gravity(0,-9.81);
    m_world = new b2World(gravity);

    if(engineMode() == ModeTestbed) {
        Ground *ground = new Ground(this, b2Vec2(0,10), 10, 10);
        entities.push_back(ground);
        Ground *ground2 = new Ground(this, b2Vec2(10,10), 10, 10);
        entities.push_back(ground2);
        Ground *ground3 = new Ground(this, b2Vec2(20,10), 10, 10);
        entities.push_back(ground3);
        Ground *ground4 = new Ground(this, b2Vec2(30,10), 10, 10);
        entities.push_back(ground4);
        SvennisCoolBlueBox *box = new SvennisCoolBlueBox(this, b2Vec2(10,20), 5, 5);
        box->setIdentifyer(AwesomeBlueBox);
        box->body()->SetLinearVelocity(b2Vec2(5,2));
        box->body()->SetAngularVelocity(0.1f);
        entities.push_back(box);
        SvennisAwesomeBall *ball = new SvennisAwesomeBall(this, b2Vec2(15,30),2);
        ball->body()->SetLinearVelocity(b2Vec2(5,10));
        entities.push_back(ball);
    } else {
        std::cerr << "Mode not implemented!" << std::endl;
    }
}

void GameEngine::redraw() {

    platform()->clear();

    for(unsigned int i = 0; i < entities.size(); ++i) {
        Entity* entity = entities.at(i);

        m_scale = 10;
        // scaling should be redone
        double x = entity->body()->GetPosition().x * m_scale;
        double y = entity->body()->GetPosition().y * m_scale;
        double width = entity->width() * m_scale;
        double height = entity->height() * m_scale;
        platform()->drawSprite(entity->sprite(), x, y, width, height, entity->body()->GetAngle());
    }
}

std::vector<Entity*> GameEngine::getEntitiesFromID(int ID)
{

    std::vector<Entity*> matchedEntities;

    for (unsigned int i = 0; i < entities.size(); ++i) {
        Entity* entity_i = entities.at(i);
        const int* ID_i = entity_i->getIdentifyer();

        if (ID_i == NULL){
            continue;
        }

        if (ID == *(ID_i)) {
            matchedEntities.push_back(entity_i);
        }
    }

    return matchedEntities;

}

void GameEngine::advance()
{
    m_world->Step(timeStep, velocityIterations, positionIterations);
    redraw();
}

void GameEngine::startGame()
{
    m_gameState = GameRunning;
    m_platform->startAdvanceTimer();
}

void GameEngine::exitGame()
{
    m_gameState = GameOver;
    m_platform->stopAdvanceTimer();
    m_platform->close();
}

void GameEngine::onMouseReleased(int x, int y)
{
    std::cout << b2Vec2(x,y).x << " " << b2Vec2(x,y).y << std::endl;
    b2Vec2 position;
    position.x = x / m_scale;
    position.y = y / m_scale;

    double radius = 1 + (Sprite::getNumberOfSprites()%20)/5;

    SvennisAwesomeBall *ball = new SvennisAwesomeBall(this, position, radius);
    ball->body()->SetLinearVelocity(b2Vec2(1,2));
    ball->body()->SetAngularVelocity(radius*2);
    entities.push_back(ball);
}

void GameEngine::moveBox(int direction)
{
    b2Body * blueBox = (*getEntitiesFromID(AwesomeBlueBox).begin())->body();

    float scale = 0.25f;

    const b2Vec2 & oldPosition = blueBox->GetPosition();

    float newX = oldPosition.x + direction*scale;

    b2Vec2 newPosition(newX, oldPosition.y);

    b2Vec2 force(direction*1000.0f, 0);

    blueBox->SetTransform(newPosition, blueBox->GetAngle());
    blueBox->ApplyForce(force, blueBox->GetWorldCenter());
}

void GameEngine::launchBox(){

    b2Body * blueBox = (*getEntitiesFromID(AwesomeBlueBox).begin())->body();

    b2Vec2 rocket(0, 10000.0f);
    blueBox->ApplyForce(rocket, blueBox->GetWorldCenter());

}
