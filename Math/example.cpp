#include <iostream>
#include "gcd.hpp"
#include "lcm.hpp"
#include "fibonacci.hpp"

int main() {
    std::cout << gcd(10, 15) << std::endl;

    std::cout << lcm(10, 15) << std::endl;

    std::cout << fibonacci(10) << std::endl;

    return 0;
}