#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include "../Observer/Observer.h"
#include <set>
#include <string>
#include "../Logger/Level.h"
class Observable {
public:
    virtual void setObs(Observer * obs) = 0;
    virtual void notify(Level level, std::string str) = 0;
};
#endif // OBSERVABLE_H
