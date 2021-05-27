#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

template <class T>
class BlockingQueue: public std::queue<T> {
    public:
        BlockingQueue(int size);
        ~BlockingQueue();
        void push(T item);
        bool full();
        T pop();

    private:
        int maxSize;
        bool run = true;
        std::mutex readerMutex;
        std::mutex writerMutex;
        std::condition_variable isFull;
        std::condition_variable isEmpty;
};