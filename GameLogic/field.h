#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
#include "../Observable/gamesubject.h"
class Field : public GameSubject
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
    friend class FieldView;
    int getHeight() const;
    int getWidth() const;
    const Position &getPositionPlayer() const;
    void setCell(int x, int y,const Cell & cell);
    Event * getCurrentEvent();
    void setPositionWin(int x, int y);
    void unlockWin();
    void unlockCell(int x, int y);
    void lockCell(int x, int y);
    friend void newField(Field & field);
    bool isWin();

private:
    bool validXY(int x, int y) {
        return x >= 0 && y >= 0 && y < width && x < height;
    }
    bool validPosition(const Position & pos) {
        return pos.getX() >= 0 && pos.getY() >= 0 && pos.getY() < width && pos.getX() < height;
    }
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
