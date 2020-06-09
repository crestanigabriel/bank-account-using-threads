#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore
{
    public:
        Semaphore();
        virtual ~Semaphore();

        void notify();
        void wait();
        bool try_wait();
    protected:

    private:
        std::mutex _mutex;
        std::condition_variable _condition;
        unsigned long _count;
};

#endif // SEMAPHORE_H
