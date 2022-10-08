#include "eventnone.h"

void EventNone::makeAction(Player &player)
{
    player.setHealth(player.getHealth() - 10);
}
