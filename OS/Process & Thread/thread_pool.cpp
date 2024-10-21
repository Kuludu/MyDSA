#include <iostream>
#include "thread_pool.hpp"

int main() {
    ThreadPool pool(2, 4, std::chrono::seconds(10));

    auto result = pool.enqueue([] {
        std::cout << "Hello from task 1\n";
        return 1;
    });

    std::this_thread::sleep_for(std::chrono::seconds(5));

    pool.enqueue([] {
        std::cout << "Hello from task 2\n";
    });

    std::cout << "Result from task 1: " << result.get() << "\n";

    std::this_thread::sleep_for(std::chrono::seconds(11));

    return 0;
}