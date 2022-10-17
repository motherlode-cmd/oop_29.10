#ifndef EVENTLOCK_H
#define EVENTLOCK_H
#include "eventField.h"

class EventLock : public EventField
{
public:
    EventLock(){std::cout<<"createLock\n";}
    ~EventLock(){std::cout<<"deleteLock\n";}
    void newField(Field & field) override;
    //friend std::ostream& operator << (std::ostream &, EventLock *);
    void print(std::ostream& os) const override {os << "Locked some cells ;(";}
};

#endif // EVENTLOCK_H
