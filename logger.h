#ifndef LOGGER_H
#define LOGGER_H
#include "field.h"
#include "player.h"
#include <array>
#include <fstream>
#include <ostream>
//template <class A>

class Logger
{
public:
    enum Level
    {
       WARN, ERROR, INFO
    };
public:
    //Logger();
    virtual void log(/*Level level, */const Player & p) = 0;
    virtual void log(/*Level level, */const Field & f) = 0;
    virtual void log(/*Level level, */const Event & e) = 0;
    virtual void log(std::string && s) = 0;
    //void logs(vector <Logger * >)
protected :

    //std::string buff;
};
#endif // LOGGER_H
