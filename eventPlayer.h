#ifndef EVENTPLAYER_H
#define EVENTPLAYER_H
#include "event.h"
#include "player.h"
class EventPlayer : public Event{
public:
    virtual void makeAction(Player & player) = 0;
};
#endif // EVENTPLAYER_H
