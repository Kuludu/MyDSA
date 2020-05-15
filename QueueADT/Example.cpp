#include <iostream>
#include "MyQueue.hpp"
using std::cout;
using std::endl;
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

    delete q;
    delete bq;

    return 0;
}