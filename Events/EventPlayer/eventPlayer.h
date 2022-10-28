#ifndef EVENTPLAYER_H
#define EVENTPLAYER_H
#include "../event.h"
#include "../../GameLogic/humanPlayer.h"

class EventPlayer : public Event{
public:
    virtual void makeAction(HumanPlayer & player) = 0;
};
#endif // EVENTPLAYER_H
