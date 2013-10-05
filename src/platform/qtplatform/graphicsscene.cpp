#include "graphicsscene.h"

#include "qtplatform.h"
#include "../../gameengine/gameengine.h"

#include <iostream>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

GraphicsScene::GraphicsScene(QtPlatform *platform) :
    QGraphicsScene(platform),
    m_platform(platform)
{
    setSceneRect(0,0,400,400);
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsScene::mouseReleaseEvent(event);
    std::cout << "Mouse released at " << event->scenePos().x() << event->scenePos().y() << std::endl;
    gameEngine()->onMouseReleased(event->scenePos().x(), event->scenePos().y());
}

void GraphicsScene::keyPressEvent(QKeyEvent *event) {
    QGraphicsScene::keyPressEvent(event);

    switch (event->key()) {
    case W:
    case UPARROW:
        gameEngine()->launchBox();
        break;
    case A:
    case LEFTARROW:
        gameEngine()->moveBox(-1);
        break;
    case D:
    case RIGHTARROW:
        gameEngine()->moveBox(+1);
        break;
    case ESC:
        gameEngine()->exitGame();
    default:
        break;
    }

}

GameEngine *GraphicsScene::gameEngine()
{
    return m_platform->gameEngine();
}
