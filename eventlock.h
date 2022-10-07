#ifndef EVENTLOCK_H
#define EVENTLOCK_H
#include "eventField.h"

class EventLock : public EventField
{
public:
    EventLock();
    int getNumOfType() override {return 3;}
    void newField(Field & field) override;
};

#endif // EVENTLOCK_H
