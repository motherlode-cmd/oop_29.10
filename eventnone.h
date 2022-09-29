#ifndef EVENTNONE_H
#define EVENTNONE_H
#include "event.h"

class EventNone : public Event
{
public:
    EventNone();
    void makeAction(Player & player) override;
    int getNumOfType() override {return 0;}
};

#endif // EVENTNONE_H
