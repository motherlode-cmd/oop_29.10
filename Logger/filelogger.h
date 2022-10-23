#ifndef FILELOGGER_H
#define FILELOGGER_H
#include <fstream>
#include <string>
#include "Logger.h"
class FileLogger : public Logger
{
public:
    FileLogger(std::string fileName);
    ~FileLogger();
    void log(Level level, std::string str) override;
    std::string & getFileName();
    bool operator == (const FileLogger & other) {
        return fileName == other.fileName;
    }
private:
    std::ofstream outfile;
    std::string fileName;
    bool isFile = false;
};

#endif // FILELOGGER_H
