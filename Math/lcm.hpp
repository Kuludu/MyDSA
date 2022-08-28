#ifndef __LCM_HPP__
#define __LCM_HPP__

#ifndef _GLIBCXX_FUNCTIONAL
#include <functional>
#endif

#ifndef __GCD_HPP__
#include "gcd.hpp"
#endif

std::function<int(int, int)> lcm = [](int a, int b) -> int {
        return a * b / gcd(a, b);
    };

#endif