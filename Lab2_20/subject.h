#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <vector>
#include "observer.h"
#include "filestate.h"


// Класс, который отслеживает всех наблюдателей и предоставляет возможность
// добавлять или удалять наблюдателей
class Subject
{
private:
    std::vector<FileObserver*> subs; // все наблюдатели
public:
    void Attach(FileObserver *observer); // добавить наблюдателя
    void Detach(FileObserver *observer); // удалить наблюдателя
    void Notify(bool isExist, long size); // оповестить всех наблюдателей
};

class FileChecking : public Subject {
private:
    FileState previousFileState; // в этой переменной храним предыдущее состояние файла
public:
    FileChecking(std::string name);
    void CheckFile(); // проверка файла на одно из состояний
    void CheckChanges(bool isExist, long size); // проверка изменений
};

#endif // SUBJECT_H
