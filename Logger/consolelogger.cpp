#include "consolelogger.h"
#include <iostream>

ConsoleLogger::~ConsoleLogger()
{
//    std::cout<<"deletedCON\n"<<std::endl;
}

void ConsoleLogger::log(Level level, std::string str)
{
    std::lock_guard<std::mutex> guard(m);
    std::cout<<level<<str<<std::endl;
}
