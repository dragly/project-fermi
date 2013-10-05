#include "svenniscoolbluebox.h"

SvennisCoolBlueBox::SvennisCoolBlueBox(GameEngine *engine,
                                       const b2Vec2 &position,
                                       double width,
                                       double height) :
    BoxEntity(engine, position, "box.png", width, height, true)
{
    createFixtureFromProps(1.0, 0.4, 0.3);
}
