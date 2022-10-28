#include "eventnone.h"

void EventNone::makeAction(HumanPlayer &player)
{
    notify(Level::State, print());
    player.setHealth(player.getHealth() - 10);
}

//std::ostream & operator<<(std::ostream & os, EventNone & e)
//{
//    //os << " -10 hp \n";
//    e.print(os);
//    return os;
//}
