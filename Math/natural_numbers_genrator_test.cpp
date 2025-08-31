#include <iostream>
#include <iomanip>
#include "natural_numbers_generator.hpp"

int main() {
    std::cout << "Gen 1-20:" << std::endl;
    auto generator = generate_natural_numbers(1, 20);
    
    int count = 0;
    while (generator.has_next()) {
        int num = generator.next();
        if (num != -1) {
            std::cout << std::setw(3) << num;
            count++;
            if (count % 10 == 0) {
                std::cout << std::endl;
            } else {
                std::cout << " ";
            }
        }
    }
    if (count % 10 != 0) {
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Gen infinite (first 30):" << std::endl;
    auto infinite_generator = generate_infinite_natural_numbers(1);
    
    for (int i = 0; i < 30 && infinite_generator.has_next(); ++i) {
        int num = infinite_generator.next();
        if (num != -1) {
            std::cout << std::setw(3) << num;
            if ((i + 1) % 10 == 0) {
                std::cout << std::endl;
            } else {
                std::cout << " ";
            }
        }
    }
    std::cout << std::endl;

    std::cout << "Gen 50-59:" << std::endl;
    auto custom_generator = generate_natural_numbers(50, 59);
    
    count = 0;
    while (custom_generator.has_next()) {
        int num = custom_generator.next();
        if (num != -1) {
            std::cout << num << " ";
            count++;
        }
    }
    std::cout << std::endl;
}