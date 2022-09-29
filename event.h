#ifndef EVENT_H
#define EVENT_H
#include "player.h"
class Event{
public:
    virtual void makeAction(Player & player) = 0;
    virtual int getNumOfType() = 0;
};
#endif // EVENT_H
