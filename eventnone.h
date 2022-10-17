#ifndef EVENTNONE_H
#define EVENTNONE_H
#include "eventPlayer.h"

class EventNone : public EventPlayer
{
public:
    EventNone(){std::cout<<"createNone\n";}
    ~EventNone(){std::cout<<"deleteNone\n";}
//    friend std::ostream& operator << (std::ostream &, EventNone *);
    void makeAction(Player & player) override;
    void print(std::ostream& os) const override {os << "OOOOPS -10 HP";}
};

#endif // EVENTNONE_H
