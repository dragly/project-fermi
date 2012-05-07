#ifndef TEST_H
#define TEST_H

#include "entity.h"

class Test : public Entity
{
public:
    Test(GameEngine *gameEngine, const b2Vec2 &position, double width, double height);
};

#endif // TEST_H
