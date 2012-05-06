#include "qtplatform.h"

#include "gameengine/gameengine.h"
#include "qtsprite.h"

#include <QApplication>
#include <iostream>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <math.h>

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
    graphicsView->scale(1,-1);

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

Sprite* QtPlatform::createSprite(std::string spriteFile)
{
    QPixmap pixmap(QString(":/images/") + QString::fromStdString(spriteFile));
    QGraphicsPixmapItem* rectItem = graphicsScene->addPixmap(pixmap);
    QtSprite *sprite = new QtSprite(rectItem);
    return sprite;
}

void QtPlatform::drawSprite(Sprite *sprite, double x, double y, double width, double height, double rotation)
{
    QtSprite* qtSprite = (QtSprite*)sprite;
    QGraphicsPixmapItem *spriteItem = (QGraphicsPixmapItem*)qtSprite->graphicsItem();
    QPixmap tmpPixmap = spriteItem->pixmap();
    spriteItem->setPixmap(tmpPixmap.scaledToHeight(height, Qt::SmoothTransformation));
    spriteItem->setTransformOriginPoint(width/2, height/2);
    spriteItem->setRotation(rotation * 180 / M_PI);
    spriteItem->setPos(-width/2 + x, -height/2 + y);
    spriteItem->setVisible(true);
}

void QtPlatform::clear()
{
}

