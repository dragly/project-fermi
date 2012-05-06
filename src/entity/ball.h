#ifndef BALL_H
#define BALL_H

#include "entity.h"

class Ball : public Entity
{
public:
    Ball(GameEngine *gameEngine, const b2Vec2 &position, double radius);
};

#endif // BALL_H
