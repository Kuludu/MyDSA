#include <vector>
#include "lower_bound.hpp"

using std::vector;

int main() {
    vector<int> vec = {1, 3, 3, 4, 4, 5};

    auto loc_lower = lower_bound_search(vec.begin(), vec.end(), 3);
    
    return *loc_lower == 3 ? 0 : 1;
}