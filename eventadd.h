#ifndef EVENTADD_H
#define EVENTADD_H
#include "eventPlayer.h"

class EventAdd : public EventPlayer
{
public:
    EventAdd(){std::cout<<"createAdd\n";}
    ~EventAdd(){std::cout<<"deleteAdd\n";}
    void makeAction(Player & player) override;
    void print(std::ostream& os) const override {os << "OOO + 10 HP ";}
    //friend std::ostream& operator << (std::ostream &, EventAdd *);
};

#endif // EVENTADD_H
