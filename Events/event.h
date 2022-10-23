#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <set>
#include "../Observable/gamesubject.h"
class Event : public GameSubject
{
public:
    virtual ~Event(){/*std::cout<<"eventDeleted ";*/}
    virtual std::string print() const {return "Event ";}
    friend std::ostream& operator<<(std::ostream& out, const Event & obj){
        out << obj.print();
        return out;
    }
};

#endif // EVENT_H
