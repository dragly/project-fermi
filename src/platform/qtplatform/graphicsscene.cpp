#include "graphicsscene.h"

#include "qtplatform.h"
#include "../../gameengine/gameengine.h"

#include <iostream>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

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

void GraphicsScene::keyPressEvent(QKeyEvent *event) {
    QGraphicsScene::keyPressEvent(event);

    switch (event->key()) {
    case W:
    case UPARROW:
        m_gameEngine->launchBox();
        break;
    case A:
    case LEFTARROW:
        m_gameEngine->moveBox(-1);
        break;
    case D:
    case RIGHTARROW:
        m_gameEngine->moveBox(+1);
        break;
    case ESC:
        m_gameEngine->exitGame();
    default:
        break;
    }

}
