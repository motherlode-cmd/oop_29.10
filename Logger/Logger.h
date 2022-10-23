#ifndef LOGGER_H
#define LOGGER_H
#include "Level.h"
#include <string>
class Logger {
public:
    virtual ~Logger(){}
    virtual void log(Level level, std::string str) = 0;
};
#endif // LOGGER_H
