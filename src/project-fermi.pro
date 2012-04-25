SOURCES += \
    platform/platform.cpp \
    main.cpp \
    gameengine/gameengine.cpp \
    platform/qtplatform.cpp
INCLUDEPATH += ../libs/Box2D_v2.2.1
INCLUDEPATH += ../libs/Box2D_v2.2.1/Box2D
LIBPATH += /mn/felt/u9/svennard/projects/project-fermi/libs/Box2D_v2.2.1/Build/gmake/obj/Debug/Box2D
LIBS += -lbox2d

HEADERS += \
    platform/platform.h \
    gameengine/gameengine.h \
    platform/qtplatform.h

