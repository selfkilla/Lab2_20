#include "subject.h"
#include <sys/stat.h>
#include <algorithm>

// метод подписки
void Subject::Attach(FileObserver *observer){
    subs.push_back(observer); // добавление наблюдателя
}

// метод отписки
void Subject::Detach(FileObserver *observer){
    // удаление наблюдателя
    subs.erase(std::remove(subs.begin(), subs.end(), observer), subs.end());
}

// метод оповещения
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
    FileState newestFileState(previousFileState.name); // получаем новое состояние файла
    CheckChanges(newestFileState.isExist, newestFileState.size); // проверяем изменения
    previousFileState = newestFileState; // обновляем состояние файла
}

void FileChecking::CheckChanges(bool isExist, long size){
    Notify(isExist, size);
}
