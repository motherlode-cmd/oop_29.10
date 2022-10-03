#include "field.h"
#include "eventnone.h"
#include <iostream>
//Field::Field()
//{
////    cells = new Cell *[height];
////    for(int i = 0; i < height; i++) {
////        cells[i] = new Cell [width];
////    }
////    for(int i = 0; i < height; i++) {
////        for(int j = 0; j < width;  j++) {
////            cells[i][j] = Cell(new EventNone(), Position(i,j), i!=j+1);
////        }
////    }

//}

Field::Field(int height, int width):height(height), width(width)
{
    int startX = 0;
    int startY = 0;
    cells = new Cell *[height];
    for(int i = 0; i < height; i++) {
        cells[i] = new Cell [width];
    }
    for(int i =0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cells[i][j] = Cell(new EventNone(), Position(i,j), i!=j);
            if(cells[i][j].getIsOpen()){
                startX = i;
                startY = j;
            }
        }
    }
    positionPlayer = Position(startX,startY);

}

Field::Field(Field const &newField): positionPlayer(newField.positionPlayer),
    height(newField.height), width(newField.width)
{
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
    }
    return *this;
}

Field &Field::operator =(Field && other)
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
    }
    return *this;
}

Field::Field(Field &&source): positionPlayer(source.positionPlayer),
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
    std::cout<<"delete ";
    for(int i = 0; i < height; i++) {
        delete [] cells[i];
    }
    delete cells;
}

void Field::setNewEvent(Event *event, int x, int y)
{
    cells[x][y].setEvent(event);
}

void Field::playerMove(int deltaX, int deltaY, Player &player)
{
    Position newPos(Position(abs(positionPlayer.getX(), deltaX, width), abs(positionPlayer.getY(), deltaY, height)));
    if(cells[newPos.getX()][newPos.getY()].getIsOpen()) {
        positionPlayer = newPos;
        cells[positionPlayer.getX()][positionPlayer.getY()].makeEvent(player);
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

const Position &Field::getPositionPlayer() const
{
    return positionPlayer;
}


int Field::abs(int x, int deltaX, int metric)
{
    if(x + deltaX >= 0) return (x + deltaX) % metric;
    else return (metric + deltaX) % metric;
}
