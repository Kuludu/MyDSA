#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

int main() {
    std::mutex mtx;
    std::condition_variable cv;
    std::queue<int> buffer;
    const int MAX_BUFFER_SIZE = 5;
    
    auto producer = [&](int id) {
        for (int i = 0; ; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate production time
            std::unique_lock<std::mutex> lock(mtx); // Acquire lock
            cv.wait(lock, [&]() { return buffer.size() < MAX_BUFFER_SIZE; }); // Wait for buffer to be empty
            std::cout << "Producer " << id << " produced: " << i << std::endl; 
            buffer.push(i); // Push to buffer
            cv.notify_all(); // Notify consumers or other producers
        }
    };

    auto consumer = [&](int id) {
        for (;;) {
            std::unique_lock<std::mutex> lock(mtx); // Acquire lock
            cv.wait(lock, [&]() { return !buffer.empty(); }); // Wait for buffer to be non-empty
            int item = buffer.front();
            buffer.pop(); // Pop from buffer
            std::cout << "Consumer " << id << " consumed: " << item << std::endl;
            lock.unlock(); // Release lock explictly
            cv.notify_all(); // Notify producers or other consumers
            std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Simulate consumption time
        }
    };

    std::thread producer_thread[2];
    std::thread consumer_threads[4];
    for (int i = 0; i < 2; ++i) {
        producer_thread[i] = std::thread(producer, i);
    }
    for (int i = 0; i < 4; ++i) {
        consumer_threads[i] = std::thread(consumer, i);
    }
    for (int i = 0; i < 2; ++i) {
        producer_thread[i].join();
    }
    for (int i = 0; i < 4; ++i) {
        consumer_threads[i].join();
    }

    return 0;
}