#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <sstream>

class Sprite
{
public:
    Sprite();

    std::string getName() {
        return spriteName;
    }

    unsigned int getID() {
        return ID;
    }

    static unsigned int getNumberOfSprites(){
        return staticID;
    }

    std::string getDescription(){
        std::stringstream s;

        s << getName() << "_" << getID();

        return s.str();
    }

    //Makes the Entity base the only one able to change the name.
    friend class Entity;

private:

    static unsigned int staticID;
    unsigned int ID;

    std::string spriteName;

    void setName(std::string spriteName) {
        this->spriteName = spriteName;
    }

};

#endif // SPRITE_H
