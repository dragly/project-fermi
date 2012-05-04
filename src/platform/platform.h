#ifndef PLATFORM_H
#define PLATFORM_H

class Platform
{
public:
    Platform(int argc, char* argv[]);
    virtual int exec() = 0;
};

#endif // PLATFORM_H
