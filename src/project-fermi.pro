QT += core gui opengl

QMAKE_CXXFLAGS += -std=c++0x

DEFINES += PLATFORM_IS_QT

HEADERS += \
    platform/platform.h \
    gameengine/gameengine.h \
    platform/qtplatform/qtplatform.h \
    platform/qtplatform/graphicsscene.h \
    entity/entity.h \
    entity/svennisawesomeball.h \
    entity/ground.h \
    entity/boxentity.h \
    platform/sprite.h \
    platform/qtplatform/qtsprite.h \
    entity/circleentity.h \
    entity/svenniscoolbluebox.h

SOURCES += \
    platform/platform.cpp \
    main.cpp \
    gameengine/gameengine.cpp \
    platform/qtplatform/qtplatform.cpp \
    platform/qtplatform/graphicsscene.cpp \
    entity/entity.cpp \
    entity/svennisawesomeball.cpp \
    entity/ground.cpp \
    entity/boxentity.cpp \
    platform/sprite.cpp \
    platform/qtplatform/qtsprite.cpp \
    entity/circleentity.cpp \
    entity/svenniscoolbluebox.cpp

# Box2D should be placed in a libs/ folder next to src/
# It is suffixed with -harmattan if it is an ARM build for Nokia N9
contains(MEEGO_EDITION,harmattan) {
    message(Is MeeGo (Nokia N9))
    INCLUDEPATH += $$PWD/../libs/Box2D_v2.2.1-harmattan
    INCLUDEPATH += $$PWD/../libs/Box2D_v2.2.1-harmattan/Box2D
    LIBS += -L$$PWD/../libs/Box2D_v2.2.1-harmattan/Build/gmake/bin/Debug -lBox2D
} else {
    message(Is some other OS)
    INCLUDEPATH += $$PWD/../libs/Box2D_v2.2.1
    INCLUDEPATH += $$PWD/../libs/Box2D_v2.2.1/Box2D
    LIBS += -L$$PWD/../libs/Box2D_v2.2.1/Build/gmake/bin/Debug -lBox2D
}


RESOURCES += \
    resources.qrc

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog

contains(MEEGO_EDITION,harmattan) {
    target.path = /opt/project-fermi/bin
    INSTALLS += target
}
