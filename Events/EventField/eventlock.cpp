#include "eventlock.h"

void EventLock::newField(Field &field)
{
    int x = field.getPositionPlayer().getX();
    int y = field.getPositionPlayer().getY();
    field.lockCell(x, y + 1);
    notify(Level::State, print() +  "[" + std::to_string(x) +  "]" +"[" + std::to_string(y + 1) +  "]");
}

//std::ostream& operator << (std::ostream & os, const EventLock & e) {
//    //os << "Player locked somecells \n";
//    e.print(os);
//    return os;
//}
