#ifndef QTSPRITE_H
#define QTSPRITE_H

#include "../sprite.h"

#include <string>
#include <QGraphicsItem>

class QtSprite : public Sprite
{
public:
    QtSprite(QGraphicsItem *graphicsItem);

    QGraphicsItem *graphicsItem();
private:
    std::string m_filename;
    QGraphicsItem* m_graphicsItem;
};

#endif // QTSPRITE_H
