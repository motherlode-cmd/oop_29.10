#include "eventnone.h"

void EventNone::makeAction(Player &player)
{
    player.setHealth(player.getHealth() - 10);
}

//std::ostream & operator<<(std::ostream & os, EventNone & e)
//{
//    //os << " -10 hp \n";
//    e.print(os);
//    return os;
//}
