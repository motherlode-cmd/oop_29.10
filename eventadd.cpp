#include "eventadd.h"

void EventAdd::makeAction(Player &player)
{
    player.setHealth(player.getHealth() + 10);
}
