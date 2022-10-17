#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H
#include "logger.h"
#include <mutex>
class ConsoleLogger : public Logger
{
public:
    std::mutex m;
    ConsoleLogger();
    ~ConsoleLogger();
    void log(/*Level level, */const Player & p) override{std::lock_guard<std::mutex> guard(m); std::cout<<p;}
    void log(/*Level level, */const Field & f) override{std::lock_guard<std::mutex> guard(m); std::cout<<f;}
    void log(/*Level level, */const Event & e) override{std::lock_guard<std::mutex> guard(m); std::cout<<e;}
    void log(std::string && s) override{std::lock_guard<std::mutex> guard(m); std::cout<<s;}
};

#endif // CONSOLELOGGER_H
