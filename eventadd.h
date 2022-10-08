#ifndef EVENTADD_H
#define EVENTADD_H
#include "eventPlayer.h"

class EventAdd : public EventPlayer
{
public:
    EventAdd(){std::cout<<"createAdd\n";}
    ~EventAdd(){std::cout<<"deleteAdd\n";}
    void makeAction(Player & player) override;
};

#endif // EVENTADD_H
