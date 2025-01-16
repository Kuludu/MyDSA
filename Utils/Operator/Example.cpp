#include <iostream>
#include "Add.cpp"
#include "Divide.cpp"

int main() {
    int a = 1, b = 2;

    Add<int, int> add(a, b);
    Divide<int, int> divide(a, b);
    Divide<int, int> ill_divide(a, 0);

    std::cout << add.execute() << std::endl;
    std::cout << divide.execute() << std::endl;
    try {
        std::cout << ill_divide.execute() << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}