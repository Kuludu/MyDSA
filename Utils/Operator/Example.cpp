#include <iostream>
#include "Add.cpp"

int main() {
    int a = 1, b = 2;

    Add<int, int> add(a, b);

    std::cout << add.execute() << std::endl;

    return 0;
}