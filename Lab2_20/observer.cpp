#include "observer.h"

void FileObserver::Update(bool isExist, long size) {

    if(size == -1) {
        this->size = size;
    }

    if(isExist) {
        if(this->size != size) {
            std::cout << "File exists" << std::endl;
            std::cout << "File has been changed, size = " << size << std::endl;
            this->size = size;
        }
        else {
            std::cout << "File exists" << std::endl;
            std::cout << "File hasn't been changed, size = " << size << std::endl;
        }

    }

    else {
        std::cout <<"File doesn't exist" << std::endl;
    }
}
