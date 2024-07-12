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
    
    auto producer = [&](std::stop_token st, int id) {
        int i = 0;
        while (!st.stop_requested()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate production time
            std::unique_lock<std::mutex> lock(mtx); // Acquire lock
            cv.wait(lock, [&]() { return buffer.size() < MAX_BUFFER_SIZE; }); // Wait for buffer to be empty
            std::cout << "Producer " << id << " produced: " << i++ << std::endl; 
            buffer.push(i); // Push to buffer
            cv.notify_all(); // Notify consumers or other producers
        }
        std::cout << "Producer " << id << " stopped" << std::endl; 
    };

    auto consumer = [&](std::stop_token st, int id) {
        while (!st.stop_requested()) {
            std::unique_lock<std::mutex> lock(mtx); // Acquire lock
            cv.wait(lock, [&]() { return !buffer.empty(); }); // Wait for buffer to be non-empty
            int item = buffer.front();
            buffer.pop(); // Pop from buffer
            std::cout << "Consumer " << id << " consumed: " << item << std::endl;
            lock.unlock(); // Release lock explictly
            cv.notify_all(); // Notify producers or other consumers
            std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Simulate consumption time
        }
        std::cout << "Consumer " << id << " stopped" << std::endl; 
    };

    std::jthread producer_thread[2];
    std::jthread consumer_threads[4];
    for (int i = 0; i < 2; ++i) {
        producer_thread[i] = std::jthread(producer, i);
    }
    for (int i = 0; i < 4; ++i) {
        consumer_threads[i] = std::jthread(consumer, i);
    }

    std::string operation; 
    while (std::cin >> operation && operation != "exit") {
        if (operation =="quit_producer") {
            for (int i = 0; i < 2; ++i) {
                producer_thread[i].request_stop();
            }
            std::cout << "Producer threads stopped" << std::endl;
        }
        if (operation == "quit_consumer") {
            for (int  i = 0; i < 4; i++) {
                consumer_threads[i].request_stop();
            }
            std::cout << "Consumer threads stopped" << std::endl;
        }
    }

    return 0;
}