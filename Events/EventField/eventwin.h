#ifndef EVENTWIN_H
#define EVENTWIN_H
#include "eventField.h"
class EventWin : public EventField
{
public:
    EventWin(){}
    ~EventWin(){}
    void newField(Field & field) override;
    //friend std::ostream& operator << (std::ostream &, EventWin *);
    std::string print() const override {return " -WINER- ";}
};

#endif // EVENTWIN_H
