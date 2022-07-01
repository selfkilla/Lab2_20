#include "observer.h"

void FileObserver::Update(bool isExist, long size) {

    if (size == -1) { // если размер файла изначальный, то вызов первый
        this->size = size; // обновляем последний размер
    }

    if (isExist) { // если файл существует
        if(this->size != size) { // если размер был изменен
            std::cout << "File exists" << std::endl;
            std::cout << "File has been changed, size = " << size << std::endl;
            this->size = size; // размер обновляем
        }
        else {
            // файл существует
            std::cout << "File exists" << std::endl;
            std::cout << "File hasn't been changed, size = " << size << std::endl;
        }

    }
    // файл не существует
    else {
        std::cout <<"File doesn't exist" << std::endl;
    }
}
