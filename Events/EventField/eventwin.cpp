#include "eventwin.h"
void EventWin::newField(Field &field)
{
    notify(Level::State, print());
}

//std::ostream& operator << (std::ostream & os, const EventWin & e) {
//    //os << "WINN \n";
//    e.print(os);
//    return os;
//}
