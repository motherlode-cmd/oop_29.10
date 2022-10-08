#ifndef EVENTNONE_H
#define EVENTNONE_H
#include "eventPlayer.h"

class EventNone : public EventPlayer
{
public:
    EventNone(){std::cout<<"createNone\n";}
    ~EventNone(){std::cout<<"deleteNone\n";}
    void makeAction(Player & player) override;
};

#endif // EVENTNONE_H
