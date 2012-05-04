#ifndef QTPLATFORM_H
#define QTPLATFORM_H

#include "../platform.h"
#include "../../gameengine/gameengine.h"
#include "graphicsscene.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtOpenGL/QGLWidget>
#include <QTimer>
#include <QObject>

class QtPlatform : public QObject, public Platform
{
    Q_OBJECT
public:
    QtPlatform(int argc, char* argv[]);
    int exec();
    void startAdvanceTimer();
    void stopAdvanceTimer();
    void setAdvanceTimerInterval(double interval);
    void *createSprite(std::string spriteFile);
    void drawSprite(void *sprite, double x, double y, double width, double height, double rotation);
    void clear();

public slots:
    void advanceTimeout();

private:
    GameEngine *gameEngine;

    QGraphicsView *graphicsView;
    QGraphicsScene *graphicsScene;

    QApplication *qtApp;

    QTimer *timer;
};

#endif // QTPLATFORM_H
