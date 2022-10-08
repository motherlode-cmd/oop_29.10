#include "starteventfield.h"

StartEventField::StartEventField(EventField * event)
{
    eventField = event;
}

void StartEventField::event(Event *event, Field &field, Player &player)
{
    eventField->newField(field);
}

