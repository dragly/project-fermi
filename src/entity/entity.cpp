#include "entity.h"

#include "../platform/platform.h"
#include "../gameengine/gameengine.h"

Entity::Entity(GameEngine *engine_) :
    engine(engine_),
    world(engine_->world()),
    platform(engine_->platform())
{
}
