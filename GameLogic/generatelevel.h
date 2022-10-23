#ifndef GENERATELEVEL_H
#define GENERATELEVEL_H
#include "../Events/EventPlayer/eventadd.h"
#include "../Events/EventPlayer/eventnone.h"
#include "../Events/EventPlayer/eventkey.h"
#include "../Events/EventField/eventlock.h"
#include "../Events/EventField/eventunlock.h"
#include "../Events/EventField/eventwin.h"
#include "field.h"
class GenerateLevel
{
public:
    GenerateLevel();
    ~GenerateLevel();
    void setEventObs(Observer* obs);
    void generateLevel(Field & field);
private:
    Event * eventUnlock = new EventUnlock;
    Event * eventLock = new EventLock;
    Event * eventAdd = new EventAdd;
    Event * eventNone = new EventNone;
    Event * eventWin = new EventWin;
    Event * eventKey = new EventKey;
};

#endif // GENERATELEVEL_H
