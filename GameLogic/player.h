#ifndef PLAYER_H
#define PLAYER_H
#include "position.h"
#include <ostream>
#include "../Observable/gamesubject.h"
class Player : public GameSubject
{
public:
    Player() = default;
    Player(const Position &position);
    Player(Player const & newPlayer);
    Player(Player && source);
    Player & operator = (const Player &other);
    Player & operator = (Player && other);
    ~Player(){}
    friend std::ostream& operator << (std::ostream &, const Player &);
    void makeMove(const Position &newPosition);
    int getHealth() const;
    void setHealth(int newHealth);
    const Position &getCurrentPosition() const;
    void gotKey(){key = true;}
    bool keyState(){return key;}

private:
    Position currentPosition;
    int health = 100;
    bool key = false;
};

#endif // PLAYER_H
