#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
#include "player.h"
//#include "position.h"
class Field
{
public:
    Field() = default;
    Field(int heiht, int width);
    Field(Field const & newField);
    Field & operator = (Field const &other);
    Field & operator = (Field && other);
    Field(Field && source);
    void setNewEvent(Event *event, int x, int y);
    void playerMove(int deltaX, int deltaY, Player & player);
    const Cell & getCell(int i, int j) const;
    int getHeight() const;
    int getWidth() const;
    const Position &getPositionPlayer() const;


protected:
    Cell ** cells = nullptr;
    Position positionPlayer = Position(-1,-1);
    int height = 0;
    int width = 0;
private:
    int abs(int x, int deltaX, int metric);
};

#endif // FIELD_H
