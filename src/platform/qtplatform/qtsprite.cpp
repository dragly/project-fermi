#include "qtsprite.h"

#include <QGraphicsItem>

QtSprite::QtSprite(QGraphicsItem *graphicsItem) :
    Sprite(),
    m_graphicsItem(graphicsItem)
{

}

QGraphicsItem *QtSprite::graphicsItem()
{
    return m_graphicsItem;
}
