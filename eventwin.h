#ifndef EVENTWIN_H
#define EVENTWIN_H
#include "eventField.h"
class EventWin : public EventField
{
public:
    EventWin(){std::cout<<"createWin\n";}
    ~EventWin(){std::cout<<"deleteWin\n";}
    void newField(Field & field) override;
};

#endif // EVENTWIN_H
