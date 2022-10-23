#include "eventunlock.h"

void EventUnlock::newField(Field &field)
{
    int x = field.getPositionPlayer().getX();
    int y = field.getPositionPlayer().getY();
    //field.setCell(x + 1, y + 1, Cell(new EventNone(),Position(x + 1, y + 1), true));
    //field.setCell(x - 1, y - 1, Cell(new EventNone(),Position(x - 1, y - 1), true));
    //field.setCell(x, y - 1, Cell(this, Position(x, y - 1), true));
    field.unlockCell(x, y-1);
    notify(Level::State, print() +  "[" + std::to_string(x) +  "]" + "["+ std::to_string(y - 1) +  "]");
}
