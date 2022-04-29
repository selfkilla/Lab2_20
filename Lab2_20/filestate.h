#ifndef FILESTATE_H
#define FILESTATE_H

#include <string>
#include <sys/stat.h>
class FileState
{
public:
    std::string name;
    long size;
    bool isExist;
    FileState(std::string fileName);
};

#endif // FILESTATE_H
