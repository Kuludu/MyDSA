#include <iostream>
#include "shared_pointer.hpp"

int main() {
    SharedPointer<char> s_ptr1(new char('A'));

    std::cout << "s_ptr1: " << *s_ptr1 << std::endl;
    std::cout << "s_ptr1 use count: " << s_ptr1.use_count() << std::endl;
    {
        SharedPointer<char> s_ptr2 = s_ptr1;
        std::cout << "s_ptr1 use count: " << s_ptr1.use_count() << std::endl;
    }
    std::cout << "s_ptr1 use count: " << s_ptr1.use_count() << std::endl;

    return 0;
}