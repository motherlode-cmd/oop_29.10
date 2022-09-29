#include "field.h"
#include "eventnone.h"

Field::Field(int height, int width):height(height), width(width)
{
    cells = new Cell *[height];
    for(int i = 0; i < height; i++) {
        cells[i] = new Cell [width];
    }
    for(int i =0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cells[i][j] = Cell(new EventNone(), Position(i,j), i*j < 2);
        }
    }
    positionPlayer = Position(0,0);
}

Field::Field(Field const &newField)
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
    positionPlayer = newField.positionPlayer;
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
        for(int i = 0; i < height; i++) {
            delete [] other.cells[i];
        }
        delete other.cells;
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
    for(int i = 0; i < height; i++) {
        delete [] source.cells[i];
    }
    delete source.cells;
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
        player.makeMove(newPos);
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
