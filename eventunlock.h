#ifndef EVENTUNLOCK_H
#define EVENTUNLOCK_H
#include "eventField.h"

class EventUnlock : public EventField
{
public:
    EventUnlock();
    int getNumOfType() override {return 3;}
    void newField(Field & field) override;
};

#endif // EVENTUNLOCK_H
