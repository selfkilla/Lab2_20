#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <iostream>

class IObserver {
public:
    virtual void Update(bool isExist, long size);
};


class FileObserver : IObserver {
private:
    long size = -1;
public:
    void Update(bool isExist, long size);
};

#endif // OBSERVER_H
