#include "graphicsscene.h"

GraphicsScene::GraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
    setSceneRect(0,0,400,400);
}
