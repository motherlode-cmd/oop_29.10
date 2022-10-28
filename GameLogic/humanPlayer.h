#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "position.h"
#include "Player.h"
#include <ostream>
class HumanPlayer : public Player
{
public:
    HumanPlayer() = default;
    HumanPlayer(const Position &position);
    HumanPlayer(HumanPlayer const & newPlayer);
    HumanPlayer(HumanPlayer && source);
    HumanPlayer & operator = (const HumanPlayer &other);
    HumanPlayer & operator = (HumanPlayer && other);
    ~HumanPlayer(){}
    friend std::ostream& operator << (std::ostream &, const HumanPlayer &);
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

#endif // HUMANPLAYER_H
