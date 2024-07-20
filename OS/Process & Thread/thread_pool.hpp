#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>

class ThreadPool {
public:
    ThreadPool(size_t num_threads) : stop(false) {
         for(size_t i = 0; i < num_threads; ++i) {
            workers.emplace_back(&ThreadPool::worker, this);
        }
    }

    virtual ~ThreadPool() {
        stop = true;
        cv.notify_all();
        for(auto &worker : workers) {
            worker.join();
        }
    }

    void enqueue(std::function<void()> task) {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            tasks.push(std::move(task));
        }
        cv.notify_one();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queue_mutex;
    std::condition_variable cv;
    std::atomic<bool> stop;

    void worker() {
         while(true) {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(queue_mutex);
                cv.wait(lock, [this] { return stop || !tasks.empty(); });
                if(stop && tasks.empty()) return;
                task = std::move(tasks.front());
                tasks.pop();
            }
            task();
        }
    }
};
