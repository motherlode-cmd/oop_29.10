#ifndef GENERATELEVEL_H
#define GENERATELEVEL_H
#include "eventadd.h"
#include "eventkey.h"
#include "eventlock.h"
#include "eventnone.h"
#include "eventunlock.h"
#include "eventwin.h"
#include "field.h"
class GenerateLevel
{
public:
    GenerateLevel();
    ~GenerateLevel();
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
