#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <vector>
#include "observer.h"
#include "filestate.h"

class Subject
{
private:
    std::vector<FileObserver*> subs;
public:
    void Attach(FileObserver *observer);
    void Detach(FileObserver *observer);
    void Notify(bool isExist, long size);
};

class FileChecking : public Subject {
private:
    FileState previousFileState;
public:
    FileChecking(std::string name);
    void CheckFile();
    void CheckChanges(bool isExist, long size);
};

#endif // SUBJECT_H
