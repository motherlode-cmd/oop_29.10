#include "player.h"
#include "message.h"
#include <iostream>
#include <QString>
Player::Player(const Position & position):currentPosition(position), health(100){}

Player::Player(Player const &newPlayer):currentPosition(newPlayer.currentPosition), health(newPlayer.health), key(newPlayer.key){}

Player &Player::operator = (const Player &other)
{
    if(this != &other) {
        currentPosition = other.currentPosition;
        health = other.health;
        key = other.key;
    }
    return *this;
}

Player &Player::operator = (Player &&other)
{
    if(this != &other) {
        currentPosition = other.currentPosition;
        health = other.health;
        key = other.key;
        other.health = 0;
        other.currentPosition = Position(-1,-1);
    }
    return *this;
}

Player::Player(Player &&source):currentPosition(source.currentPosition), health(source.health), key(source.key)
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

//Message Player::getMessage()
//{
//    std::string s("Player's health is " + QString::number(health).toStdString() + '\n');
//    Message m(s);
//    return m;
//}

std::ostream & operator<<(std::ostream & os, const Player & rhs)
{
    os <<"Player's Health after move: "<< rhs.getHealth() << " ";
    return os;
}
