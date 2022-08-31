#ifndef __FIBONACCI_HPP__
#define __FIBONACCI_HPP__

constexpr int fibonacci(const int n) {
    return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

#endif