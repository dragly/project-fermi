#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>

class QtPlatform;
class GameEngine;

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene(QtPlatform *platform = 0);

signals:
    
public slots:
    
private:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    QtPlatform *m_platform;
    GameEngine *m_gameEngine;
};

#endif // GRAPHICSSCENE_H
