#include "cell.h"

//Cell::Cell(Event *event, Position &position):event(event), position(position)
//{

//}
Cell::Cell()
{
    event = nullptr;
    position = Position(0,0);
    isOpen = true;
}

Cell::Cell(Cell const &copyCell)
{
    event = copyCell.event;
    position = copyCell.position;
    isOpen = copyCell.isOpen;
}

Cell &Cell::operator = (Cell const &other)
{
    if(this != &other) {
        position = other.position;
        event = other.event;
        isOpen = other.isOpen;
    }
    return *this;
}

Cell::Cell(Event *event, const Position &position, bool isOpen): event(event), position(position), isOpen(isOpen)
{

}

Cell &Cell::operator = (Cell &&other)
{
    if(this != &other) {
        position = other.position;
        event = other.event;
        isOpen = other.isOpen;
        other.event = nullptr;
    }
    return *this;
}

Cell::Cell(Cell &&source): event(source.event), position(source.position), isOpen(source.isOpen)
{
    source.event = nullptr;
}

void Cell::makeEvent(Player &player)
{
    event->makeAction(player);
}

void Cell::setEvent(Event *newEvent)
{
    event = newEvent;
}

const Position &Cell::getPosition() const
{
    return position;
}

bool Cell::getIsOpen() const
{
    return isOpen;
}

Event *Cell::getEvent() const
{
    return event;
}

