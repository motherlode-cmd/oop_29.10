#include "position.h"

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

Position::Position(Position const &newPosition)
{
    this->x = newPosition.x;
    this->y = newPosition.y;
}

Position::~Position()
{
}

Position::Position(Position &&source): x(source.x), y(source.y)
{
}

Position &Position::operator = (const Position &other)
{
    if(this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

bool Position::operator ==(const Position &other)
{
    return x == other.x && y == other.y;
}

Position &Position::operator = (Position &&other)
{
    if(this != &other) {
        x = other.x;
        y = other.y;
        other.x = -1;
        other.y = -1;
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

void Position::setX(int newX)
{
    x = newX;
}

int Position::getY() const
{
    return y;
}

void Position::setY(int newY)
{
    y = newY;
}
//const доступ к игроку
