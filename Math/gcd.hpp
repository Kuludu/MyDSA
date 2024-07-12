#ifndef __GCD_HPP__
#define __GCD_HPP__

#ifndef _GLIBCXX_FUNCTIONAL
#include <functional>
#endif

auto gcd = [](auto& a, auto& b) -> int {
        return b ? gcd(b, a % b) : a;
    };

#endif