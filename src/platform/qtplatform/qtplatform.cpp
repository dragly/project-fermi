#include "qtplatform.h"

#include "gameengine/gameengine.h"

#include <QApplication>
#include <iostream>
#include <QGraphicsRectItem>
#include <QGraphicsItem>

QtPlatform::QtPlatform(int argc, char* argv[]) :
    Platform(argc, argv)
{

    timer = new QTimer();
    qtApp = new QApplication(argc, argv);
    graphicsView = new QGraphicsView();
    QGLWidget *glwidget = new QGLWidget(graphicsView);
    graphicsScene = new QGraphicsScene(graphicsView);
    graphicsScene->setSceneRect(0,0,800,480);
    graphicsView->setViewport(glwidget);
    graphicsView->setScene(graphicsScene);

    connect(timer, SIGNAL(timeout()), SLOT(advanceTimeout()));
    gameEngine = new GameEngine(this, argc, argv);
}

/*!
  This loads everything needed to run a game and sets up the game engine
  so that it is aware about the platform.
  */
int QtPlatform::exec()
{
    graphicsView->show();

    return qtApp->exec();
}

void QtPlatform::advanceTimeout()
{
    std::cout << "Timed out!" << std::endl;
    gameEngine->advance();
}

void QtPlatform::startAdvanceTimer()
{
    timer->start();
}

void QtPlatform::stopAdvanceTimer()
{
    timer->stop();
}

void QtPlatform::setAdvanceTimerInterval(double interval)
{
    timer->setInterval(interval * 1000);
}

void* QtPlatform::createSprite(std::string spriteFile)
{
    QGraphicsRectItem* rectItem = graphicsScene->addRect(0,0,10,10);
    return rectItem;
}

void QtPlatform::drawSprite(void *sprite, double x, double y, double width, double height, double rotation)
{
    QGraphicsRectItem *spriteItem = (QGraphicsRectItem*)sprite;
    spriteItem->setRect(x, y, width, height);
    spriteItem->setVisible(true);
}

void QtPlatform::clear()
{
}

