#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <string>

#ifdef _DEBUG
class Timer {
public:
    Timer(const std::string& name);
    ~Timer();
private:
    std::string name_;
    std::chrono::high_resolution_clock::time_point start_;
};

#define DEBUG_TIMER(name) Timer timer##__LINE__(name)
#else
#define DEBUG_TIMER(name)
#endif

#endif // TIMER_H