#include "eventkey.h"

void EventKey::makeAction(HumanPlayer &player)
{
    notify(Level::State, print());
    player.gotKey();
}

//std::ostream& operator << (std::ostream & os, const EventKey & e) {
//    //os << "Player ot Key \n";
//    e.print(os);
//    return os;
//}
