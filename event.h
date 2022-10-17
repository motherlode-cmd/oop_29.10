#ifndef EVENT_H
#define EVENT_H
#include <iostream>
class Event{
public:
    virtual ~Event(){/*std::cout<<"eventDeleted ";*/}
    virtual void print(std::ostream & os) const {os<<"Event ";}
    friend std::ostream& operator<<(std::ostream& out, const Event & obj){
        obj.print(out);
        return out;
    }
};

#endif // EVENT_H

