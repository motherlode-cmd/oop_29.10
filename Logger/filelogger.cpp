#include "filelogger.h"
#include <iostream>

FileLogger::FileLogger(std::string fileName)
{
    this->fileName = fileName;
    if(!isFile) {
        outfile.open(fileName,  std::ios::binary);
        if(!outfile.is_open()) {
            outfile.open(fileName);
        }
    }
    isFile = true;
}

FileLogger::~FileLogger()
{
    outfile.close();
}

void FileLogger::log(Level level, std::string str)
{
    if(isFile) {
        outfile<<level<<str<<std::endl;
        outfile.flush();
    }
}

std::string &FileLogger::getFileName()
{
    return fileName;
}




