#include <vector>
#include "upper_bound.hpp"

using std::vector;

int main() {
    vector<int> vec = {1, 3, 3, 4, 4, 5};

    auto loc_upper = upper_bound_search(vec.begin(), vec.end(), 3);
    
    return *loc_upper == 4 ? 0 : 1;
}