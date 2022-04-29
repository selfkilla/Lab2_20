#include <iostream>
#include <chrono>
#include <thread>

#include "observer.h"
#include "subject.h"

int main() {

    FileChecking checking("filename.txt");
    FileObserver observer;
    checking.Attach(&observer);

    for(;;){
        checking.CheckFile();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
