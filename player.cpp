#include "player.h"

Player::Player(Position & position):currentPosition(position), health(100){}

Player::Player(Player const &newPlayer):currentPosition(newPlayer.currentPosition), health(newPlayer.health){}

Player &Player::operator = (const Player &other)
{
    if(this != &other) {
        currentPosition = other.currentPosition;
        health = other.health;
    }
    return *this;
}

Player &Player::operator = (Player &&other)
{
    if(this != &other) {
        currentPosition = other.currentPosition;
        health = other.health;
        other.health = 0;
        other.currentPosition = Position(-1,-1);
    }
    return *this;
}

Player::Player(Player &&source):currentPosition(source.currentPosition), health(source.health)
{
    source.health = 0;
    source.currentPosition = Position(-1,-1);
}

void Player::makeMove(const Position & newPosition)
{
    currentPosition = newPosition;
}

int Player::getHealth() const
{
    return health;
}

void Player::setHealth(int newHealth)
{
    health = newHealth;
    if(health > 100) health = 100;
    if(health < 0) health = 0;
}

const Position &Player::getCurrentPosition() const
{
    return currentPosition;
}

