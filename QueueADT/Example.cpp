#include <iostream>
#include <typeinfo>
#include "MyQueue.hpp"
using std::cout;
using std::endl;
using std::move;
using namespace MyQueueNamespace;

int main() {
    cout << "An example of MyQueue and MyBetterQueue class." << endl;
    
    MyQueue<int> *q = new MyQueue<int>;
    MyBetterQueue<int> *bq = new MyBetterQueue<int>;
    cout << "The address of MyQueue is " << q << endl;
    cout << "The address of MyBetterQueue is " << bq << endl;

    q->push(1);
    bq->push(2);

    cout << "The back of q is " << q->back() << endl;
    cout << "The front of bq is " << bq->front() << endl;

    cout << "MyBetterQueue supports stream insertion." << endl;

    *bq << 1 << 2 << 3;

    bq->pop();

    cout << "The size of bq is " << bq->size() << endl;

    if ( !bq->isempty() )
        cout << "bq is not empty." << endl;

    bq->pop();
    bq->pop();
    bq->pop();
    bq->pop();

    delete q;
    delete bq;

    cout << "Example of move semantics." << endl;
    MyBetterQueue<int> a;
    a << 1 << 2 << 3;
    MyBetterQueue<int> b;
    b << 4 << 5 << 6;
    cout << typeid(a + b).name() << endl;
    MyBetterQueue<int> c = move(a + b);
    while ( !c.isempty() ) {
        cout << c.front() << ' ';
        c.pop();
    }
    cout << endl;

    return 0;
}