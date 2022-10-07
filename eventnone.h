#ifndef EVENTNONE_H
#define EVENTNONE_H
#include "eventPlayer.h"

class EventNone : public EventPlayer
{
public:
    EventNone();
    void makeAction(Player & player) override;
    int getNumOfType() override {return 0;}
};

#endif // EVENTNONE_H
