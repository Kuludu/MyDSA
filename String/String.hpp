#ifndef MyString_H_
#define MyString_H_

#ifndef _GLIBCXX_OSTREAM
#include <ostream>
#endif

namespace MyStringNamespace {
    class MyString {
    public:
        MyString(const unsigned long long);
        ~MyString();
        bool insert(char);
        friend std::ostream &operator<<(std::ostream &, const MyString);
    private:
        char *root;
        unsigned long long size;
        unsigned long long pointer;
    };

    MyString::MyString(const unsigned long long size) {
        this->size = size;
        this->pointer = 0;
        root = new char[size];
    }

    MyString::~MyString() {
        delete[] this->root;
        this->size = 0;
    }

    bool MyString::insert(char c) {
        if (this->pointer < this->size) {
            root[this->pointer] = c;
            ++this->pointer;

            return true;
        }
        
        return false;
    }

    std::ostream &operator<<(std::ostream &output, const MyString str) {
        unsigned long long p = 0;
        while (p < str.pointer) {
            output << str.root[p++];
        }

        return output;
    }
}

#endif