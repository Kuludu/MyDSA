#include "vector.hpp"
#include <iostream>
#include <string>

int main() {
    VariantVector vec;
    
    std::cout << "Testing push_back..." << std::endl;
    
    int idx1 = vec.push_back(42);
    std::cout << "Added int 42 at index: " << idx1 << std::endl;
    
    int idx2 = vec.push_back(std::string("Hello"));
    std::cout << "Added string 'Hello' at index: " << idx2 << std::endl;

    int idx3 = vec.push_back(10.1);
    std::cout << "Added double 10.0 at index: " << idx3 << std::endl;

    std::cout << "Vector size: " << vec.size() << std::endl;
    
    std::cout << "\nTesting index access..." << std::endl;
    
    auto& elem0 = vec[0];
    auto& elem1 = vec[1];
    auto& elem2 = vec[2];
    
    std::visit([](const auto& value) {
        std::cout << "Element 0: " << value << std::endl;
    }, elem0);
    
    std::visit([](const auto& value) {
        std::cout << "Element 1: " << value << std::endl;
    }, elem1);
    
    std::visit([](const auto& value) {
        std::cout << "Element 2: " << value << std::endl;
    }, elem2);
    
    std::cout << "\nTesting element modification..." << std::endl;
    vec[0] = 999;
    vec[1] = std::string("World");
    
    std::visit([](const auto& value) {
        std::cout << "Modified Element 0: " << value << std::endl;
    }, vec[0]);
    
    std::visit([](const auto& value) {
        std::cout << "Modified Element 1: " << value << std::endl;
    }, vec[1]);

    std::visit([](const auto& value) {
        std::cout << "Modified Element 2: " << value << std::endl;
    }, vec[2]);
    
    std::cout << "\nTesting pop..." << std::endl;
    std::cout << "Size before pop: " << vec.size() << std::endl;
    
    vec.pop();
    std::cout << "Size after pop: " << vec.size() << std::endl;
    
    std::cout << "Remaining elements:" << std::endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        std::visit([i](const auto& value) {
            std::cout << "Element " << i << ": " << value << std::endl;
        }, vec[i]);
    }
    
    std::cout << "\nTesting clear..." << std::endl;
    vec.clear();
    std::cout << "Size after clear: " << vec.size() << std::endl;
    std::cout << "Is empty: " << (vec.empty() ? "Yes" : "No") << std::endl;
    
    return 0;
}