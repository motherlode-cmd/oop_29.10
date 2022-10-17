#ifndef EVENTWIN_H
#define EVENTWIN_H
#include "eventField.h"
class EventWin : public EventField
{
public:
    EventWin(){std::cout<<"createWin\n";}
    ~EventWin(){std::cout<<"deleteWin\n";}
    void newField(Field & field) override;
    //friend std::ostream& operator << (std::ostream &, EventWin *);
    void print(std::ostream& os) const override {os << "\n -WINER- \n";}
};

#endif // EVENTWIN_H
