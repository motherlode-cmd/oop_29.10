#include "eventadd.h"

EventAdd::EventAdd()
{}

void EventAdd::makeAction(Player &player)
{
    player.setHealth(player.getHealth() + 10);
}
