#ifndef _GLIBCXX_FUNCTIONAL
#include <functional>
#endif

std::function<int(int, int)> gcd = [](int a, int b) -> int {
        return b ? gcd(b, a % b) : a;
    };