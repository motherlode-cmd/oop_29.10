#include "position.h"

Position::Position(int x, int y):x(x), y(y) {}

Position::Position(Position const &newPosition):x(newPosition.x), y(newPosition.y) {}

Position::~Position() {x = -1; y = -1;}

Position::Position(Position &&source): x(source.x), y(source.y) {}

Position &Position::operator = (const Position &other)
{
    if(this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

bool Position::operator == (const Position &other)
{
    return x == other.x && y == other.y;
}

Position &Position::operator = (Position &&other)
{
    if(this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;

}
void Position::setPosition(int x, int y){
    this->x = x;
    this->y = y;
}

int Position::getX() const
{
    return x;
}

int Position::getY() const
{
    return y;
}

//const доступ к игроку
