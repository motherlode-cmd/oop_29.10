#ifndef LOGGEROBSERVER_H
#define LOGGEROBSERVER_H

#include "Observer.h"
#include <vector>

class LoggerObserver : public Observer
{
public:
    void clear() override;
    LoggerObserver() = default;
    ~LoggerObserver();
    void addLogger(Logger * log) override;
    void deleteLogger(Logger * log) override;
    void addLevel(Level level) override;
    void deleteLevel(Level level) override;
    void update(Level level, std::string s) override;
private:
    int findLevel(Level level);
    std::set <Logger*> logs;
    std::vector <Level> levels;
};

#endif // LOGGEROBSERVER_H
