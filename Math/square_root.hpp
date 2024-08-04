#ifndef __SQRT_HPP__
#define __SQRT_HPP__

#ifndef _GLIBCXX_FUNCTIONAL
#include <functional>
#endif

std::function<double(double)> sqrt = [](double x, double eps = 1e-9) {
    double l = 0, r = x;
    while (r - l > eps) {
        double m = (l + r) / 2;
        if (m * m > x) {
            r = m;
        } else {
            l = m;
        }
    }
    
    return l;
};

#endif
