#ifndef EVENT_H
#define EVENT_H
#include <iostream>
class Event{
public:
    virtual ~Event(){std::cout<<"eventDeleted ";}
};
#endif // EVENT_H
