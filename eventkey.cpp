#include "eventkey.h"

void EventKey::makeAction(Player &player)
{
    player.gotKey();
}

//std::ostream& operator << (std::ostream & os, const EventKey & e) {
//    //os << "Player ot Key \n";
//    e.print(os);
//    return os;
//}
