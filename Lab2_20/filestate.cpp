#include "filestate.h"
#include <sys/stat.h>
FileState::FileState(std::string fileName)
{
    this->name = fileName;
    struct stat stat_buf;
    isExist = stat(fileName.c_str(), &stat_buf) == 0;
    size = stat_buf.st_size;
}
