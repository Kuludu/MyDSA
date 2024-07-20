#include "thread_pool.hpp"

int main() {
    ThreadPool thread_pool(4);

    thread_pool.enqueue([]() { 
        std::cout << "Hello from thread pool!\n"; 
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "I have waited for 1 second.\n"; 
    });

    thread_pool.enqueue([]() { 
        std::cout << "Another task in thread pool!\n"; 
    });

    thread_pool.enqueue([]() { 
        std::cout << "The third task in thread pool!\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "I have waited for 3 second.\n"; 
    });

    return 0;
}