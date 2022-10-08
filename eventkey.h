#ifndef EVENTKEY_H
#define EVENTKEY_H
#include "eventPlayer.h"
class EventKey : public EventPlayer
{
public:
    EventKey(){std::cout<<"createKey\n";}
    ~EventKey(){std::cout<<"deleteKey\n";}
    void makeAction(Player & player) override;
};

#endif // EVENTKEY_H
