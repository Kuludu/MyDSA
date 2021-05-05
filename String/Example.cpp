#include "String.hpp"
#include <iostream>
using std::cout;
using std::endl;
using namespace MyStringNamespace;

int main() {
    cout << "An example of MyString class." << endl;

    MyString *str = new MyString(10);
    str->insert('a');
    str->insert('b');
    cout << *str << endl;

    return 0;
}