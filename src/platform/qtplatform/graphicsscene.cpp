#include "graphicsscene.h"

#include "qtplatform.h"
#include "../../gameengine/gameengine.h"

#include <iostream>
#include <QGraphicsSceneMouseEvent>

GraphicsScene::GraphicsScene(QtPlatform *platform) :
    QGraphicsScene(platform),
    m_platform(platform),
    m_gameEngine(platform->gameEngine())
{
    setSceneRect(0,0,400,400);
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsScene::mouseReleaseEvent(event);
    std::cout << "Mouse released at " << event->scenePos().x() << event->scenePos().y() << std::endl;
    m_gameEngine->onMouseReleased(event->scenePos().x(), event->scenePos().y());
}
