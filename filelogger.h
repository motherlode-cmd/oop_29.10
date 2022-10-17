#ifndef FILELOGGER_H
#define FILELOGGER_H
#include "logger.h"

class FileLogger : public Logger
{
public:
    FileLogger() = default;
    FileLogger(std::string fileName);
    ~FileLogger();
    void log(/*Level level, */const Player & p) override;
    void log(/*Level level, */const Field & f) override;
    void log(/*Level level, */const Event &e) override;
    void log(std::string && s) override{ outfile<<s; outfile.flush();}
    //void print(Message && mes);
private:
    std::ofstream outfile;
};

#endif // FILELOGGER_H
