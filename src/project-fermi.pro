QT += core gui opengl


DEFINES += PLATFORM_IS_QT

HEADERS += \
    platform/platform.h \
    gameengine/gameengine.h \
    platform/qtplatform/qtplatform.h \
    platform/qtplatform/graphicsscene.h \
    entity/entity.h \
    entity/ball.h \
    entity/ground.h \
    entity/box.h

SOURCES += \
    platform/platform.cpp \
    main.cpp \
    gameengine/gameengine.cpp \
    platform/qtplatform/qtplatform.cpp \
    platform/qtplatform/graphicsscene.cpp \
    entity/entity.cpp \
    entity/ball.cpp \
    entity/ground.cpp \
    entity/box.cpp

# Box2D should be placed in a libs/ folder next to src/
INCLUDEPATH += ../libs/Box2D_v2.2.1
INCLUDEPATH += ../libs/Box2D_v2.2.1/Box2D
LIBS += -L../libs/Box2D_v2.2.1/Build/gmake/bin/Debug -lBox2D
