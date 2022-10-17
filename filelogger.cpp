#include "filelogger.h"

FileLogger::FileLogger(std::string fileName)
{
    outfile.open(fileName,  std::ios::binary);
}

FileLogger::~FileLogger()
{
    outfile.close();
}

void FileLogger::log(const Player &p)
{
    outfile<<p;
    outfile.flush();
}

void FileLogger::log(const Field &f)
{
    outfile<<f;
    outfile.flush();
}

void FileLogger::log(const Event &e)
{
    outfile << e;
    outfile.flush();
}

