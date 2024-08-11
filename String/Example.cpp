#include "String.hpp"
#include "trie.hpp"
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

    Trie::Trie *trie = new Trie::Trie();
    trie->insert("hello");
    cout << trie->search("hello") << endl;
    cout << trie->startsWith("hel") << endl;
    cout << trie->startsWith("world") << endl;

    return 0;
}