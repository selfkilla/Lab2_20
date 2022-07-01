#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <iostream>

class IObserver { // интерфейс observer, метод Update вызывается при каждом изменении
public:
    virtual void Update(bool isExist, long size); // абстрактный метод обновления
};


class FileObserver : IObserver { // конкретная реализация observer
private:
    long size = -1; // в этой переменной храним последний размер файла
public:
    void Update(bool isExist, long size); // метод, уведомляющий об изменениях файла
};

#endif // OBSERVER_H
