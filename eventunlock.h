#ifndef EVENTUNLOCK_H
#define EVENTUNLOCK_H
#include "eventField.h"

class EventUnlock : public EventField
{
public:
    EventUnlock(){std::cout<<"createUnlock\n";}
    ~EventUnlock(){std::cout<<"deleteUnlock\n";}
    void newField(Field & field) override;
};

#endif // EVENTUNLOCK_H
