#ifndef EVENTLOCK_H
#define EVENTLOCK_H
#include "eventField.h"

class EventLock : public EventField
{
public:
    EventLock(){std::cout<<"createLock\n";}
    ~EventLock(){std::cout<<"deleteLock\n";}
    void newField(Field & field) override;
};

#endif // EVENTLOCK_H
