RAW_FILE_DATA_CPP = """#include "__NAME__.h"

#include "platform/platform.h"

__NAME__::__NAME__(GameEngine *engine, const b2Vec2 &position, __ARGS__) :
    Entity(engine)
{
    m_bodyDef = new b2BodyDef();__DYN_OR_STAT1__
    m_bodyDef->position = position;
    m_body = m_world->CreateBody(m_bodyDef);

    __SHAPE_SPESIFIC__

    __FIXTURE__

    __DYN_OR_STAT2__
    m_sprite = m_platform->createSprite("__LOWERNAME__.png"); 
}
"""

RAW_FILE_DATA_H = """#ifndef __UPPERNAME___H
#define __UPPERNAME___H

#include "entity.h"

class __NAME__ : public Entity
{
public:
    __NAME__(GameEngine *gameEngine, const b2Vec2 &position, __ARGS__);
};

#endif // __UPPERNAME___H
"""


###STATIC/DYNAMIC DIFFERENCES
STATIC1 = ""
STATIC2 = "m_body->CreateFixture(m_shape, 0.0f);"

DYNAMIC1 = "\n    m_bodyDef->type = b2_dynamicBody;"
DYNAMIC2 = "m_body->CreateFixture(fixtureDef);"

###FIXTURE
FIXTURE = """b2FixtureDef *fixtureDef = new b2FixtureDef();
    fixtureDef->shape = m_shape;
    fixtureDef->density = %gf;
    fixtureDef->restitution = %gf;
    fixtureDef->friction = %gf;"""


###DIFFERENT SHAPES BY KEYWORDS
CIRCLE = """m_shape = new b2CircleShape();
    m_height = m_width = radius * 2;
    m_shape->m_radius = radius;"""

BOX = """polygonShape = new b2PolygonShape();
    m_width = width;
    m_height = height;
    polygonShape->SetAsBox(m_width / 2, m_height / 2);
    m_shape = polygonShape;"""


shapeLib = {}
shapeLib["Circle"] = CIRCLE;
shapeLib["Box"] = BOX;

def GenerateFiles(name, args, dynamic, \
                 Shape, density, restitution, friction):

    #HFILE:
    DATA_H = RAW_FILE_DATA_H.replace("__UPPERNAME__", name.upper())
    DATA_H = DATA_H.replace("__NAME__", name)

    argstring = ""
    for arg in args:
        argstring += arg + ", "
    argstring = argstring.strip(", ")

    DATA_H = DATA_H.replace("__ARGS__", argstring)


    #CPPFILE
    DATA_CPP = RAW_FILE_DATA_CPP.replace("__LOWERNAME__", name.lower())
    DATA_CPP = DATA_CPP.replace("__NAME__", name)
    DATA_CPP = DATA_CPP.replace("__ARGS__", argstring)

    if dynamic:
        DATA_CPP = DATA_CPP.replace("__DYN_OR_STAT1__", DYNAMIC1)
        DATA_CPP = DATA_CPP.replace("__DYN_OR_STAT2__", DYNAMIC2)

        DATA_CPP = DATA_CPP.replace("__FIXTURE__", FIXTURE % (density, \
                                                              restitution, \
                                                              friction))


    else:
        DATA_CPP = DATA_CPP.replace("__DYN_OR_STAT1__", STATIC1)
        DATA_CPP = DATA_CPP.replace("__DYN_OR_STAT2__", STATIC2)

        DATA_CPP = DATA_CPP.replace("__FIXTURE__", "");

    DATA_CPP = DATA_CPP.replace("__SHAPE_SPESIFIC__", shapeLib[Shape]);

        
    return DATA_H, DATA_CPP

def xcheckShapeArgs(Shape, args):
    for arg in args:
        raw_arg = arg.split()[1]
        if raw_arg not in shapeLib[Shape]:
            print "-----------------------------------------------------\n"
            print "WARNING: ARGUMENT %s NOT FOUND IN %s SHAPELIB:\n" \
                  % (raw_arg, Shape)
            print shapeLib[Shape];
            print "\n-----------------------------------------------------"

def main():
    name = "Test"
    args = ["double width", "double height"]

    dynamic = True;

    Shape = "Box"

    density = 1.0
    restitution = 0.4
    friction = 0.3

    xcheckShapeArgs(Shape, args);         

    H, CPP = GenerateFiles(name, args, dynamic, \
                            Shape, density, restitution, friction)

    hfile = open(name + ".h", 'w')
    cppfile = open(name + ".cpp", 'w')

    hfile.write(H)
    cppfile.write(CPP)

    hfile.close()
    cppfile.close()

    return 0;

if __name__ == "__main__":
    main()



    
