#include "svennisawesomeball.h"

SvennisAwesomeBall::SvennisAwesomeBall(GameEngine *engine, const b2Vec2 &position, double radius) :
    circleEntity(engine, position, radius)
{
    createFixtureFromProps(1.0, 0.4, 0.3);
}
