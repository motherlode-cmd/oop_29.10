#ifndef EVENTWIN_H
#define EVENTWIN_H
#include "eventField.h"
class EventWin : public EventField
{
public:
    EventWin();
    int getNumOfType() override {return 3;}
    void newField(Field & field) override;
};

#endif // EVENTWIN_H
