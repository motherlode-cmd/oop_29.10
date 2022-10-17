#ifndef EVENTKEY_H
#define EVENTKEY_H
#include "eventPlayer.h"
class EventKey : public EventPlayer
{
public:
    EventKey(){std::cout<<"createKey\n";}
    ~EventKey(){std::cout<<"deleteKey\n";}
    void makeAction(Player & player) override;
    //friend std::ostream& operator << (std::ostream &, EventKey *);
    void print(std::ostream& os) const override {os << "in this cell player got Key";}
};

#endif // EVENTKEY_H
