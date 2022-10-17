#include "eventadd.h"

void EventAdd::makeAction(Player &player)
{
    player.setHealth(player.getHealth() + 10);
}

//std::ostream& operator << (std::ostream & os, const EventAdd * e) {
//    //os << "+10 hp \n";
//    e->print(os);
//    return os;
//}
