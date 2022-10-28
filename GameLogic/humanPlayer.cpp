#include "humanPlayer.h"
#include <iostream>
#include <QString>
HumanPlayer::HumanPlayer(const Position & position):currentPosition(position), health(100){}

HumanPlayer::HumanPlayer(HumanPlayer const &newPlayer):currentPosition(newPlayer.currentPosition), health(newPlayer.health), key(newPlayer.key){}

HumanPlayer &HumanPlayer::operator = (const HumanPlayer &other)
{
    if(this != &other) {
        currentPosition = other.currentPosition;
        health = other.health;
        key = other.key;
    }
    return *this;
}

HumanPlayer &HumanPlayer::operator = (HumanPlayer &&other)
{
    if(this != &other) {
        currentPosition = other.currentPosition;
        health = other.health;
        key = other.key;
        other.health = 0;
    }
    return *this;
}

HumanPlayer::HumanPlayer(HumanPlayer &&source):currentPosition(source.currentPosition), health(source.health), key(source.key)
{
    source.health = 0;
}

void HumanPlayer::makeMove(const Position & newPosition)
{
    try {
        if(currentPosition.getX() >= 0 && currentPosition.getY() >= 0)
            currentPosition = newPosition;
        else
            throw(currentPosition);
    } catch (Position pos){
        notify(Level::Error, "Player invalid");
    }
}
//сделать возможность выбора уровня логгирования
//сделать проверку на количество логгеров

int HumanPlayer::getHealth() const
{
    return health;
}

void HumanPlayer::setHealth(int newHealth)
{
    if(health != newHealth) {
        notify(Level::State, "New player's health " + std::to_string(newHealth));
    }
    health = newHealth;
    if(health > 100) health = 100;
    if(health < 0) health = 0;
    if(health == 0) {
        notify(Level::State, "LOSE");
    }
}

const Position &HumanPlayer::getCurrentPosition() const
{
    return currentPosition;
}

std::ostream & operator<<(std::ostream & os, const HumanPlayer & rhs)
{
    os <<"Player's Health after move: "<< rhs.getHealth() << " ";
    return os;
}
