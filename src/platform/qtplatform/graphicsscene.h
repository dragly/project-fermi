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

    enum KEY {
        W = 87,
        UPARROW = 16777235,
        A = 65,
        LEFTARROW = 16777234,
        D = 68,
        RIGHTARROW = 16777236,
        ESC = 16777216
    };

    void keyPressEvent(QKeyEvent *event);

    QtPlatform *m_platform;
    GameEngine *m_gameEngine;
};

#endif // GRAPHICSSCENE_H
