#ifndef EVENTUNLOCK_H
#define EVENTUNLOCK_H
#include "eventField.h"

class EventUnlock : public EventField
{
public:
    EventUnlock(){std::cout<<"createUnlock\n";}
    ~EventUnlock(){std::cout<<"deleteUnlock\n";}
    void newField(Field & field) override;
    //friend std::ostream& operator << (std::ostream &, EventUnlock *);
    void print(std::ostream& os) const override {os << "Unlock some cells";}
};

#endif // EVENTUNLOCK_H
