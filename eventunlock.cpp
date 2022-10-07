#include "eventunlock.h"
#include "eventadd.h"
#include "eventnone.h"

EventUnlock::EventUnlock()
{

}

void EventUnlock::newField(Field &field)
{
    int x = field.getPositionPlayer().getX();
    int y = field.getPositionPlayer().getY();
    //field.setCell(x + 1, y + 1, Cell(new EventNone(),Position(x + 1, y + 1), true));
    //field.setCell(x - 1, y - 1, Cell(new EventNone(),Position(x - 1, y - 1), true));
    Event * event = new EventAdd;
    field.setCell(x, y - 1, Cell(event, Position(x, y - 1), true));
}
