#ifndef OBSERVER_H
#define OBSERVER_H
#include <set>
#include <string>
#include "../Logger/Level.h"
#include "../Logger/Logger.h"
class Observer {
public:
    virtual ~Observer(){}
    virtual void addLogger(Logger * log) = 0;
    virtual void deleteLogger(Logger * log) = 0;
    virtual void addLevel(Level level) = 0;
    virtual void deleteLevel(Level level) = 0;
    virtual void update(Level level, std::string s) = 0;
    virtual void clear() = 0;
};
#endif // OBSERVER_H
