#include "field.h"
#include <cstdlib>
#include <iostream>

Field::Field(int height, int width):height(height), width(width)
{
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

void Field::setNewEvent(Event *event, int x, int y)
{
    if(x >= 0 && y >= 0 && x < width && y < height)
        cells[x][y].setEvent(event);
    else
        std::cout<<"wron k\n";
}

void Field::playerMove(int deltaX, int deltaY)
{
    Position newPos(Position(abs(positionPlayer.getX(), deltaX, width), abs(positionPlayer.getY(), deltaY, height)));
    if(cells[newPos.getX()][newPos.getY()].getIsOpen()) {
        positionPlayer = newPos;
    }
}

const Cell &Field::getCell(int i, int j) const
{
    return cells[i][j];
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
    if(x < width && x >= 0 && y >= 0 && y < height) {
        cells[x][y] = cell;
    }
}

Event *Field::getCurrentEvent()
{
    return cells[positionPlayer.getX()][positionPlayer.getY()].getEvent();
}

Event *Field::getEvent(int i, int j)
{
    return cells[i][j].getEvent();
}

void Field::setPositionWin(int x, int y)
{
    positionWin = Position(x,y);
}

void Field::unlockWin()
{
    cells[positionWin.getX()][positionWin.getY()].setIsOpen(true);
}

void Field::unlockCell(int x, int y)
{
    cells[x][y].setIsOpen(true);
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
