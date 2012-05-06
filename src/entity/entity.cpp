#include "entity.h"

#include "../platform/platform.h"
#include "../gameengine/gameengine.h"

Entity::Entity(GameEngine *engine) :
    m_engine(engine),
    m_world(engine->world()),
    m_platform(engine->platform())
{
}
