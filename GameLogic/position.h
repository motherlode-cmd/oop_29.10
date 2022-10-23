#ifndef POSITION_H
#define POSITION_H


class Position
{
public:
    Position() = default;
    Position(int x, int y);
    Position(Position const & newPosition);
    ~Position();
    Position(Position && source);
    Position & operator = (const Position &other);
    Position & operator = (Position && other);
    bool operator == (const Position & other);
    void setPosition(int x, int y);
    int getX() const;
    int getY() const;
private:
    int x = -1;
    int y = -1;
};

#endif // POSITION_H
