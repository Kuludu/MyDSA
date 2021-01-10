#include <iostream>
#include "MyStack.h"
#include "MyStack.cpp"
using std::cout;
using std::endl;
using namespace MyStackNamespace;

int main()  {
    cout << "An example of MyStack class." << endl;

    MyStack<int> *s = new MyStack<int>;
    cout << "The address of s is " << s << endl;
    s->push(1);
    s->push(2);
    cout << "The size of s is " << s->size() << endl;
    s->pop();
    cout << "After the pop operation that has changed to " << s->size() << endl;
    cout << "Top element is " << s->top() << endl;
    s->pop();
    if ( !s->pop() )
        cout << "Oops, out of range." << endl;
    s->push(123);
    delete s;

    return 0;
}