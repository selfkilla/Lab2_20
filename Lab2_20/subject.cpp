#include "subject.h"
#include <sys/stat.h>
#include <algorithm>

void Subject::Attach(FileObserver *observer){
    subs.push_back(observer);
}

void Subject::Detach(FileObserver *observer){
    subs.erase(std::remove(subs.begin(), subs.end(), observer), subs.end());
}

void Subject::Notify(bool isExist, long size){
    for(std::vector<FileObserver*>::const_iterator iterator = subs.begin();
        iterator!=subs.end(); iterator++) {
        if(*iterator != 0) {
            (*iterator)->Update(isExist, size);
        }
    }
}

FileChecking::FileChecking(std::string name) : previousFileState(name) {

}

void FileChecking::CheckFile(){
    FileState newestFileState(previousFileState.name);
    CheckChanges(newestFileState.isExist, newestFileState.size);
    previousFileState = newestFileState;
}

void FileChecking::CheckChanges(bool isExist, long size){
    Notify(isExist, size);
}
