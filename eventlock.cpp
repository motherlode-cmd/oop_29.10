#include "eventlock.h"

void EventLock::newField(Field &field)
{
    int x = field.getPositionPlayer().getX();
    int y = field.getPositionPlayer().getY();
    field.setCell(x + 1, y + 1, Cell(this,Position(x + 1, y + 1), false));
    field.setCell(x - 1, y - 1, Cell(this,Position(x - 1, y - 1), false));
    field.setCell(x, y + 1, Cell(this,Position(x + 1, y + 1), false));
}
