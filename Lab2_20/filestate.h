#ifndef FILESTATE_H
#define FILESTATE_H

#include <string>
#include <sys/stat.h>
class FileState
{
public:
    std::string name; // имя файла
    long size; // размер
    bool isExist; // переменная, проверяющая, существует ли файл
    FileState(std::string fileName);
};

#endif // FILESTATE_H
