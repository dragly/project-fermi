#ifndef SVENNISCOOLBLUEBOX_H
#define SVENNISCOOLBLUEBOX_H

#include "boxentity.h"

class SvennisCoolBlueBox : public BoxEntity
{
public:
    SvennisCoolBlueBox(GameEngine *engine, const b2Vec2 &position, double width, double height);
};
#endif // SVENNISCOOLBLUEBOX_H
