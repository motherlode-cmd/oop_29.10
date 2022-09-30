#include "eventnone.h"

EventNone::EventNone()
{}

void EventNone::makeAction(Player &player)
{
    player.setHealth(player.getHealth() - 10);
}
