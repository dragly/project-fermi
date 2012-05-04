QT += core gui opengl

LIBS += -lbox2d

DEFINES += PLATFORM_IS_QT

HEADERS += \
    platform/platform.h \
    gameengine/gameengine.h \
    platform/qtplatform/qtplatform.h \
    platform/qtplatform/graphicsscene.h

SOURCES += \
    platform/platform.cpp \
    main.cpp \
    gameengine/gameengine.cpp \
    platform/qtplatform/qtplatform.cpp \
    platform/qtplatform/graphicsscene.cpp

# Change and uncomment the following lines if Box2D resides in a different directory
#INCLUDEPATH += ../libs/Box2D_v2.2.1
#INCLUDEPATH += ../libs/Box2D_v2.2.1/Box2D
#LIBPATH += ../libs/Box2D_v2.2.1/Build/gmake/obj/Debug/Box2D
