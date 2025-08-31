#ifndef NATURAL_NUMBERS_GENERATOR_HPP
#define NATURAL_NUMBERS_GENERATOR_HPP

#include <coroutine>
#include <exception>

class NaturalNumbersGenerator {
public:
    struct promise_type {
        int current_value = 0;

        std::suspend_always initial_suspend() { return {}; }
        
        std::suspend_always final_suspend() noexcept { return {}; }
        
        NaturalNumbersGenerator get_return_object() {
            return NaturalNumbersGenerator{
                std::coroutine_handle<promise_type>::from_promise(*this)
            };
        }
        
        std::suspend_always yield_value(int value) {
            current_value = value;
            return {};
        }

        void unhandled_exception() {
            std::terminate();
        }
    };

    using handle_type = std::coroutine_handle<promise_type>;

private:
    handle_type coro;

public:
    explicit NaturalNumbersGenerator(handle_type h) : coro(h) {}
    
    NaturalNumbersGenerator(NaturalNumbersGenerator&& other) noexcept 
        : coro(other.coro) {
        other.coro = {};
    }
    
    NaturalNumbersGenerator& operator=(NaturalNumbersGenerator&& other) noexcept {
        if (this != &other) {
            if (coro) {
                coro.destroy();
            }
            coro = other.coro;
            other.coro = {};
        }
        return *this;
    }
    
    NaturalNumbersGenerator(const NaturalNumbersGenerator&) = delete;
    NaturalNumbersGenerator& operator=(const NaturalNumbersGenerator&) = delete;
    
    ~NaturalNumbersGenerator() {
        if (coro) {
            coro.destroy();
        }
    }

    int next() {
        if (coro && !coro.done()) {
            coro.resume();
            if (!coro.done()) {
                return coro.promise().current_value;
            }
        }
        return -1;
    }
    
    bool has_next() const {
        return coro && !coro.done();
    }
};


NaturalNumbersGenerator generate_natural_numbers(int start = 1, int limit = 100) {
    for (int i = start; i <= limit; ++i) {
        co_yield i;
    }
}

// may overflow
NaturalNumbersGenerator generate_infinite_natural_numbers(int start = 1) {
    int i = start;
    while (true) {
        co_yield i++;
    }
}

#endif // NATURAL_NUMBERS_GENERATOR_HPP
