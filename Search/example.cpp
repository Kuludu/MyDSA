#include <iostream>
#include <vector>
#include "upper_bound.hpp"
#include "lower_bound.hpp"

using std::cout;
using std::vector;

int main() {
    vector<int> vec = {1, 3, 3, 4, 4, 5};

    auto loc_upper = upper_bound_search(vec.begin(), vec.end(), 3);
    cout << "The first element greater than 3 is " << *loc_upper << '\n';
    auto loc_upper_stl = std::upper_bound(vec.begin(), vec.end(), 3);
    cout << "(STL) The first element greater than 3 is " << *loc_upper_stl << '\n';

    auto loc_lower = lower_bound_search(vec.begin(), vec.end(), 3);
    cout << "The first element less or equal to 3 is " << *loc_lower << '\n';
    auto loc_lower_stl = std::lower_bound(vec.begin(), vec.end(), 3);
    cout << "(STL) The first element less or equal to 3 is " << *loc_lower_stl << '\n';


    return 0;
}