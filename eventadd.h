#ifndef EVENTADD_H
#define EVENTADD_H
#include "eventPlayer.h"

class EventAdd : public EventPlayer
{
public:
    EventAdd();
    void makeAction(Player & player) override;
    int getNumOfType() override {return 1;}
};

#endif // EVENTADD_H
