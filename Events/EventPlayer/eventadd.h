#ifndef EVENTADD_H
#define EVENTADD_H
#include "eventPlayer.h"

class EventAdd : public EventPlayer
{
public:
    EventAdd(){}
    ~EventAdd(){}
    void makeAction(Player & player) override;
    std::string print() const override {return "OOO + 10 HP";}
};

#endif // EVENTADD_H
