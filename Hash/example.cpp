#include <iostream>
#include "hash_map.hpp"

int main() {
    HashMap<int, int> map(10);

    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);
    map.insert(4, 40);
    map.insert(5, 50);

    std::cout << map.get(1) << std::endl;

    map.remove(2);
    map.remove(4);

    std::cout << map.get(3) << std::endl;

    // Exception will occorr if the key is not found
    // std::cout << map.get(4) << std::endl;

    return 0;
}