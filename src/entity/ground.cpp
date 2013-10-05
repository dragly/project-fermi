#include "ground.h"

Ground::Ground(GameEngine *engine, const b2Vec2 &position, double width, double height) :
    BoxEntity(engine, position, "box.png", width, height, false)
{
    createFixtureFromProps(ENTITY_STATIC_FIXTURE);
}
