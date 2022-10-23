#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H
#include <iostream>
#include <mutex>
#include "Logger.h"
class ConsoleLogger : public Logger
{
public:
    std::mutex m;
    ConsoleLogger() = default;
    ~ConsoleLogger();
    void log(Level level, std::string str) override;
    bool operator == (const ConsoleLogger &) {
        return true;
    }
protected:
    //std::ostream& os;
};

#endif // CONSOLELOGGER_H
