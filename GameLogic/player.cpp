#include "player.h"
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
    }
    return *this;
}

Player::Player(Player &&source):currentPosition(source.currentPosition), health(source.health), key(source.key)
{
    source.health = 0;
}

void Player::makeMove(const Position & newPosition)
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

int Player::getHealth() const
{
    return health;
}

void Player::setHealth(int newHealth)
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

const Position &Player::getCurrentPosition() const
{
    return currentPosition;
}

std::ostream & operator<<(std::ostream & os, const Player & rhs)
{
    os <<"Player's Health after move: "<< rhs.getHealth() << " ";
    return os;
}
