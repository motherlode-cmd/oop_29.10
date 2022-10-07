#include "eventwin.h"
EventWin::EventWin()
{

}

void EventWin::newField(Field &field)
{
    //field.setNewEvent(new EventAdd(), 0, 0);
    //field.setCell(3, 3, Cell(new EventAdd(),Position(3, 3), true));
    field = Field(6,6);
}
