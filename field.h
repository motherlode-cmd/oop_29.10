#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
//#include "position.h"
class Field
{
public:
    Field(int heiht = 3, int width = 3);
    Field(Field const & newField);
    Field & operator = (Field const &other);
    Field & operator = (Field && other);
    Field(Field && source);
    friend std::ostream& operator << (std::ostream &, const Field &);
    ~Field();
    void setNewEvent(Event *event, int x, int y);
    void playerMove(int deltaX, int deltaY);
    const Cell & getCell(int i, int j) const;
    int getHeight() const;
    int getWidth() const;
    const Position &getPositionPlayer() const;
    friend void newField(Field & field);
    void setCell(int x, int y,const Cell & cell);
    Event * getCurrentEvent();
    void setPositionWin(int x, int y);
    void unlockWin();
    void unlockCell(int x, int y);
//    Message getMessage();
private:

protected:
    Cell ** cells = nullptr;
    Position positionPlayer = Position(0,0);
    Position positionWin = Position(1,1);
    int height = 3;
    int width = 3;
private:
    int abs(int x, int deltaX, int metric);
};

#endif // FIELD_H
