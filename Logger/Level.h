#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include <ostream>
enum Level
{
    Info,
    State,
    Error
};

inline std::ostream& operator << (std::ostream& out, Level& level)
{
    switch(level)
    {
    case Info:
        out << "[INFO]";
        break;
    case State:
        out << "[STATE CHANGE]";
        break;
    case Error:
        out << "[ERROR]";
        break;
    }
    return out;
}
#endif // LEVEL_H
