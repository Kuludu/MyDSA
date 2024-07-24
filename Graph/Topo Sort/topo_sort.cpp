#include <iostream>
#include <vector>
#include "topo_sort.hpp"

using TopoSort::Sort;
using std::vector;

int main() {
    // Possible case
    vector<vector<int>> G = {{1}};

    // Impossible case
    // vector<vector<int>> G = {{1}, {0}};
    
    Sort sorter(G);

    if (sorter.topo_sort()) {
        std::cout << "Topo sort is possible\n";
    } else {
        std::cout << "Topo sort is not possible\n";
    }

    return 0;
}