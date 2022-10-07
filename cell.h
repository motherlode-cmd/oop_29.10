#ifndef CELL_H
#define CELL_H
#include "event.h"
#include "position.h"

class Cell
{
public:
    Cell();
    Cell(Cell const &copyCell);
    Cell & operator = (Cell const & other);
    Cell(Cell && source);
    Cell & operator = (Cell && other);
    Cell(Event * event, const Position & position, bool isOpen);
    ~Cell();
    void setEvent(Event *newEvent);
    const Position &getPosition() const;
    bool getIsOpen() const;

    Event *getEvent() const;

private:
    Event * event;
    Position position;
    bool isOpen = true;
};

#endif // CELL_H
