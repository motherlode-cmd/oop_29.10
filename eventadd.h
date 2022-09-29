#ifndef EVENTADD_H
#define EVENTADD_H

#include "event.h"

class EventAdd : public Event
{
public:
    EventAdd();
    void makeAction(Player & player) override;
    int getNumOfType() override {return 1;}
};

#endif // EVENTADD_H
