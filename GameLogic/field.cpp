#include "field.h"
#include <cstdlib>
#include <iostream>
#include <QString>
Field::Field(int height, int width):height(height), width(width)
{
    try{
        if(height > 0 && width > 0){
            Event * eventDefault = nullptr;
            int startX = 0;
            int startY = 0;
            cells = new Cell *[height];
            for(int i = 0; i < height; i++) {
                cells[i] = new Cell [width];
            }
            for(int i =0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    cells[i][j] = Cell(eventDefault, Position(i,j), rand() % 4 != 0);
                    if(cells[i][j].getIsOpen()){
                        startX = i;
                        startY = j;
                    }
                }
            }
            positionPlayer = Position(startX,startY);
            positionWin = Position(0,0);
        } else {
            throw (height * width);
        }
    } catch (int errorSize) {

    }
}

Field::Field(Field const &newField): positionPlayer(newField.positionPlayer),positionWin(newField.positionWin),
    height(newField.height), width(newField.width)
{
    height = newField.height;
    width = newField.width;
    cells = new Cell *[height];
    for(int i = 0; i < height; i++) {
        cells[i] = new Cell [width];
    }
    for(int i =0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cells[i][j] = newField.cells[i][j];
        }
    }
}

Field &Field::operator = (const Field &other)
{
    if(this != &other) {
        for(int i = 0; i < height; i++) {
            delete [] cells[i];
        }
        delete cells;
        height = other.height;
        width = other.width;
        cells = new Cell *[height];
        for(int i = 0; i < height; i++) {
            cells[i] = new Cell [width];
        }
        for(int i =0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                cells[i][j] = other.cells[i][j];
            }
        }
        positionPlayer = other.positionPlayer;
        positionWin = other.positionPlayer;
    }
    return *this;
}

Field &Field::operator = (Field && other)
{
    if(this != &other) {
        for(int i = 0; i < height; i++) {
            delete [] cells[i];
        }
        delete cells;
        height = other.height;
        width = other.width;
        cells = new Cell *[height];
        for(int i = 0; i < height; i++) {
            cells[i] = new Cell [width];
        }
        for(int i =0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                cells[i][j] = other.cells[i][j];
            }
        }
        positionPlayer = other.positionPlayer;
        positionWin = other.positionPlayer;
    }
    return *this;
}

Field::Field(Field &&source): positionPlayer(source.positionPlayer), positionWin(source.positionWin),
   height(source.height), width(source.width)
{
    cells = new Cell *[height];
    for(int i = 0; i < height; i++) {
        cells[i] = new Cell [width];
    }
    for(int i =0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cells[i][j] = source.cells[i][j];
        }
    }
    source.height = 0;
    source.width = 0;
}

Field::~Field()
{
    for(int i = 0; i < height; i++) {
        delete [] cells[i];
    }
    delete cells;
}

std::ostream & operator<<(std::ostream & os, const Field & rhs)
{
    os <<" PlayerPosition : ("<< rhs.getPositionPlayer().getX() + 1 <<"; " << rhs.getPositionPlayer().getY() + 1 << ") ";
    return os;
}


void Field::setNewEvent(Event *event, int x, int y)
{
    try {
    if(validXY(x,y))
        cells[x][y].setEvent(event);
    else
        throw(Position(x,y));
    } catch(Position invalidPos) {
        notify(Level::Error, std::string("Cannot set Event in cell [{},{}]", x, y));
    }
}

void Field::playerMove(int deltaX, int deltaY)
{
    try {
        if(height > 0 && width > 0) {
            try{
                Position newPos(Position(abs(positionPlayer.getX(), deltaX, height), abs(positionPlayer.getY(), deltaY, width)));
                if(cells[newPos.getX()][newPos.getY()].getIsOpen() && validPosition(newPos)) {
                    positionPlayer = newPos;
                    notify(Level::Info, "Player's new position (" + std::to_string(newPos.getX())
                           +" ; " + std::to_string(newPos.getY()) + ")" );
                } else {
                    throw(newPos);
                }
            }catch(Position invalidPos) {
                notify(Level::Error, "Cannot make move on blocked Cell");
            }
      } else {
            throw(0);
        }
    } catch(int s) {
        notify(Level::Error, "Cannot make move on invalid field");
    }
}

int Field::getHeight() const
{
    return height;
}

int Field::getWidth() const
{
    return width;
}

void Field::setCell(int x, int y, const Cell &cell)
{
    try{
        if(validXY(x,y)) {
            cells[x][y] = cell;
        } else {
            throw(Position(x,y));
        }
    }catch(Position invalidPos) {
        notify(Level::Error, std::string("Cannot set cell [{},{}] with invalid pos", x, y));
    }
}

Event *Field::getCurrentEvent()
{
    try {
        if(validPosition(positionPlayer))
            return cells[positionPlayer.getX()][positionPlayer.getY()].getEvent();
        else
            throw(positionPlayer);
    } catch(Position invalidPos) {
        notify(Level::Error, "Invalid player pos");
        return nullptr;
    }
}

void Field::setPositionWin(int x, int y)
{
    try {
        if (validXY(x,y))
            positionWin = Position(x,y);
        else
            throw(Position(x,y));
    } catch(Position pos) {
        notify(Level::Error, "Invalid WINNER position");
    }
}

void Field::unlockWin()
{
    cells[positionWin.getX()][positionWin.getY()].setIsOpen(true);
}

void Field::unlockCell(int x, int y)
{
    try{
        if(validXY(x,y))
            cells[x][y].setIsOpen(true);
        else
            throw(Position(x,y));
    } catch(Position pos) {
        notify(Level::Error,"Cannot unlock cell");
    }
}

void Field::lockCell(int x, int y)
{
    try{
        if(validXY(x,y))
            cells[x][y].setIsOpen(false);
        else
            throw(Position(x,y));
    } catch(Position pos) {
        notify(Level::Error,"Cannot lock cell ");
    }
}

bool Field::isWin()
{
    return positionPlayer.getX() == positionWin.getX() && positionPlayer.getY() == positionWin.getY();
}

const Position &Field::getPositionPlayer() const
{
    return positionPlayer;
}

int Field::abs(int x, int deltaX, int metric)
{
    if(x + deltaX >= 0) return (x + deltaX) % metric;
    else return (metric + deltaX) % metric;
}

