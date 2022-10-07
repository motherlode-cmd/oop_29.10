#ifndef EVENTFIELD_H
#define EVENTFIELD_H
#include "field.h"
#include "event.h"
class EventField : public Event{
public:
    virtual void newField(Field & field) = 0;
};
#endif // EVENTFIELD_H
