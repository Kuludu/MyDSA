#pragma once

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <chrono>
#include <memory>

class ThreadPool {
public:
    using Task = std::function<void()>;

    explicit ThreadPool(size_t num_core_threads, size_t num_max_threads, std::chrono::milliseconds idle_time)
        : num_core_threads(num_core_threads), num_max_threads(num_max_threads), idle_time(idle_time) {
         for(size_t i = 0; i < num_core_threads; ++i) {
            workers.emplace_back(&ThreadPool::worker, this);
        }
    }

    virtual ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(event_mutex);
            stop = true;
        }
        event_variable.notify_all();
        for(auto &worker : workers) {
            if (worker.joinable()) {
                worker.join();
            }
        }
    }

    template<class T>
    auto enqueue(T task) -> std::future<decltype(task())> {
        auto wrapper = std::make_shared<std::packaged_task<decltype(task())()>>(std::move(task)); 
        {
            std::unique_lock<std::mutex> lock(event_mutex);
            if (stop) {
                throw std::runtime_error("Enqueue on stopped ThreadPool.");
            }

            tasks.emplace([=] {
                (*wrapper)();
            });

            if (workers.size() < num_max_threads && tasks.size() > workers.size()) {
                workers.emplace_back(&ThreadPool::worker, this);
            }
        }
        event_variable.notify_one();

        return wrapper->get_future();
    }

private:
    size_t num_core_threads;
    size_t num_max_threads;
    std::chrono::milliseconds idle_time;

    std::vector<std::thread> workers;
    std::queue<Task> tasks;
    std::mutex event_mutex;
    std::condition_variable event_variable;
    bool stop = false;

    void worker() {
         while(true) {
            Task task;
            {
                std::unique_lock<std::mutex> lock(event_mutex);
                if(event_variable.wait_for(lock, idle_time, [this] { return stop || !tasks.empty(); })) {
                    if(stop && tasks.empty()) return;
                    task = std::move(tasks.front());
                    tasks.pop();
                } else {
                    if(workers.size() > num_core_threads) {
                        auto thread_id = std::this_thread::get_id();
                        auto it = std::find_if(workers.begin(), workers.end(), [&](std::thread &t) { return t.get_id() == thread_id; });
                        if (it != workers.end()) {
                            it->detach();
                            workers.erase(it);
                            return;
                        }
                    }
                }
            }
            if (task) {
                task();
            }
        }
    }
};
