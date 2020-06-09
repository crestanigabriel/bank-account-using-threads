#include "Semaphore.h"

Semaphore::Semaphore()
{
    //ctor
    _count = 0;
}

Semaphore::~Semaphore()
{
    //dtor
}

void Semaphore::notify() {
    std::lock_guard<decltype(_mutex)> lock(_mutex);
    ++_count;
    _condition.notify_one();
}

void Semaphore::wait() {
    std::unique_lock<decltype(_mutex)> lock(_mutex);
    while(!_count) // Handle spurious wake-ups.
        _condition.wait(lock);
    --_count;
}

bool Semaphore::try_wait() {
    std::lock_guard<decltype(_mutex)> lock(_mutex);
    if(_count) {
        --_count;
        return true;
    }
    return false;
}
